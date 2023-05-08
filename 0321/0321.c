#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_BUF 2

void main(int argc, char *argv[]){
	int fd1, fd2, count;
	char buf[MAX_BUF];

	if (argc != 3){
		printf("Usage: %s source destination\n", argv[0]);
		exit(1);
	}
	
	if ((fd1 = open(argv[1], O_RDONLY)) < 0){
		perror("open");
		exit(1);
	}

	if ((fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644)) < 0) {
		perror("open");
		exit(1);
	}

	while(read(fd1, buf, MAX_BUF) != 0){
		write(fd2, buf, strlen(buf));
	}

	close(fd1);
	close(fd2);

}
