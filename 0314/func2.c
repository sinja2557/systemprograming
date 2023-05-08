#include <stdio.h>

struct student{
	char name[10];
	int score;
};

void func2(struct student s1[], int num){

	char grade = '\0'; // default

	for(int i = 0;i<num;i++){

		if(s1[i].score >= 90){
			grade = 'A';
		}
		else if(s1[i].score >= 80){
			grade = 'B';
		}
		else if(s1[i].score >= 70){
			grade = 'C';
		}
		else if(s1[i].score >= 60){
			grade = 'D';
		}
		else {

			grade = 'F';
		}

		printf("%s : %c\n", s1[i].name, grade);

	}
}
