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

	printf("--> Before exec function\n");

	if(execlp("ls", "ls", "-a", (char*)NULL) == -1){
		perror("execlp");
		exit(1);
	}

	printf("--> After exec function\n");

	return 0;
}

