#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int HIT = 0;
int MISS = 0;
int TOTAL = 0;

int find_min(int size, unsigned char access_register[]){
	int max = 255, index = 0;
	for(int i=0; i<size; ++i){
		if(access_register[i] < max){
			max = access_register[i];
			index = i;
		}
	}
	return index;
}

void substitute_page(int table[], int size, unsigned char access_register[], int page){
	int min = find_min(size, access_register);
	table[min] = page;
	access_register[min] = 255;
	for(int i=0; i<size; ++i){
		if (i != min){
			access_register[i] = (access_register[i] >> 1);
		}
	}
}

char* reference_page(int table[], int size, unsigned char access_register[], int page){
	for(int i=0; i < size; ++i){
		if(table[i] == page){
			HIT++;
			access_register[i] = (access_register[i] >> 1) | 128;
			return "HIT";
		}
		if(TOTAL < size){
			table[TOTAL] = page;
			MISS++;
			access_register[TOTAL] = 128;
			
			for(int i=0; i<size; i++){
				if (i != TOTAL){
					access_register[i] = (access_register[i] >> 1);
				}
			}
			
			TOTAL++;
			return "MISS";
		}
	}
	MISS++;
	substitute_page(table, size, access_register, page);
	return "MISS";
}

int main(int argc, char * argv[]){

	if (argc < 2){
		printf("Please provide page frame number and file directory\n");
	}

	int size = atoi(argv[1]);	// read page frame number
	int table[size];	// declare page table
	unsigned char access_register[size]; // register access of each page
	char buff[10];

	FILE * fp=fopen(argv[2], "r");	// read file

	for(int i=0; i<size; ++i){	// initialize a page table
		table[i] = -1;	// -1 is denoted as an empty cell
		buff[i] = 0; // 0 is denoted as 0 accesses
	}

	while(fscanf(fp, "%s", buff) != EOF){//retrieve page reference sequence one by one
		printf("Referencing PAGE:%s\n", buff);
		printf("STATUS: %s\n", reference_page(table, size, access_register, atoi(buff)));
	}

	printf("HIT:%d MISS:%d\n", HIT, MISS);
	printf("HIT/MISS ratio:%.3f", HIT / MISS);
	fclose(fp);
}
