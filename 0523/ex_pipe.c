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


int main(int argc, char* argv[]){

	int fd[2];
	pid_t pid;
	char buf[257];
	int len, status;

	if (pipe(fd) == -1){
		perror("pipe");
		exit(1);
	}

	switch(pid = fork()) {
		case -1:
			perror("fork");
			exit(1);
			break;
		
		case 0:
			close(fd[1]);
			write(1, "Child Process : ", 15);
			len = read(fd[0], buf, 256);
			write(1, buf, len);
			close(fd[0]);
			break;
		
		default:
			close(fd[0]);
			buf[0] = '\0';
			write(fd[1], "Test Message from Parents\n", 26);
			close(fd[1]);
			waitpid(pid, &status, 0);
			break;
	}
	

	return 0;
}

