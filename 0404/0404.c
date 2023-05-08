#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char* argv[]){

	DIR *dp;
	struct dirent *dent;
	struct stat buf;	

	if((dp = opendir(argv[1])) == NULL) {
		perror("opendir: ");
		exit(1);
}
	
	while ((dent = readdir(dp))){
		stat(dent->d_name, &buf);
		printf("------------------------------\n");
		printf("Name : %s\n", dent->d_name);
		printf("Inode(stat) = %ld\n", dent->d_ino);// (unsigned int)buf.st_ino);
		printf("Mode = %o\n", (unsigned int)buf.st_mode);
		printf("UID = %d\n", (int)buf.st_uid);
		printf("SIZE = %d\n", (int)buf.st_size);
		printf("------------------------------\n");

}
	closedir(dp);
	return 0;
}

