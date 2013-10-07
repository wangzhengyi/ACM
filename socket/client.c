#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define SERV_PORT 9931

int main(int argc, char *argv[])
{
	// 需要连接的服务器端socket套接字
	// 客户端的socket套接字由系统自动分配
	struct sockaddr_in servaddr;
	char *buf = (char *)malloc(MAXLINE);
	int servfd, n;

	servfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("222.31.79.131");	// 传媒ip
	servaddr.sin_port = htons(SERV_PORT);

	// 客户端调用connect连接服务器端指定socket套接字
	connect(servfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	while (fgets(buf, MAXLINE, stdin) != NULL) {
		write(servfd, buf, strlen(buf));

		n = read(servfd, buf, MAXLINE);

		if (n == 0) {
			perror("Tht other side has been closed.");
			exit(-1);
		} else {
			printf("从服务器返回的信息为:%s\n", buf);
		}

	}
	close(servfd);

	return 0;
}
