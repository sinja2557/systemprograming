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

int main(void){

	int pd, n;
	char msg[] = "Hello, FIFO";

	printf("Server =====\n");

	if (mkfifo("./HAN-FIFO", 0666) == -1) {
		perror("mkfifo");
		exit(1);
	}

	if ((pd = open("./HAN-FIFO", O_WRONLY)) == -1) {
		perror("open");
		exit(1);
	}

	printf("To Client : %s\n", msg);

	n = write(pd, msg, strlen(msg)+1);
	if (n == -1) {
		perror("write");
		exit(1);
	}
	close(pd);

	return 0;
}

