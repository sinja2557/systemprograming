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

typedef struct {
	int flag;
	char msg[1024];
}ChatData;

int main(int argc, char* argv[]){

	int shmid;
	key_t key = 987654;
	ChatData *chat_data;
	char buf[1024];


	if((shmid = shmget(key, 1024, IPC_CREAT|0666)) == -1) {
		perror("shmget");
		exit(1);
	}

	if((chat_data = (ChatData *)shmat(shmid, NULL, 0)) == (ChatData *) -1) {
		perror("shmat");
		exit(1);
	}

	chat_data->flag = 0;

	while(1) {
		if (chat_data->flag == 1) {
			printf("From client msg : %s\n", chat_data->msg);
			sleep(1);

			printf("Server >> ");
			fgets(buf, sizeof(buf), stdin);
			strcpy(chat_data->msg, buf);
			chat_data->flag = 0;
		}
	}



	return 0;
}

