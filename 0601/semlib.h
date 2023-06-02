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

int semInit(key_t key) {

	int semid;
	if ((semid = semget(key, 1, IPC_CREAT|0600)) < 0) {
		perror("semget");
		return -1;
	}

	return semid;
}


int semInitValue(int semid){

	union semun {
		int val;
	}arg;

	if(semctl(semid, 0, SETVAL, arg) == -1) {
		perror("semctl");
		return -1;
	}

	return 0;

}

int semWait(int semid) {

	struct sembuf smb;

	smb.sem_num = 0;
	smb.sem_op = -1;
	smb.sem_flg = SEM_UNDO;

	if(semop(semid, &smb, 1) < 0) { 
		perror("semop");
		return -1;
	}

	return 0;

}

int semTryWait(int semid) {

	struct sembuf smb;

	smb.sem_num = 0;
	smb.sem_op = -1;
	smb.sem_flg = IPC_NOWAIT | SEM_UNDO;
	if(semop(semid, &smb, 1) < 0) {
		perror("semop");
		return -1;
	}

	return 0;

}

int semPost(int semid) {
	struct sembuf smb;

	smb.sem_num = 0;
	smb.sem_op = 1;
	smb.sem_flg = SEM_UNDO;
	if(semop(semid, &smb, 1) < 0) {
		perror("semop");
		return -1;
	}

	return 0;

}


int semGetValue(int semid) {
	union semun{
		int val;
	}arg;

	semctl(semid, 0, GETVAL, arg);

	return 0;

}

int semDestroy(int semid) {
	union semun {
		int val;
	}arg;

	if (semctl(semid, 0, IPC_RMID, arg) < 0) {
		perror("semctl");
		return -1;
	}

	close(semid);

	return 0;

}


