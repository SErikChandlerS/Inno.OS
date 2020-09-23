#include <stdio.h>

int main()
{
    int n, arrival_time[10], burst_time[10], waiting_time[10], ct[10], tat[10], done[10], currentTime = 0; 
    float avwt = 0, avtat = 0;
	
    printf("Number (<=10) of procesess:");
    scanf("%d",&n);
 
    printf("\nProcesses Arrival Time");
    for(int i = 0; i < n; i++) scanf("%d",&arrival_time[i]);
 
    printf("\nProcesses Burst Time");
    for(int i = 0; i < n; i++) scanf("%d",&burst_time[i]);
    
    for (int i = 0; i < n; i++) {
        done[i] = 0;
        waiting_time[i] = 0;
        tat[i] = 0;
    }
 
    for (int i = 0; i < n; i++) {
        int min = 100000; 
        int minj = -1;
        for (int j = 0; j < n; j++) {
            if (arrival_time[j] <= currentTime && min > burst_time[j] && done[j] == 0) {
                minj = j;
                min = burst_time[j];
            }
        }
        currentTime += min;
         for (int j = 0; j < n; j++) {
            waiting_time[minj] += done[j];
        }
        done[minj] = min;
        waiting_time[minj] -= arrival_time[minj];
        ct[i] = currentTime;
    }
 
    printf("\nProcess\t\tArrival Time\tCompletion Time\tBurst Time\tWaiting Time\tTurnaround Time");
 
    for(int i = 0; i < n; i++)
    {
        tat[i] = burst_time[i] + waiting_time[i];
        avwt += waiting_time[i];
        avtat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i+1, arrival_time[i], ct[i], burst_time[i], waiting_time[i], tat[i]);
    }
 
    avwt /= n;
    avtat /= n;
	
    printf("\nAverage Waiting Time: %f",avwt);
    printf("\nAverage Turnaround Time: %f",avtat);
    
    return 0;
}
