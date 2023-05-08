#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

typedef struct stu{
	char name[10];
	int kor;
	int eng;
	int math;

}S;

void main(int argc, char* argv[]){
	FILE *fp;
	S s[4] = {
	{ "Kim", 90, 80, 85 },
	{ "Lee", 80, 85, 80 },
	{ "Park", 100, 95, 95 },
	{ "Song", 75, 90, 95 }	
	};
	S ss[4];
	fp = fopen("test.bin", "wb");
	fwrite(s, sizeof(s), 1, fp);
	fclose(fp);

	fp = fopen("test.bin", "rb");
	fread(ss, sizeof(ss), 1, fp);
	for(int i = 0; i < 4 ;i++){
		printf("%s : %d %d %d\n", ss[i].name, ss[i].kor, ss[i].eng, ss[i].math);
	}

	fclose(fp);
}
