#include <stdio.h>

typedef struct student{
	char name[10];
	int score;
}S;

int main(){
	S s1[3] = {
	{ "A", 90 },
	{ "B", 75 },
	{ "C", 65 }
	};

	int num = sizeof(s1) / sizeof(S);

	func1(s1, num); //average
	func2(s1, num); //grade

	return 0;

}

