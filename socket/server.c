#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define SERV_PORT 9931

int main(void)
{
	struct sockaddr_in servaddr, cliaddr;	// 服务器和客户端的socket数据结构
	// typedef int socklen_t;
	// typedef int ssize_t;
	socklen_t cliaddr_len;
	int listenfd, connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	
	// 创建socket,返回整形socket标识
	// domain = AF_INT : 套接字指定IPV4网络协议集
	// type = SOCK_STREAM : 可靠的面向流服务器或套接字
	// protocol = 0, 选择缺省的传输协议
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	// 将结构体清0
	bzero(&servaddr, sizeof(struct sockaddr_in));
	// 为服务器套接字指定协议族
	servaddr.sin_family = AF_INET;
	// 为服务器套接字指定ip，INADDR_ANY = 0.0.0.0
	servaddr.sin_addr.s_addr = inet_addr("222.31.79.131");
	// 为服务器套接字指定port
	servaddr.sin_port = htons(SERV_PORT);	

	// 为一个套接字分配地址，使用socket()创建套接字后，
	// 只赋予其使用的协议，并未分配地址，bind()用来为listenfd
	// 分配地址,参数解释：
	// sockfd = listenfd, bind函数的套接字描述符
	// my_addr = &servaddr, 服务器端sockaddr结构的指针
	// addrlen = sizeof(servaddr), sockaddr结构的长度
	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	// socket监听，准备接受连接请求
	listen(listenfd, 20);

	printf("王正一的server服务器开始等待客户端连接 ...\n");

	while (1) {
		cliaddr_len = sizeof(cliaddr);
		// 三次握手完成后，服务器调用accept()接受客户端连接
		// accept()参数：
		// sockfd = listenfd, 服务器端监听的套接字描述符
		// cliaddr = &cliaddr, 指向sockaddr结构体指针，客户端
		// 的地址信息
		// addrlen = &cliaddr_len,确定客户端地址结构体的大小
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
		read(connfd, buf, MAXLINE);
		printf("从客户端%s的%d端口收到数据\n", 
				inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));

		strcat(buf, "从王正一机器返回的信息");

		write(connfd, buf, MAXLINE);
		close(connfd);
	}
}
