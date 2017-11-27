#include"utili.h"

int main()
{
	int sockCli = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockCli == -1)
	{
		perror("socket.");
		exit(1);
	}

	struct sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(8080);
	addrSer.sin_addr.s_addr = inet_addr("127.0.0.1");
    
	char sendbuf[256];
	char recvbuf[256];

	socklen_t addrlen = sizeof(struct sockaddr);
	struct sockaddr_in addrCli;
	while(1)
	{
		printf("Cli:> ");
		scanf("%s",sendbuf);
		sendto(sockCli, sendbuf, strlen(sendbuf)+1,0,(struct sockaddr*)&addrSer, addrlen);
		recvfrom(sockCli, recvbuf, 128, 0 ,(struct sockaddr*)&addrSer, &addrlen);
		printf("From Self message:> %s\n",recvbuf);
	}
	close(sockCli);

	return 0;
}

