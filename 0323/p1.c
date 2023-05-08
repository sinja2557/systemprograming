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
	int count = 0;
	char buf[MAX_BUF];

	fd1 = open(argv[1], O_RDONLY);

	count = lseek(fd1, 0, SEEK_END);
	printf("File bytes = %d\n", count);


	close(fd1);
}
