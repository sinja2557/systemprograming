#include <stdio.h>
#include <stdlib.h>

int i_p(int n){

	if (n==0) return 0;
	if (n==1 || n==2) return 1;
	int p = 1, pp = 2, result = 2;

	for (int i = 3; i < n ; i++){
		result = p + pp;
		p = pp;
		pp = result;

	}

	return result;

}
