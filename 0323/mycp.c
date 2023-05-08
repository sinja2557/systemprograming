#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_BUF 2

void main(int argc, char *argv[]){
	FILE *fp1, *fp2;
	char buf[MAX_BUF];
	//int line = 1;

	fp1 = fopen("test.txt", "rt");
	fp2 = fopen("testcp.txt", "wt");



	while(fgets(buf, MAX_BUF, fp1)) {
		fputs(buf, fp2);
	}

	fclose(fp1);
	fclose(fp2);
}
