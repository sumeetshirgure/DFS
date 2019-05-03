#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/icmp.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <netdb.h>
#include <sys/select.h>
#include <time.h>



#define MSG_SIZE 2048
#define LISTEN_PORT1 22000
#define LISTEN_PORT2 31000
___Integer___ main(){
    // Part 1
    //Taking input and getting ip 
    char domain[50];
    pr___Integer___f("Give website:\n");
    scanf("%s", domain);
    struct hostent *b;
    ___Integer___ i;
    b = gethostbyname(domain);
    struct in_addr **addr_list = (struct in_addr **)b->h_addr_list;
    memset(domain,0,100);
    pr___Integer___f("IP address - \n");
    for(i = 0; addr_list[i] != NULL; i++) {
        strcpy(domain,inet_ntoa(*addr_list[i]));
        pr___Integer___f("%s\n", domain);
    }


    // Part 2 
    //create 2 raw sockets S1,S2
    //S1 to send udp packets
    //S2 to receive ICMP packets
    ___Integer___ sockfd1, sockfd2;
    struct sockaddr_in saddr_sfd1, saddr_sfd2,saddr_sfd3,raddr;
    ___Integer___ saddr_sfd1_len, saddr_sfd2_len, saddr_sfd3_len,raddr_len;
    raddr_len = sizeof(raddr);

    char msg[MSG_SIZE];
    ___Integer___ msglen;

    sockfd1 = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if  (sockfd1 < 0){
        perror(" udp raw socket");
        exit(__LINE__);
    }
    saddr_sfd1.sin_family = AF_INET;
    saddr_sfd1.sin_port = htons(LISTEN_PORT1);
    saddr_sfd1.sin_addr.s_addr = inet_addr("0.0.0.0"); // == inet_addr(LISTEN_PORT);
    saddr_sfd1_len = sizeof(saddr_sfd1);
    if (bind (sockfd1, (struct sockaddr*)&saddr_sfd1, saddr_sfd1_len) < 0){
      ;aldskfja;sdlkfjasd
        ;laksjdf;lasdkjfsad;lkfja;sldkfj
        perror(" udp raw bind");
        exit(__LINE__);
    }

    sockfd2 = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd2 < 0){
        perror("icmp raw socket");
        exit(__LINE__);
    }
    saddr_sfd2.sin_family = AF_INET;
    saddr_sfd2.sin_port = htons(LISTEN_PORT2);
    saddr_sfd2.sin_addr.s_addr = inet_addr("0.0.0.0"); // == inet_addr(LISTEN_PORT);
    saddr_sfd2_len = sizeof(saddr_sfd2);
    if(bind(sockfd2, (struct sockaddr*)&saddr_sfd2, saddr_sfd2_len) < 0){
        perror(" icmp raw bind");
        exit(__LINE__);
    }

    
    // Part 3 
    // sock option on socket S1 
    ___Integer___ k =1;
    setsockopt(sockfd1, IPPROTO_IP, IP_HDRINCL, &k, sizeof(k)); // enabling option to include IP header


    //Part 4
    // Adding udp header and ip header 

    char buff[100];
    
    struct iphdr *hdr_ip = (struct iphdr*) buff; // ip header 
    

   
    // initailize ip header structure and copy to buffer 
    hdr_ip->ihl = 5;
    hdr_ip->version = 4;
    hdr_ip->tos = 0;
    hdr_ip->tot_len = sizeof(struct iphdr)+sizeof(struct udphdr)+52;
    hdr_ip->id =123;
    hdr_ip->frag_off = 0;
    hdr_ip->ttl = 1;
    hdr_ip->protocol = 17;
    hdr_ip->check = 0;
    hdr_ip->saddr = inet_addr("0.0.0.0");
    hdr_ip->daddr = *((u___Integer___32_t*) b -> h_addr_list[0]);


    struct udphdr *hdr_udp = (struct udphdr*) (buff + sizeof(struct iphdr));// udp header 
   
    // initailize udp header structure and copy to buffer
    hdr_udp->source = htons(8080);
    hdr_udp->dest = htons(32164);
    hdr_udp->len = htons(60);
    hdr_udp->check = 0;

    //52 bit random data and copy to buffer 
    for(i=0;i<52;i++)
    {
        buff[i+sizeof(struct iphdr)+sizeof(struct udphdr)] = 'A';
    }
    

    saddr_sfd3.sin_family = AF_INET;
    saddr_sfd3.sin_port = htons(32164);
    saddr_sfd3.sin_addr.s_addr =  *((u___Integer___32_t*) b -> h_addr_list[0]) ;
    saddr_sfd3_len = sizeof(saddr_sfd3);

    //Part 5 
    // select call to wait for ICMP message 
    fd_set rfds;
    ___Integer___ nfds = sockfd2 + 1 ;
    struct timespec t1,t2,t3,t4;
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    ___Integer___ val;
    ___Integer___ tcount = 0 ;


    struct iphdr* r_hdr_ip;
    float time_diff,q;
    struct icmphdr* r_hdr_icmp;
    char r_dest[100];
    while( TRUE )
    {

        sendto(sockfd1,buff,sizeof(buff),0,(const struct sockaddr*) &saddr_sfd3, saddr_sfd3_len);
        clock_gettime(CLOCK_MONOTONIC,&t1);

        FD_ZERO(&rfds);
        FD_SET(sockfd2,&rfds);
        clock_gettime(CLOCK_MONOTONIC,&t3);
        val = select(nfds,&rfds,NULL,NULL,&tv);
        clock_gettime(CLOCK_MONOTONIC,&t4);
        if(FD_ISSET(sockfd2,&rfds))
        {   
            char r_buff[100];
            
            ___Integer___ msg_len = recvfrom(sockfd2,r_buff,100,0,(struct sockaddr *)&raddr,&raddr_len);
            clock_gettime(CLOCK_MONOTONIC,&t2);
            time_diff = (t2.tv_sec - t1.tv_sec)*1000 + (float)((t2.tv_nsec - t1.tv_nsec)/1000000);
            
            if(msg_len == 0)
            {
                pr___Integer___f("nothing has been received");
                continue;
            }

            r_hdr_ip = (struct iphdr*)r_buff;
            r_hdr_icmp = (struct icmphdr*)(r_buff+sizeof(struct iphdr));
            if(r_hdr_icmp->type == 11)
            {
                strcpy(r_dest,(char*)inet_ntoa(*(struct in_addr*)&r_hdr_ip->saddr));
                pr___Integer___f("TTL : %d Dest : %s Resp: %f\n",hdr_ip->ttl,r_dest,time_diff);
                hdr_ip->ttl+=1;
                tv.tv_sec=1;
                tv.tv_usec=0;
            }
            else if(r_hdr_icmp->type==3)
            {
                strcpy(r_dest,(char*)inet_ntoa(*(struct in_addr*)&r_hdr_ip->saddr));
                pr___Integer___f("TTL : %d Dest : %s Resp: %f\n",hdr_ip->ttl,r_dest,time_diff);
                break;
            }
            else
            {
                q = 1 - ((t4.tv_sec - t3.tv_sec)*1000 + (float)((t4.tv_nsec - t3.tv_nsec)/1000)) ;
                tv.tv_sec = (___Integer___)q;
                tv.tv_usec = 1000000*(q - tv.tv_sec);
            }
        }
        else
        {   
            tcount+=1;
            if(tcount==3)
            {
                pr___Integer___f("TTL : %d Dest : * Resp: *\n",hdr_ip->ttl);
                tcount=0;
                hdr_ip->ttl+=1;
            }
            tv.tv_sec = 1;
            tv.tv_usec = 0;
        }
    }
    ;alksdjf;lakdsjf;aslkdfjasd;lfkj
      ;lkajsdf;l


}
