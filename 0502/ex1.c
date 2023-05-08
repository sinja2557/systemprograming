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

void SigIntHandler(int signo) {

	printf("\nSignal Handler Signal Number: %d\n", signo);
	psignal(signo, "Received Signal");
}

int main(int argc, char* argv[]){

	signal(SIGINT, SigIntHandler);

	printf("Wait 1st Ctrl+C... : SIGINT\n");
	pause();
	printf("After 1st Signal Handler\n");
	printf("Wait 2nd Ctrl+C.... : SIGINT\n");
	pause();
	printf("After 2nd Signal Handler\n");
	

	return 0;
}

