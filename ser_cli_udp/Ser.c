#include"utili.h"


int main()
{
	int sockSer = socket(AF_INET,SOCK_DGRAM,0);
	if(sockSer == -1)
	{
		perror("socket.");
		exit(1);
	}

	struct sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port =  htons(8080);
	addrSer.sin_addr.s_addr = inet_addr("127.0.0.1");

	socklen_t addrlen = sizeof(struct sockaddr);
	int ret = bind(sockSer, (struct sockaddr*)&addrSer, addrlen);
	if(ret == -1)
	{
		perror("bind.");
		exit(1);
	}

	char sendbuf[256];
	char recvbuf[256];
		
	struct sockaddr_in addrCli;
	while(1)
	{
		recvfrom(sockSer, recvbuf, 128, 0, (struct sockaddr*)&addrCli, &addrlen);
		printf("From Client message:> %s\n",recvbuf);
		sendto(sockSer, recvbuf, strlen(recvbuf)+1,0, (struct sockaddr*)&addrCli, addrlen);
	}
	close(sockSer);
	return 0;
}
