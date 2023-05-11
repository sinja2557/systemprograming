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
	pid = fork();
	int status;


	if (pid == 0) {
		if(execlp("bash", "sh", "-c", "./mymv", argv[1], argv[2], (char*)NULL) == -1){
			perror("execlp");
			exit(1);
		}
	}
	else if (pid < 0) {
		perror("fork");
		exit(1);
	}
	else {
		wait(&status);
		if(execlp("bash", "sh", "-c", "./myfile", argv[2], argv[1], (char*)NULL) == -1){
				perror("execlp");
				exit(1);
	}
	
	return 0;
}

