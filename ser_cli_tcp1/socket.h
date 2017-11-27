#ifndef _SOCKET_H
#define _SOCKET_H

#include"utili.h"

int start_up(const char*ip, short port, int mode)
{
	int sockfd;
	if(mode == TCP)
	  sockfd = socket(AF_INET, SOCK_STREAM, 0);
	else
	  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	if(sockfd == -1)
	{
		perror("socket.");
		return -1;
	}
	
	struct sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(port);
	addrSer.sin_addr.s_addr = inet_addr(ip);

	int yes =  1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) ;

	socklen_t addrlen = sizeof(struct sockaddr);
	int ret = bind(sockfd, (struct sockaddr*)&addrSer, addrlen);
	if(ret == -1)
	{
		perror("bind.");
		return -1;
	}
	

	if(mode == TCP)
	{
		ret = listen(sockfd, LISTEN_QUEUE_SIZE);
		if(ret == -1)
		{
			perror("listen.");
			return -1;
		}
	}

	return sockfd;

}



#endif
