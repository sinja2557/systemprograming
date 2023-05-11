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
	if(execlp("mv", "mv", argv[1], argv[2], (char*)NULL) == -1){
		perror("execlp");
		exit(1);
	}
	printf("File moved.");

	return 0;
}

