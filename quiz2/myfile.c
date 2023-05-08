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


int main(int argc, char* argv[]){
	if(access(argv[1], F_OK)) {
			printf("%s : is Found.\n", argv[1]);
		}
		else {
			printf("%s : is not found.\n", argv[1]);
		}
	}
	
	return 0;
}

