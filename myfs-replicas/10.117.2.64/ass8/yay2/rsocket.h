#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<sys/time.h>
#define T 2
#define SOCK_MRP 1000
#define prob 0.15
#define MAX 100
typedef struct 
{
	int front,rear;
	char messages[100][100];//is message i an ACK?
	int siz[100];
	struct sockaddr_in addr[100];
	socklen_t addr_len[100];

}Recv_buffer;

typedef struct 
{
	int num_messages;
	int table[100];
}Received_message_id_table;

typedef struct 
{
	int id;
	char message[100];
	int siz;
	struct in_addr  ip;
	unsigned short int port;
}Message_add;

typedef struct 
{
	int num_messages;
	Message_add message_add[100];
	int isvalid[100];
	struct timespec tim[100];


}Unacknowledged_message_table;

int r_socket(int domain,int type,int protocol);
int r_bind(int sockfd,const struct sockaddr* addr,socklen_t addrlen);
ssize_t r_sendto(int sockfd,const void *buf,size_t len,int flags,const struct sockaddr* dest_addr,socklen_t addrlen);
ssize_t r_recvfrom(int sockfd,void *buf,ssize_t len,int flags,struct sockaddr* src_addr,socklen_t *addrlen);
int r_close(int sockfd);
int dropMessage(float p);





