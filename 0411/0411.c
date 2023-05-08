#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>

int main(int argc, char* argv[]){
	int pid;
	pid = fork();
	if (pid == 0)
		printf("Child : I am %d. My parent is %d\n", getpid(), getppid());
	else
		printf("Parent : I am %d, My child is %d\n", getpid(), pid);
	
	sleep(1);

	return 0;
}

