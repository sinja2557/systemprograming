#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>

void myexit1(){
	printf("first exit handler\n");
}

void myexit2(){
	printf("second exit handler\n");
}

int main(int argc, char* argv[]){
	
	if(atexit(myexit2) != 0){
		perror("atexit");
		exit(1);
	}

	if(atexit(myexit1) != 0){
		perror("atexit");
		exit(1);
	}
	
	printf("main is done\n");
	return 0;
}

