#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	struct stat buf;

	chmod("unix.txt", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);
	stat("unix.txt", &buf);
	printf("1.Mode = %o\n", (unsigned int)buf.st_mode);

	buf.st_mode |= S_IWGRP;
	buf.st_mode &= ~(S_IROTH);
	chmod("unix.txt", buf.st_mode);
	stat("unix.txt", &buf);
	printf("2.Mode = %o\n", (unsigned int)buf.st_mode);
	

	return 0;
}

