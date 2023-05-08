#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>

int main(int argc, char* argv[]){

	system("ls -al");
	system("date");
	system("who");

	return 0;
}

