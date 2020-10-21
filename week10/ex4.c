#include<stdlib.h>
#include<stdio.h>

int main(){
	int inode;
	FILE * file;  
	file = fopen("/tmp/file1", 'r');

	if (file < 0) {  
		return -1;		    
	}  

	struct stat file_stat;  
	int var = fstat (file, &file_stat);
	
	if (var < 0) {  
	   return -1;  
	} 

	inode = file_stat.st_ino;

	printf("%d\n", inode);
	
	return 0;
}