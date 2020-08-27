#include<stdio.h>

int main()
{
	int n;
	printf("Enter size ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - 1 - i; j++)
			printf(" ");
		for (int j = 0; j < 1 + i * 2; j++)
			printf("*");
		printf("\n");
	}
	
	return 0;
}