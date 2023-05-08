#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Usage : %s filename\n", argv[0]);
		exit(1);
}
	
	umask(000);
	int fd = open(argv[1], O_CREAT, 0666);
	close(fd);

	return 0;
}

