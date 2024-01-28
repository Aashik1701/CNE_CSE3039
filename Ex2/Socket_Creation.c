#include <stdio.h> 

#include <stdlib.h>

#include <unistd.h>

#include <sys/socket.h>

#include<netinet/in.h>

#include<arpa/inet.h>

int main()

{

  int sockfd1,sockfd2; /* sokcet file descriptors */

  sockfd1=socket(AF_INET,SOCK_STREAM,0); /* socket system call */

  sockfd2=socket(PF_INET,SOCK_DGRAM,0);

  if(sockfd1==-1) /* error checking */
  {

    printf("Socket1 not Created\n");

  }

  else

  {

    printf("Socket1 Created and \t Socket1 File Descriptor value is %d \n",sockfd1);

    if(sockfd2==-1)

    {

      printf("socket2 creation error");

    }

    else

    {

      printf("Socket2 created and \t socket2 descriptor value is %d\n",sockfd2);

    }

  }
}

