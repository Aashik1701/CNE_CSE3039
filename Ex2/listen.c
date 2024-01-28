#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define PORT 3550
#define BACKLOG 12

int main() {
	int fd;
	struct sockaddr_in server;
	struct sockaddr_in client;

	int sin_size;
	int x;
	if((fd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		printf("socket() error\n");
		exit(-1);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server.sin_zero),8);

	if(bind(fd,(struct sockaddr*)&server,sizeof(struct sockaddr)) == -1)
	{
		printf("bind() error\n");
		exit(-1);

	}

	x = listen(fd,BACKLOG);
	if(x == -1)
	{
		printf("listen() error\n");
		exit(-1);
	}
	else
	{
		printf("Server is in listening mode\n");
	}
	close(fd);
}
