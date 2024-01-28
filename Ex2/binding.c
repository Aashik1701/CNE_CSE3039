#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORTNO 2000

int main(){
	int sockfd,i = PORTNO;
	struct sockaddr_in myaddr;
	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		printf("Socket1 Creation Error\n");
	}
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(PORTNO);
	myaddr.sin_addr.s_addr =  INADDR_ANY;
	memset(&(myaddr.sin_zero),'\0',8);
	
	if(bind(sockfd,(struct sockaddr*)&myaddr, sizeof(struct sockaddr)) == -1)
	{
		printf("Binding Error\n");
	}
	else{
	        printf("Socket is Binded at port %d\n",i);
		
	}
}
