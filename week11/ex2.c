#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
	char * string = "Hello";
	for(int i = 0; i < strlen(string); ++i){
		printf("%c", string[i]);
		sleep(1);
	}
	return 0;
}