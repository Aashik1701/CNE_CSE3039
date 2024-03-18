#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 4771

int main(){
    int sockfd;
    struct sockaddr_in serv;
    char data[100];
    char divisor[100];
    char crc[100];
    char codeWord[1024];

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    printf("Client Socket Created Successfully\n");
    memset(&serv,0,sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT);
    serv.sin_addr.s_addr = INADDR_ANY;

    if(connect(sockfd,(struct sockaddr*)&serv,sizeof(serv))<0){
        printf("Error in Connect");
        exit(0);
    }
    printf("Client Socket with Server Successfully\n");

    printf("Enter the data:");
    scanf("%s",data);
    int l = strlen(data);
    printf("Enter the divisor:");
    scanf("%s",divisor);
    int N = strlen(divisor);
    
    char msg[200];
    sprintf(msg,"%s\n%s",data,divisor);   //Formatting the string and storing in msg

    send(sockfd,msg,strlen(msg),0);
    printf("Data and Divisor sent to the server\n");
    printf("From Server:\n");
    read(sockfd,crc,sizeof(crc));
    
    //Construction of Code Word
    for(int i=0;i<l;i++){
          codeWord[i] = data[i];
    }
    for(int i=0;i<N-1;i++){
          codeWord[l+i] = crc[i];
    }
    codeWord[l+N-1] = '\0';   //Null - terminate the string
    printf("CodeWord = %s\n",codeWord);
    close(sockfd);

    return 0;
}
