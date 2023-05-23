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
#include <pthread.h>
#include <signal.h>
#include <sys/mman.h>


int main(int argc, char* argv[]){

	int fd[2], pagesize, length;
	caddr_t addr1, addr2;
	size_t copylen;
	struct stat statbuf;
	off_t set = 0;


	if (argc != 3){
		fprintf(stderr, "Usage : %s src dst\n", argv[0]);
		exit(1);
	}

	if (stat(argv[1], &statbuf) == -1){
		perror("stat");
		exit(1);
	}

	pagesize = sysconf(_SC_PAGESIZE);
	length = 1 * pagesize;

	if ((fd[0] = open(argv[1], O_RDWR)) == -1) {
		perror("open");
		exit(1);
	}

	if ((fd[1] = open(argv[2], O_RDWR| O_CREAT | O_TRUNC, 0666)) == -1) {
		perror("open");
		exit(1);
	}

	if(ftruncate(fd[1], statbuf.st_size) == -1){
		perror("ftruncate");
		exit(1);
	}


	printf("Page size : %d\n", length);
	printf("File size : %ld\n", statbuf.st_size);

	while (set < statbuf.st_size){

		if((statbuf.st_size - set) > length){
			copylen = length;
		}
		else {
			copylen = statbuf.st_size;
		}


		addr1 = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd[0], set);
		addr2 = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd[1], set);


		if (addr1 == MAP_FAILED){
			perror("mmap");
			exit(1);
		}

		if (addr2 == MAP_FAILED){
			perror("mmap");
			exit(1);
		}

		memcpy(addr2, addr1, copylen);

		if(munmap(addr1, copylen) == -1){
			perror("munmap");
			exit(1);
		}

		if(munmap(addr2, copylen) == -1){
			perror("munmap");
			exit(1);
		}

		set += copylen;

	}

	close(fd[0]);
	close(fd[1]);

}

