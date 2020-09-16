#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread(void *vargp){
	sleep(1);
	pthread_t self = pthread_self();
	printf("Hello world %u\n", self);
	return NULL;
}

int main(){
	pthread_t tid[3];

	for (int i = 0; i < 3 ; ++i)
	{
		pthread_create(&tid[i], NULL, thread, NULL);
		printf("before thread %u\n", tid[i]);
		pthread_join(tid[i], NULL);
		printf("after thread\n");		
	}
}

