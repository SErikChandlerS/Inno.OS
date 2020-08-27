#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	printf("Enter two integer: ");
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d and %d", a, b);
	return 0;
}