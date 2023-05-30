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

int main(int argc, char* argv[]){

	int shmid;
	char *num;
	key_t key = 987654;
	void *memory_segment = NULL;
	char buf[1000];

	if((shmid = shmget(key, 1024, IPC_CREAT|0666)) == -1) {
		printf("shmget failed\n");
		exit(1);
	}

	if((memory_segment = shmat(shmid, NULL, 0)) == (void*) -1) {
		printf("shmat failed\n");
		exit(1);
	}

	printf("Shared memoty 01 ID : %d\n", shmid);
	printf("Shared memoty 01 attached address : %p\n\n", num);

	printf(">> ");
	gets(buf);
	num = (char*)memory_segment;
	strcpy(num, buf);

	printf("Data in shared memoty 01 : %s\n", num);

	shmctl(shmid, IPC_RMID, NULL);


	return 0;
}

