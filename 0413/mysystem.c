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

void mysystem(char* str){
	if(execlp("bash", "sh", "-c", str, (char*)NULL) == -1){
		perror("execlp");
		exit(1);
	}
}

int main(int argc, char* argv[]){

	pid_t pid;
	int status;
	pid = fork();

	if(pid < 0){	

		perror("fork");
		exit(1);

	} 
	else if (pid == 0) {
		
		printf("--> Child Process\n");

		printf("\ncommand(ls -al)\n");
		mysystem("ls -al");

		exit(0);	
	} 
	else {

		wait(&status);
		pid = fork();

		if (pid < 0) {
			perror("fork");
			exit(1);
		}
		else if (pid == 0) {

			printf("\ncommand(who)\n");
			mysystem("who");
		
			exit(0);
		}
		else {
			wait(&status);
			pid = fork();

			if(pid < 0){
				perror("fork");
				exit(1);
			}
			else if (pid == 0) {
				printf("\ncommand(date)\n");
				mysystem("date");
			}
			else {
				wait(&status);
				printf("\n--> Parent process - My PID : %d, My Child PID : %d\n", (int)getpid(), pid);	
			}

		}
	}
	return 0;
}
