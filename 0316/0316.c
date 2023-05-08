#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, result;

	printf("input any number: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n + 1);
	for(int i = n; i >= n;i--){
		arr[i] = 0;
	}

	result = r_p(n, arr);
	printf("<Recursion> \n");
	printf("value: %d\n", result);
	
	for(int i = n; i >= 0; i--){
		printf("fibo[%d]: %d times. \n", i, arr[i]);
	}

	result = i_p(n);
	printf("======================== \n");
	printf("<Iteration> \n");
	printf("value: %d\n", result);

	free(arr);
	return 0;


}
