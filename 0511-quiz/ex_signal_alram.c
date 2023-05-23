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
#define NUM_CHILD 5

void sigUSR(int signo){
	printf("Child[%d] : Received signal.\n\n", getpid());
}


int main(int argc, char* argv[]){

	int i;
	pid_t child[NUM_CHILD];

	signal(SIGUSR1, sigUSR);

	for(i = 0;i<NUM_CHILD;i++){
		child[i] = fork();
		if(child[i] == 0){
			break;
		}
	}

	pid_t pid_prev;
	if(i==0) 
		pid_prev = getppid();
	else
		pid_prev = child[i-1];

	while(i-->0) {
		sleep(1);
	}


	printf("%d: sending signal to process... %d\n", getpid(), pid_prev);
	kill(pid_prev, SIGUSR1);


	sleep(1);

	return 0;
}

