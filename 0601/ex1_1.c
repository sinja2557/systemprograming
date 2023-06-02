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
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main(int argc, char* argv[]){

	key_t key = 987654;
	int nsems = 1;
	int semid;
	struct sembuf sb = {0, 0, SEM_UNDO};


	if((semid = semget(key, nsems, 0)) == -1){
		perror("semget");
		exit(1);
	}



	return 0;
}

