#include "rsocket.h"


int counter = 0; 
int transmission_count = 0;
int message_count = 0;
Recv_buffer *recv_buffer;
Received_message_id_table *received_message_id_table;
Unacknowledged_message_table *unacknowledged_message_table;
pthread_t X;
pthread_mutex_t lock;

int dropMessage(float p)
{
	
	float x = (float)rand() / RAND_MAX;
	return(x < p);
}

void HandleAppMsgRecv(int sockfd,char *buf,int len,struct sockaddr_in cliaddr,socklen_t clilen)
{
	int msgid = 0;
	int i;
	for(i = 1;i<5;i++)
	{
		msgid *= 10;
		msgid += buf[i]-'0';
	}



	if(received_message_id_table -> table[msgid])
	{

		
	}
	else
	{
		buf[len] = '\0';
		pthread_mutex_lock(&lock);
		strcpy(recv_buffer ->messages[recv_buffer -> rear],(char *)(buf + 5));
		recv_buffer ->siz[recv_buffer -> rear] = len;
		recv_buffer -> addr[recv_buffer -> rear] = cliaddr;
		recv_buffer -> addr_len[recv_buffer -> rear] = clilen;
		recv_buffer -> rear = (1 + recv_buffer->rear) % 100;
		pthread_mutex_unlock(&lock);
	}
	char ack_mess[10];
	ack_mess[0] = '1';
    i = 4;
	
	received_message_id_table -> table[msgid] = 1;
	received_message_id_table -> num_messages++;
	while(msgid > 0)
	{
		ack_mess[i--] = '0' + (msgid % 10); 
		msgid /= 10;
	}
	while(i > 0)
	{
		ack_mess[i--] = '0';
	}
	


	sendto(sockfd,ack_mess,5,0,(struct sockaddr *)&cliaddr,clilen);
}

void HandleACKMsgRecv(int sockfd,char *buf,int len,struct sockaddr_in cliaddr,socklen_t clilen)
{

	int msgid = 0;
	int i;
	for( i = 1;i<5;i++)
	{
	    msgid *= 10;
		msgid += buf[i]-'0';
	}
	
	pthread_mutex_lock(&lock);
	unacknowledged_message_table->isvalid[msgid] = 0;
	unacknowledged_message_table -> num_messages --;
	pthread_mutex_unlock(&lock);

}

void HandleRetransmit(int sockfd)
{
	
	int i;
	for( i = 0;i < 100 ;i++)
	{
		if(unacknowledged_message_table->isvalid[i])
		{
			
			struct timespec tv;
			clock_gettime(CLOCK_REALTIME,&tv);
			long int curtime = tv.tv_sec * 1000000 + tv.tv_nsec/1000;
			long int sendtime = unacknowledged_message_table->tim[i].tv_sec * 1000000 + unacknowledged_message_table ->tim[i].tv_nsec/1000;

		
		

			if(curtime - sendtime > T * 1000000)
			{
				
				
				char new_buf[100],buf[100];
				strcpy(buf,unacknowledged_message_table -> message_add[i].message);
				
				struct sockaddr_in cliaddr;
				socklen_t clilen = sizeof(cliaddr);
				cliaddr.sin_family = AF_INET;
				cliaddr.sin_addr = unacknowledged_message_table -> message_add[i].ip;
				cliaddr.sin_port = unacknowledged_message_table ->message_add[i].port;
				
				
				int ind = 4;
				int msg_id  = i;
				while(msg_id > 0)
				{
					new_buf[ind--] = '0' + (msg_id % 10); 
					msg_id /= 10;
				}
				while(ind > 0)
				{
					new_buf[ind--] = '0';
				}
				new_buf[0] = '0';
				strcpy(new_buf + 5, (char *)buf);

			
				struct timespec tv2;
				clock_gettime(CLOCK_REALTIME,&tv2);
				unacknowledged_message_table ->tim[i] = tv2;


			
				transmission_count++;
				sendto(sockfd,new_buf,strlen(new_buf),0,(struct sockaddr *)&cliaddr,clilen);


			}

		}
	}

}

void HandleReceive(int sockfd,char *buf,int len,struct sockaddr_in cliaddr,int clilen)
{

	if(buf[0] == '0')
	{
		HandleAppMsgRecv(sockfd,buf,len,cliaddr,clilen);
	}
	else
	{
		HandleACKMsgRecv(sockfd,buf,len,cliaddr,clilen);
	}

}

void* run(void *arg)
{
	struct timeval tval;
	tval.tv_sec = T;
	tval.tv_usec = 0;
	fd_set readfs;
	int sockfd = *((int *) arg);
	while(1)
	{
		
		
		FD_ZERO(&readfs);
		FD_SET(sockfd,&readfs);
		int nfds = sockfd + 1;
		int retval = select(nfds,&readfs,NULL,NULL,&tval);
		if(retval < 0)
		{
			perror("select failed");
		}
		else
		{
			if(retval == 0)
			{
			
				HandleRetransmit(sockfd);
				tval.tv_sec = T;
				tval.tv_usec = 0;
			}
			else
			{
				struct sockaddr_in cliaddr;
				socklen_t clilen = sizeof(cliaddr);
				char buf[100];
				int len = recvfrom(sockfd,buf,100,0,(struct sockaddr *)&cliaddr,&clilen);
				int drop = dropMessage(prob);
				
				
				if(drop)
				{ 
					continue;
				}
				HandleReceive(sockfd,buf,len,cliaddr,clilen);

			}
		}

	}

}

