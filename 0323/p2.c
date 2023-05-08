#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#define MAX_BUF 5

void main(int argc, char *argv[]){
	int fd1;

	creat("p2_test", 0644);
	fd1 = open("p2_test", O_RDWR | O_CREAT | O_TRUNC, 0644);
	lseek(fd1, 9999, SEEK_SET);
	write(fd1, " ", 1);


	close(fd1);
}
