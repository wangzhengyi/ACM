#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1000
#define SERV_PORT 9931

void doprocessing(int sock, struct sockaddr_in cliaddr)
{
	int n;

	char str[INET_ADDRSTRLEN];
	char *buf = (char *)malloc(MAXLINE);

	memset(buf, '\0', MAXLINE);
	while (1) {
		n = read(sock, buf, MAXLINE);

		if (n < 0) {
			perror("Error reading from socket!");
			return;
		} else {
			printf("Connect from %s:%d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));
			write(sock, "I got your message!", 20);
		}
	}

	free(buf);
}


int main(void)
{
	struct sockaddr_in servaddr, cliaddr;

	int listenfd, connfd, pid;
	socklen_t cliaddr_len = sizeof(cliaddr);


	// first call to socket() function
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		perror("Error opening socket!");
		exit(-1);
	}	

	// initialize socket structure
	memset(&servaddr, 0, sizeof(struct sockaddr_in));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("222.31.79.131");
	servaddr.sin_port = htons(SERV_PORT);	

	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	// start listening for the clients
	listen(listenfd, 2000);

	printf("王正一的server服务器开始等待客户端连接 ...\n");

	while (1) {
		// 三次握手完成后，服务器调用accept()接受客户端连接
		// accept()参数：
		// sockfd = listenfd, 服务器端监听的套接字描述符
		// cliaddr = &cliaddr, 指向sockaddr结构体指针，客户端的地址信息
		// addrlen = &cliaddr_len,确定客户端地址结构体的大小
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);

		pid = fork();

		if (pid == -1) {
			perror("call to fork");
			exit(-1);
		} else if (pid == 0) {
			close(listenfd);
			doprocessing(connfd, cliaddr);
			exit(0);
		} else {
			close(connfd);
		}
	}

	return 0;
}
