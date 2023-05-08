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

void *thread_function(void *arg);

int main(int argc, char* argv[]){

	int state;
	pthread_t tid;
	state = pthread_create(&tid, NULL, thread_function, NULL);

	if(state != 0) {
		perror("thread create error : ");
		exit(1);
	}

	state = pthread_join(tid, NULL);
	sleep(3);
	puts("main function is end");
	printf("%d", state);
	return 0;
}

void *thread_function(void *arg) {
	int i;
	for(i=0;i<3;i++) {
		sleep(2);
		puts("Thread is running..");
	}
}

