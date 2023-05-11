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
	S s[3];
	S ss[3];

	printf("Id\tName\tGrade\n");
	for(int i = 0; i < 3; i++){
		scanf("%d %s %d", &s[i].id, s[i].name, &s[i].grade);
	}

	fp = fopen("stu.dat", "wb");
	fwrite(s, sizeof(s), 1, fp);
	fclose(fp);
	/*
	fp = fopen("stu.dat", "r+b");
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
	
	printf("Edit stu id : ");
	scanf("%d", &stu_id);
	int set_id = 0;
	for(int i = 0; i < 3; i++){
		if(ss[i].id == stu_id){
			printf("Id:%d\tName:%s\tgrade:%d\n", ss[i].id,ss[i].name,ss[i].grade);
			set_id = i;
			break;
		}
	}
	
	int new_grade = 0;
	printf("Update grade : ");
	scanf("%d", &new_grade);
	ss[set_id].grade = new_grade;
	fwrite(ss, sizeof(ss), 1, fp);
	
	fclose(fp);
	*/	

	return 0;
}

