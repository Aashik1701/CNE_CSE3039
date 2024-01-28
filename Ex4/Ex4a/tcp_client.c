//TCP CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 4771

int main(int argc,char *argv[]) {
        int sockfd;
        struct sockaddr_in serv;
        char buffer[100];
        sockfd = socket(AF_INET,SOCK_STREAM,0);
        
        printf("Client Socket Created Successfully.\n");
        memset(&serv,0,sizeof(serv));
        serv.sin_family = AF_INET;
        serv.sin_port = htons(PORT);
        serv.sin_addr.s_addr = INADDR_ANY;
        
        if(connect(sockfd,(struct sockaddr*) &serv,sizeof(serv)) < 0) {
                printf("Error in Connect");
                exit(0);
        }
        printf("Client Socket with Server Successfully.\n");
        
        do
        {   
                strcpy(buffer," ");
                printf("Client. :");
                fgets(buffer,100,stdin);
                write(sockfd,buffer,100);
                
                if(strcmp(buffer,"bye\n") == 0) {
                        printf("Client:%s",buffer);
                        goto stop;
                }
                strcpy(buffer," ");
                read(sockfd,buffer,sizeof(buffer));
                printf("From Server : %s\n",buffer);
          }
          while(strcmp(buffer,"bye\n") != 0);
          stop:
          exit(0);
          close(sockfd);
          
          return 0 ;
}
