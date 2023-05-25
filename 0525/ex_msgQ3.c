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

int main(int argc, char* argv[]){

	key_t key;
	int msgid;

	key = ftok("keyfile", 1);
	msgid = msgget(key, IPC_CREAT|0644);
	if (msgid == -1) {
		perror("msgget");
		exit(1);
	}

	printf("Before IPC_RMID\n");
	system("ipcs -q");
	msgctl(msgid, IPC_RMID, (struct msqid_ds *)NULL);
	printf("After IPC_RMID\n");
	system("ipcs -q");

	return 0;
}

