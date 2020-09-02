#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *arr, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size - 1 - i; j++){
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

int main(){
	int arr[] = {10, 15, 14, 33, 11, 16, 12};
	printf("Array before sorting:\n");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    printf("Array after sorting:\n");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}

	return 0;
}