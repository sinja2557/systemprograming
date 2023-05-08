#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void main(int argc, char* argv[]){
	FILE *fp;
	char buf[26];
	char fcase[13];
	char scase[13];

	fp = fopen("alphabet.txt", "r");
	printf("First case\n");
	fread(buf, strlen(buf), 1, fp);
	fseek(fp, 0, 0);
	for(int i = 0; i < 13; i++){
		char ch = getc(fp);
		fcase[i] = ch;
		fseek(fp, 1, 1);
	}
	printf("%s", fcase);

	printf("\nSecond case\n");
	fseek(fp, 1, 0);
	for(int i = 0; i < 13; i++){
		char ch = getc(fp);
		scase[i] = ch;
		fseek(fp, 1, 1);
	}
	printf("%s", scase);
	printf("\n");
}
