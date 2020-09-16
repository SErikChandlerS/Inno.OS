#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10
#define bool int
#define True 1
#define False 0

bool consumer_sleep = True;
bool producer_sleep = False;


int jar[SIZE];
int top = -1;

int push(int data){
	if(!isFull()){
		jar[++top] = data;
	}else{
		printf("impossible to push\n");
	}
}

int pop(){
	int data;
	
	if (!isEmpty()){
		data = jar[top];
		top--;
		return data;
	}else{
		printf("impossible to pop\n");
	}
}

int isFull(){
	if(top == SIZE){
		return 1;
	}
	return 0;
}

int isEmpty(){
	if(top == -1){
		return 1;
	}
	return 0;
}


void *consumer(){
	while(1){
		if(! consumer_sleep){
			printf("Consume:%d  Rest: ", pop());
			sleep(1);
			for(int j = 0; j <= top; ++j){
				printf("%d ", jar[j]);
			}
			printf("\n");
		}
		if(isEmpty){
			consumer_sleep = True;
			producer_sleep = False;
		}
	}
}

void *producer(){
	time_t seconds; 
    time(&seconds);
	srand(seconds);
	
	while(1){
		if( ! producer_sleep){
			int r = rand() % 100; 
			push(r);
			printf("Produce:%d  Rest: ", r);
			sleep(1);
			for(int j = 0; j <= top; ++j){
				printf("%d ", jar[j]);
			}
			printf("\n");
		}	
		if(isFull){
			consumer_sleep = False;
			producer_sleep = True;
		}
	}
}

int main(){
	pthread_t threadP, threadC;
  
    pthread_create(&threadP, NULL, &producer, NULL); 
    pthread_create(&threadC, NULL, &consumer, NULL); 
	
	pthread_join(threadP, NULL);
	pthread_join(threadC, NULL);

	return 0;
}
