#include <stdio.h>

struct student{
	char name[10];
	int score;
};

void func1(struct student s1[], int num){

	int total = 0;

	for(int i = 0;i<num;i++){
		total += s1[i].score;
	}

	printf("Average : %d\n", total / num);

}
