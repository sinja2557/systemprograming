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

	if (argc != 3) {
		perror("argc");
		exit(1);
	}

	int m_type = atoi(argv[1]);

	key = ftok("keyfile", m_type);
	msgid = msgget(key, IPC_CREAT|0644);
	if (msgid == -1) {
		perror("msgget");
		exit(1);
	}

	mesg.mtype = m_type;
	strcpy(mesg.mtext, argv[2]);

	if (msgsnd(msgid, (void*)&mesg, 80, IPC_NOWAIT) == -1) {
		perror("msgsnd");
		exit(1);
	}
	

	return 0;
}