int r_socket(int domain,int type,int protocol)
{
	srand(time(NULL));
	if(type != SOCK_MRP)
	{
		return -1;
	}
	int sockfd = socket(domain,SOCK_DGRAM,protocol);
	if(sockfd < 0) return -1;
	int optval = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEPORT,&optval,sizeof(optval));
	recv_buffer = (Recv_buffer *) malloc(sizeof(Recv_buffer));
	received_message_id_table = (Received_message_id_table *) malloc(sizeof(Received_message_id_table));
	unacknowledged_message_table = (Unacknowledged_message_table *) malloc(sizeof(Unacknowledged_message_table));
	
	recv_buffer -> front = recv_buffer -> rear = 0;
	received_message_id_table -> num_messages = 0;
	unacknowledged_message_table -> num_messages = 0;
	counter = 0;
	transmission_count = 0;
	int i;
	for( i = 0;i<100;i++)
	{
		received_message_id_table -> table[i] = 0;
		unacknowledged_message_table->isvalid[i] = 0;
	}
	pthread_mutex_init(&lock,NULL);
	int *sockfd_ptr = (int *)malloc(sizeof(int));
	*sockfd_ptr = sockfd;
	pthread_create(&X,NULL,run,sockfd_ptr);


	return sockfd;
}
int r_close(int sockfd)
{
	
	while(unacknowledged_message_table ->num_messages)
	{
		usleep(1000);
	}
	printf("Average transmissions %f\n",(float)transmission_count/message_count);
	
	pthread_cancel(X);
	pthread_mutex_destroy(&lock);
	close(sockfd);
	free(unacknowledged_message_table);
	free(recv_buffer);
	free(received_message_id_table);
	
}
int r_bind(int sockfd,const struct sockaddr* addr,socklen_t addrlen)
{
	if(bind(sockfd,addr,addrlen) < 0)
	{
		return -1;
	}
	return 0;
}
ssize_t r_sendto(int sockfd,const void *buf,size_t len,int flags,const struct sockaddr* dest_addr,socklen_t addrlen)
{

	int msg_id = counter ++;
	char *buff;
	buff = (char *)buf;
	char new_buf[110],copy_buf[110];
	int i = 4;
	int temp = msg_id;
	while(temp > 0)
	{
		new_buf[i--] = '0' + (temp % 10); 
		temp /= 10;
	}

	while(i > 0)
	{
		new_buf[i--] = '0';
	}
	new_buf[0] = '0';
	

	
	for( i = 0;i < len;i++)
	{
		new_buf[i+5] = buff[i];
		copy_buf[i] = buff[i]; 
	}
	copy_buf[len] = '\0';
	new_buf[len + 5] = '\0';
	Message_add message_with_header;
	message_with_header.id = msg_id;
	strcpy(message_with_header.message,copy_buf);
	message_with_header.siz = len;
	struct sockaddr_in *cliaddr_in = (struct sockaddr_in *)dest_addr;
	message_with_header.ip = cliaddr_in-> sin_addr;
	
	
	message_with_header.port = ((struct sockaddr_in *)dest_addr) ->sin_port;
	
	pthread_mutex_lock(&lock);
	int unack_no = unacknowledged_message_table -> num_messages;
	unacknowledged_message_table -> message_add[msg_id] = message_with_header;
	
	unacknowledged_message_table -> num_messages++;
	
	unacknowledged_message_table -> isvalid[msg_id] = 1;
	
	
	struct timespec tv;
	clock_gettime(CLOCK_REALTIME,&tv);
	unacknowledged_message_table ->tim[msg_id] = tv;
	pthread_mutex_unlock(&lock);
	
	
	
	sendto(sockfd,new_buf,strlen(new_buf),flags,dest_addr,addrlen);
	message_count++;
	transmission_count ++;


}
ssize_t r_recvfrom(int sockfd,void *buf,ssize_t len,int flags,struct sockaddr* src_addr,socklen_t *addrlen)
{
	while(1)
	{
	  pthread_mutex_lock(&lock);
	  if(recv_buffer -> front != recv_buffer -> rear) 
	  {
	  	pthread_mutex_unlock(&lock);
	  	 break;
	  }
	  pthread_mutex_unlock(&lock);

	  usleep(1000);
	}
	char temp_buf[100];
	pthread_mutex_lock(&lock);

	strcpy(temp_buf,recv_buffer -> messages[recv_buffer -> front]);
	buf = (char *)buf;
	int msg_size = recv_buffer -> siz[recv_buffer -> front];
	int min_len = msg_size < len ? msg_size : len;
	int i;
	for(i = 0;i <min_len;i++)
	{
		((char *)buf)[i] = temp_buf[i];
	}
	
	*src_addr =*((struct sockaddr *) &(recv_buffer->addr[recv_buffer -> front]));
	*addrlen = recv_buffer -> addr_len[recv_buffer -> front];
	recv_buffer->front = (recv_buffer->front + 1) % 100;

	pthread_mutex_unlock(&lock);

	return min_len; 


}