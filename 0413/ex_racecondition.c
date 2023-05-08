#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>

void CharAtaTime(char* str){
	char *ptr;
	int c, i;
	setbuf(stdout, NULL);
	for(ptr=str;c=*ptr;ptr++){
		for(i = 0;i<999999;i++);
		putc(c, stdout);
	}
}

int main(int argc, char* argv[]){

	pid_t pid;
	if ((pid = fork()) < 0){
		perror("fork");
		exit(1);
	} else if (pid == 0){
		CharAtaTime("output from child\n");
	} else {
	//	wait(NULL);
		CharAtaTime("output from parent\n");
	}

	return 0;
}

