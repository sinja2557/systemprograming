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

pthread_mutex_t mutex;
void *count(void *arg);
int cnt=0;

int main(int argc, char* argv[]){

	int i;
	pthread_t thread1, thread2;

	pthread_mutex_init(&mutex,NULL);

	pthread_create(&thread1, NULL, count, (void*)"thread1");
	pthread_create(&thread2, NULL, count, (void*)"thread2");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

void *count(void *arg) {
	int i;
	char* name = (char*)arg;

	pthread_mutex_lock(&mutex);

	cnt=0;
	for (i=0;i<10;i++) {
		printf("%s cnt: %d\n", name, cnt);
		cnt++;
		sleep(1);
	}

	pthread_mutex_unlock(&mutex);
}

