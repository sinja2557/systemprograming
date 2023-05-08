#include <stdio.h>

void main(int argc, char* argv[]){
	char exec[100];
	setuid(0);
	setgid(0);
	sprintf(exec, "%s 2>/dev/null ", argv[1]);
	system(exec);

}
