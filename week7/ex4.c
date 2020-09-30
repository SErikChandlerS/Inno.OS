#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* reallocate_please(int * ptr, int new_size, int old_size){
	int * new;
	if(ptr == NULL){
		return malloc(old_size*sizeof(int));
	}	
	if(new_size == 0){
		free(ptr);
		return NULL;
	}

	new=(int*)malloc(sizeof(int)*new_size);	
	memcpy(new, ptr,(old_size > new_size)? new_size*sizeof(int) : old_size*sizeof(int));

	free(ptr);
	return new;
}

int main(){

	int * ptr = (int*)malloc(5*sizeof(int));

	for(int i=0; i<5; i++){
		ptr[i] = i;
		printf("%d ", ptr[i]);
	}
	printf("\n");
	ptr = reallocate_please(ptr, 10, 5);
	
	for(int i=0; i<10; ++i){
		printf("%d ", ptr[i]);
	}


	
}