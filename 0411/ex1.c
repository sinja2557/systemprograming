#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>

int Var = 6;

int main(int argc, char* argv[]){
	int var;
	pid_t pid;
	var = 88;

	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (pid==0) {
		Var++;
		var++;
	} else {
		sleep(1);
	}

	printf("pid = %d, Var = %d, var = %d\n", (int)getpid(), Var, var);

	return 0;
}

