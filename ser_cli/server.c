#include"utili.h"


int main()
{
	int sockSer = socket(AF_INET,SOCK_STREAM, 0);
	if(sockSer == -1)
	{
		perror("error!\n");
		exit(1);
	}

	struct sockaddr_in addrSer, addrCli;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port =  htons(SERVER_PORT);//host to network short convert
	addrSer.sin_addr.s_addr = inet_addr("SERVER_IP");

	/*
	int yes = 1;
	setsockopt(sockSer, SO_REUSEADDR, &yes, sizeof(int));
*/
	socklen_t len = sizeof(struct sockaddr);
	int ret = bind(sockSer, (struct sockaddr*)&addrCli, len);
	if(!strcmp(sendbuf,"quit"))
	   51           break;
	 52         send(sockConn, sendbuf, strlen(sendbuf)+1, 0);
	  53         recv(sockConn, recvbuf, BUFFER_SIZE, 0);
	   54         printf("Cli:> %s\n",recvbuf);
	    55     }
 56     close(sockSer);
 57     return 0;
f(ret == -1)
	{
		perror("bind.\n");
		exit(1);
	}

	ret = listen(sockSer, LISTEN_QUEUE_SIZE);
	if(ret == -1)
	{
		perror("listen.\n");
		exit(1);
	}

	printf("Server wait Client Connect.....\n");

	int sockConn = accept(sockSer, (struct sockaddr*)&addrCli,&len);
	if(sockConn == -1)
	{
		perror("Server accept Client error!\n");
		exit(1);
	}
	else
	{
		printf("Server accept Client success!\n");
		printf("Client IP:> %s\n",inet_ntoa(addrCli.sin_addr));
		printf("Client Port:> %d\n",addrCli.sin_port);
	}
	char sendbuf[BUFFER_SIZE];
	char recvbuf[BUFFER_SIZE];
	while(1)
	{
		printf("Ser:> ");
		scanf("%s",sendbuf);
		if(!strcmp(sendbuf,"quit"))
		  break;
		send(sockConn, sendbuf, strlen(sendbuf)+1, 0);
		recv(sockConn, recvbuf, BUFFER_SIZE, 0);
		printf("Cli:> %s\n",recvbuf);
	}
	close(sockSer);
	return 0;
}
