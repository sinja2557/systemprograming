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

struct mymsgbuf {
	long mtype;
	char mtext[80];
};

int main(int argc, char* argv[]){

	key_t key;
	int msgid;
	struct mymsgbuf mesg;

	key = ftok("keyfile", 1);
	msgid = msgget(key, IPC_CREAT|0644);
	if (msgid == -1) {
		perror("msgget");
		exit(1);
	}

	mesg.mtype = 1;
	strcpy(mesg.mtext, "Message Q Test");

	if (msgsnd(msgid, (void*)&mesg, 80, IPC_NOWAIT) == -1) {
		perror("msgsnd");
		exit(1);
	}
	

	return 0;
}

