#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>

void main(int argc, char *argv[]){
	int fd1;

	creat(argv[1], 0644); // argv[1] file create
	fd1 = open(argv[1], O_WRONLY | O_TRUNC, 0644); // open argv[1] , write + read | del + create 
	write(fd1, argv[2], strlen(argv[2])); // write in fd1 , argv[2] , length argv[2]

	close(fd1);
}
