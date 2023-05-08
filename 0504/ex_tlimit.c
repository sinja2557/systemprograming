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

void SigAlrm(int signo){
	printf("SIGALRM : %d\n", signo);
}

void SigInt(int signo){
	printf("SIGINT : %d\n", signo);
}

void SigChild();

unsigned int alarmHandler(unsigned int nsecs, int child_pid){
	if(signal(SIGALRM, SigAlrm) == SIG_ERR)
		return(nsecs);

	alarm(nsecs);
	pause();

	kill(child_pid, SIGINT);
	
	return(alarm(0));
}

	
void main(int argc, char* argv[]){

	pid_t pid;
	int status;

	if (argv[1] == NULL || argv[2] == NULL) {
		printf("plz input parameter.\n");
		exit(0);
	}

	int time_limit = atoi(argv[1]);

	printf("Parent : %d\n", getpid());

	signal(SIGALRM, SigAlrm);
	signal(SIGINT, SigInt);
	signal(SIGCHLD, SigChild);

	pid = fork();


	if(pid < 0) {
		perror("fork");
		exit(1);
	} 
	else if (pid == 0) {

		printf("Child : %d\n", getpid());
		if(execlp(argv[2], (char*)NULL) == -1) {
			perror("execvp");
		}

	}
	else {
		alarmHandler(time_limit, pid);
	}

	return;
}

void SigChild(){
	int childPid, childStatus;
	childPid = wait(&childStatus);
	printf("Child %d terminated.\n", childPid);
	exit(0);

}
