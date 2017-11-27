#include"utili.h"
#include"socket.h"

int main(int argc, char *argv[])
{
	int sockSer = start_up(argv[1],atoi(argv[2]), TCP);
	struct sockaddr_in addrSer,addrCli;
	socklen_t addrlen = sizeof(struct sockaddr);
	int sockConn = accept(sockSer, (struct sockaddr*)&addrCli, &addrlen);
	if(sockConn == -1)
	{
		printf("Server Accept Client Connect failed.\n");
		exit(1);
	}
	else
	  printf("Server Accept Client Success.\n");
	
	char sendbuf[256];
	char recvbuf[256];

	while(1)
	{
		printf("Ser:> ");
		scanf("%s",&sendbuf);
		send(sockConn, sendbuf, strlen(sendbuf)+1, 0);
		recv(sockConn, recvbuf, 256, 0);
		printf("Cli:> %s\n",recvbuf);
	}
	close(sockSer);
	return 0;
}



