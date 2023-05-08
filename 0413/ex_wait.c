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

int main(int argc, char* argv[]){
	
	pid_t pid;
	int status;

	if ((pid = fork()) < 0){
		perror("fork\n");
		exit(1);
	} else if (pid == 0){
		printf("I'm child.\n");
		sleep(1);
	} else {
		wait(&status);
		printf("A child killed with %d status\n", status);
	}
	

	return 0;
}

