#include <unistd.h>
#include <stdio.h>

int main(){
  int parentPID = getpid();
  fork();
  int childPID = getpid();

  if(parentPID == childPID){
    printf("Hello from parent [PID - %d]\n", parentPID);
  } else {
    printf("Hello from child [PID - %d]\n", childPID);
  }
  return 0;
}
