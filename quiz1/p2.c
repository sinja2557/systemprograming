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

typedef struct student{
	int id;
	char* name[10];
	int grade;

}S;

int main(int argc, char* argv[]){

	FILE *fp;
	S ss[3];

	fp = fopen("stu.dat", "rb");
	fread(ss, sizeof(ss), 1, fp);
	
	int stu_id = 0;
	printf("input stu id : ");
	scanf("%d", &stu_id);
	for(int i = 0; i < 3; i++){
		if(ss[i].id == stu_id){
			printf("Id:%d\tName:%s\tgrade:%d\n", ss[i].id,ss[i].name,ss[i].grade);
			break;
		}
	}
		

	return 0;
}

