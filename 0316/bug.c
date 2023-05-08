#include <stdio.h>
#include <string.h>

int main(){
	int i;
	double j;
	char *bug = NULL;

	for(i = 0;i<5;i++) {
		j = i/2 + i;
		printf("j is %lf \n", j);
	}

	strcpy(bug, "hi");
	printf("bug is %s \n", bug);

	return 0;



}
