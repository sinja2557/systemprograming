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
	union semun arg;


	// create
	if((semid = semget(key, nsems, IPC_CREAT|0666)) == -1){
		perror("semget");
		exit(1);
	}

	// initialize
	if(setctl(semid, 0, SETVAL, arg) == -1) {
		perror("setctl");
		exit(1);
	}

	return 0;
}

