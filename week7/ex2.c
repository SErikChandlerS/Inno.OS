#include<stdlib.h>
#include<stdio.h>

int main(){
	int n;
	int * arr;
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));

	for(int i=0; i<n; ++i){
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
}