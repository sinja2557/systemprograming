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
	printf("Signal Handler Signal Number %d\n", signo);
	return;
}

unsigned int mysleep(unsigned int nsecs){
	if(signal(SIGALRM, SigAlrm) == SIG_ERR)
		return(nsecs);

	alarm(nsecs);
	pause();
	return(alarm(0));
}
	
void main(int argc, char* argv[]){

	printf("sleep 5 seconds...\n");
	mysleep(5);

}

