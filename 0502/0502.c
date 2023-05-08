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

int i = 10;

void SigIntHandler(int signo){
	printf("Siganl Interrupt has been occureed.\n");
	i = 11;
}

void SigTermHandler(int signo) {
	printf("Signal Term has been occureed.\n");
	exit(0);
}

void SigUsrHandler(int signo){
	printf("Signal USR1 has been occureed.\n");
	i = 1;
	for(i;i <= 10;i++) {
		printf("Count : %d\n", i);
		sleep(1);
	}
}

int main(int argc, char* argv[]){


	signal(SIGINT, SigIntHandler);
	signal(SIGTERM, SigTermHandler);
	signal(SIGUSR1, SigUsrHandler);


	for(i; i >= 0; i--){
		printf("Count : %d\n", i);
		sleep(1);
	}

	return 0;
}

