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

void sem_wait(int semid) {
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = -1;
	buf.sem_flg = SEM_UNDO;

	if(semop(semid, &buf, 1) == -1) {
		perror("semop");
		exit(1);
	}
}

void sem_post(int semid) {
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = 1;
	buf.sem_flg = SEM_UNDO;

	if(semop(semid, &buf, 1) == -1) {
		perror("semop");
		exit(1);
	}
}


int main(int argc, char* argv[]){

	key_t key = 987654;
	int shmid, a, semid;
	void *shmaddr;
	char buf[1024];
	
	shmid = shmget(key, 1024, IPC_CREAT|0666);
	shmaddr = shmat(shmid, NULL, 0);

	semid = semget(key, 0, 0);

	for(a=0;a<=10;a++) {
		sem_wait(semid);
		strcpy(shmaddr, "University");
		sleep(1);
		strcpy(buf, shmaddr);
		printf("B : %s\n", buf);
		sem_post(semid);
	}

	shmdt(shmaddr);

	return 0;
}

