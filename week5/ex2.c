#include <unistd.h>
#include <stdlib.h>

int main(){
	int LOOP = 5;
	for(int i = 0; i < LOOP; i++){
		fork();
		sleep(5);
	}
}
