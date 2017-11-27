#include"utili.h"


int main(int argc, char *argv[])
{
	int sockSer = socket(AF_INET, SOCK_STREAM, 0);
	if(sockSer == -1)
	{
		perror("socket.");
		exit(1);
	}

	struct sockaddr_in addrSer, addrCli;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(atoi(argv[2]));
	addrSer.sin_addr.s_addr = inet_addr(argv[1]);

	int yes = 1;
	setsockopt(sockSer, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

	socklen_t addrlen =  sizeof(struct sockaddr);
	int ret = bind(sockSer, (struct sockaddr*)&addrSer, addrlen);
	if(ret == -1)
	{
		perror("bind.");
		exit(1);
	}

	ret = listen(sockSer,5);

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



