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
int i = 2;

int main(int argc, char* argv[]){

	pthread_t thread1, thread2;

	pthread_mutex_init(&mutex,NULL);

	pthread_create(&thread1, NULL, count, (void*)"thread1");
	pthread_create(&thread2, NULL, count, (void*)"thread2");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

void *count(void *arg) {
	char* name = (char*)arg;

	pthread_mutex_lock(&mutex);
	
	for (int j = 1;j<10;j++) {
		printf("%s : %d x %d = %d\n", name, i, j, i*j);
		sleep(1);
	}

	pthread_mutex_unlock(&mutex);
	i = 3;
}

