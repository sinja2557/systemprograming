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
#include <stdbool.h>

int cook_status = 0;
bool cooking = false;

void sigINT(int signo){

}


void sigUSR(int signo){
	if(!cooking){
		cook_status = 30;
	}
}

void sigALRM(int signo){
	printf("Cooking Completed\n");
	cook_status = 0;
	cooking = false;
}

int main(int argc, char* argv[]){

	int status;
	pid_t pid;

	signal(SIGUSR1, sigUSR);
	signal(SIGINT, sigINT);
	signal(SIGALRM, sigALRM);

	if((pid = fork()) == 0){
		while(1) {
			printf("Waiting..,\n");
			for(cook_status;cook_status < 30; cook_status++) {
				sleep(1);
			}
			printf("Cooking...\n");
			cooking = true;
			for(int i = 10; i > 0; i--){
				printf("Remaining time : %d\n", i);
				sleep(1);
			}
			raise(SIGALRM);
		}
	}
	else if (pid < 0) {
		perror("fork");
		exit(1);
	}
	else {

		wait(&status);

	}



	return 0;
}

