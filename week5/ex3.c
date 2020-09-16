#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 50 //initializing length of buffer

int main(){
	char command[BUFF_SIZE];
	
	while(true){ // we will read commands from user until exit
		char directory[BUFF_SIZE];
		getcwd(directory, sizeof(directory)); // getting working directory
		
		printf("shell : %s : ", directory); //init shell in directory
		scanf("%s", command); // get command from user
		
		if(strcmp(command, "exit") == 0){ // cheking on "exit" command
			break;
		} 
		else {			
			system(command); // man system run the command
		}
	}
	return 0;
}
