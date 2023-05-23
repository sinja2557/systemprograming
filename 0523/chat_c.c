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
	char inmsg[80], outmsg[80];

	mkfifo("./HAN-FIFO", 0666);

	while(1){
		pd = open("./HAN-FIFO", O_RDONLY);
		read(pd, inmsg, 80);

		printf("User1 : %s\n", inmsg);
		close(pd);

		pd = open("./HAN-FIFO", O_WRONLY);
		fgets(outmsg, 80, stdin);
		write(pd, outmsg, strlen(outmsg)+1);
		close(pd);
	}

	return 0;
}

