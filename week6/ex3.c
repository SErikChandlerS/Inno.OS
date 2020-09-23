#include<stdio.h> 
 
int main() 
{ 
 
  int count = 0, n, currentTime = 0, remain, flag = 0, quantum; 
  int wt = 0, tat = 0, at[10], bt[10], rt[10]; 
  printf("Number (<=10) of procesess:");
  scanf("%d",&n);
  remain = n; 
  
  printf("\nProcesses Arrival Time\n");
  for(int i=0; i < n; i++) {
    scanf("%d", &at[i]);
  }
  
  printf("\nProcesses Burst Time\n");
  for(int i=0; i < n; i++) {
      scanf("%d", &bt[i]);
      rt[i] = bt[i];
  }
  
  printf("Time Quantum:\t"); 
  scanf("%d" ,&quantum); 
  
  printf("\nProcess\t\tArrival Time\tCompletion Time\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
  while(remain != 0) { 
      
    if(rt[count] <= quantum && rt[count] > 0) { 
      currentTime += rt[count]; 
      rt[count] = 0; 
      flag = 1; 
    } 
    
    else if(rt[count] > 0) { 
      rt[count] -= quantum; 
      currentTime += quantum; 
    } 
    
    if(rt[count] == 0 && flag == 1) {  
      remain--; 
      printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", count+1, at[count], currentTime, bt[count], currentTime-at[count]-bt[count], currentTime-at[count]); 
      wt += currentTime - at[count] - bt[count]; 
      tat += currentTime - at[count]; 
      flag = 0; 
    } 
    
    if(count == n - 1) 
      count = 0; 
      
    else if(at[count + 1] <= currentTime) 
      count++; 
      
    else 
      count = 0; 
  } 
  
  printf("\nAverage Waiting Time = %f", wt*1.0/n); 
  printf("\nAverage Turnaround Time = %f", tat*1.0/n); 
  
  return 0; 
}