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

	int pd1, pd2, n1, n2;
	char inmsg[80];

	printf("Server =====\n");

	mkfifo("./HAN-FIFO2", 0666);

	if ((pd1 = open("./HAN-FIFO", O_WRONLY)) == -1) {
		perror("open");
		exit(1);
	}

	if ((pd2 = open("./HAN-FIFO2", O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	char send_msg[80];

	while (send_msg == "q")  {
		scanf("Input the msg : %s", send_msg);
		n1 = write(pd1, send_msg, sizeof(send_msg));

		if(n1 == -1) {
			perror("write");
			exit(1);
		}

		if ((n2 = read(pd2, inmsg, 80)) > 0) {
			write(1, inmsg, n2);
		}

		if (n2 == -1) {
			perror("read");
			exit(1);
		}
	}

	close(pd1);
	close(pd2);

	return 0;
}

