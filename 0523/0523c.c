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

	if(mkfifo("./HAN-FIFO1", 0666) == -1) {
		perror("mkfifo");
		exit(1);
	}


	if ((pd1 = open("./HAN-FIFO2", O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	if ((pd2 = open("./HAN-FIFO1", O_WRONLY)) == -1) {
		perror("open");
		exit(1);
	}

	printf("Client =====\n");
	char send_msg[80];

	while (send_msg != "q") {

		if ((n1=read(pd1, inmsg, 80)) > 0) {
			write(1, inmsg, n1);
		}


		if (n1 == -1) {
			perror("read");
			exit(1);
		}


		scanf("Input the msg : %s", send_msg);
		
		n2 = write(pd2, send_msg, strlen(send_msg)+1);
		
		if(n2 == -1){
			perror("write");
			exit(1);
		}

		write(1, "\n", 1);


	}
	
	close(pd1);
	close(pd2);

	return 0;
}

