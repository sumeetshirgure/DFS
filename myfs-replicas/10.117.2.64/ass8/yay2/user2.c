
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include "rsocket.h"
  
int main() { 
    int sockfd; 
    struct sockaddr_in servaddr,cliaddr; 
  
    // Creating socket file descriptor 
    sockfd = r_socket(AF_INET, SOCK_MRP, 0);
    if ( sockfd < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(52007); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 

    if ( r_bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    // cliaddr.sin_family = AF_INET;
    // cliaddr.sin_port = htons(8181);
    // cliaddr.sin_addr.s_addr = INADDR_ANY;


    char buf[1];
    int i;
    for(i = 0;i < 100;i++)
    {
        socklen_t clilen = sizeof(cliaddr);
        r_recvfrom(sockfd,buf,1,0,(struct sockaddr *) &cliaddr,&clilen);
        printf("Received char %c\n",buf[0]);
    }
    

}