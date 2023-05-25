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
	int msgid, len;
	struct mymsgbuf inmsg;

	if (argc != 2) {
		perror("argc");
		exit(1);
	}

	int m_type = atoi(argv[1]);


	key = ftok("keyfile", m_type);
	if ((msgid = msgget(key, 0)) < 0) {
		perror("msgget");
		exit(1);
	}

	len = msgrcv(msgid, &inmsg, 80, m_type, 0);
	printf("Received Msg = %s\n", inmsg.mtext);

//	msgctl(msgid, IPC_RMID, (struct msqid_ds *)NULL);

	return 0;
}

