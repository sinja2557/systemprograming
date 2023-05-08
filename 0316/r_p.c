#include <stdio.h>
#include <stdlib.h>

int r_p(int n, int arr[]){
	arr[n] += 1;

	if (n==0) {
		return 0;
	} else if(n==1) {
		return 1;
	}
	return r_p(n-1, arr) + r_p(n-2, arr);

}
