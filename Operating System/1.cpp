#include <stdio.h> 

void calculateWaitingTime(int n, int bt[], int wt[]) { 
    wt[0] = 0; // Waiting time for the first process is 0 

    // Calculate waiting time for each process 
    for (int i = 1; i < n; i++) { 
        wt[i] = wt[i - 1] + bt[i - 1]; 
    } 
} 

void calculateTurnaroundTime(int n, int bt[], int wt[], int tat[]) { 
    // Calculate turnaround time for each process 
    for (int i = 0; i < n; i++) { 
        tat[i] = bt[i] + wt[i]; 
    } 
} 

void calculateAverageTime(int n, int bt[]) { 
    int wt[n], tat[n];
    double total_wt = 0, total_tat = 0; 

    calculateWaitingTime(n, bt, wt); // Calculate waiting time 
    calculateTurnaroundTime(n, bt, wt, tat); // Calculate turnaround time 

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    // Calculate total waiting time and total turnaround time 
    for (int i = 0; i < n; i++) { 
        total_wt += wt[i]; 
        total_tat += tat[i]; 
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]); 
    } 

    double avg_wt = total_wt / n; // Calculate average waiting time 
    double avg_tat = total_tat / n; // Calculate average turnaround time 

    printf("\nAverage Waiting Time: %.2f\n", avg_wt); 
    printf("Average Turnaround Time: %.2f\n", avg_tat); 
    printf("Name: Rajani Lamichhane\n"); 
    printf("Roll No: 25796\n"); 
} 

int main() { 
    int n; 

    printf("Enter the number of processes: "); 
    scanf("%d", &n); 

    int burst_time[n]; 

    printf("Enter the burst time for each process:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Process %d: ", i + 1); 
        scanf("%d", &burst_time[i]); 
    } 

    calculateAverageTime(n, burst_time); // Calculate average waiting time and average turnaround time 

    return 0; 
}

