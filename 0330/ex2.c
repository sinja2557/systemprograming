#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	struct stat buf;

	stat(argv[1], &buf);

	printf("Mode = %o (16 : %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

	if(S_ISFIFO(buf.st_mode)) printf("%s : FIFO\n", argv[1]);
	if(S_ISDIR(buf.st_mode)) printf("%s : Directory\n", argv[1]);
	if(S_ISREG(buf.st_mode)) printf("%s : Regular File\n", argv[1]);

	return 0;

}
