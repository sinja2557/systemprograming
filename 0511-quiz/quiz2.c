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
bool parent_check = false;
int child_pid = 0;

void sigINT(int signo){
	printf("Parent : kill Child Process\n");
	kill(SIGKILL, child_pid);
}


void sigUSR(int signo){
	if(!cooking){
		cook_status = 30;
	}
}

void sigALRM(int signo){
	printf("Child : Cooking Completed\n");
	cook_status = 0;
	cooking = false;
}

void sigINTC(int signo){

}

int main(int argc, char* argv[]){

	int status;
	pid_t pid;
	child_pid = pid;

	signal(SIGUSR1, sigUSR);
	signal(SIGALRM, sigALRM);

	if((pid = fork()) == 0){
		signal(SIGINT, sigINTC);
		while(1) {
			if (parent_check) {
				parent_check = false;
				printf("Child : Order received\n");
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
	}
	else if (pid < 0) {
		perror("fork");
		exit(1);
	}
	else {

		while (true) {
			signal(SIGINT, sigINT);

			char* rp = "";
			int yn = 0;
			printf("Do you want to ordr? (y,n) ");
			scanf("%s", rp);
			if (rp == "y") {
				yn = 1;
			}

			switch(yn){
				case 1:
					parent_check = true;
					printf("Parent : Order transmitted\n");
					wait(&status);
					printf("Parent : Cooking Completed\n");
					break;
			}
		}

	}



	return 0;
}

