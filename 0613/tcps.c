#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char* argv[]){

	int serv_sock, clnt_sock;
	char sendmsg[1024] = "Test";
	char recvmsg[1024];

	char ip[] = "127.0.0.1";
	int port = 10000;

	struct sockaddr_in st_serv_addr;
	struct sockaddr_in st_clnt_addr;

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1) {
		perror("socket");
		exit(1);
	}

	memset(&st_serv_addr, 0, sizeof(st_serv_addr));
	st_serv_addr.sin_family = AF_INET;
	st_serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	st_serv_addr.sin_port = htons(port);

	int bindret = bind(serv_sock, (struct sockaddr*)&st_serv_addr, sizeof(st_serv_addr));
	if(bindret == -1) {
		perror("bind");
		exit(1);
	}

	int listenret = listen(serv_sock, 10);
	if(listenret == -1) {
		perror("listen");
		exit(1);
	}


	int clnt_addr_size = sizeof(st_clnt_addr);
	int acceptret = accept(serv_sock, (struct sockaddr*)&st_clnt_addr, &clnt_addr_size);
	
	if(acceptret == -1) {
		perror("accept");
		exit(1);
	}


	write(clnt_sock, sendmsg, sizeof(sendmsg));
	int readstrlen = read(clnt_sock, recvmsg, sizeof(recvmsg)-1);

	close(clnt_sock);
	close(serv_sock);

	return 0;
}

