#include <stdio.h>

void calculateWaitingTime(int n, int bt[], int wt[], int quantum) {
    int remaining_bt[n];
    // Copy the burst times to a new array
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }
    int t = 0;
    // Process until all processes are completed
    while (1) {
        int completed = 1;
        for (int i = 0; i < n; i++) {
            // If the process still has burst time remaining
            if (remaining_bt[i] > 0) {
                completed = 0; // Set completed flag to false
                // If the remaining burst time is less than or equal to the quantum
                if (remaining_bt[i] <= quantum) {
                    t += remaining_bt[i]; // Increment time by the remaining burst time
                    wt[i] = t - bt[i]; // Calculate waiting time for the process
                    remaining_bt[i] = 0; // Set remaining burst time to 0
                } else {
                    t += quantum; // Increment time by the quantum
                    remaining_bt[i] -= quantum; // Decrement the remaining burst time by the quantum
                }
            }
        }
        // If all processes are completed, exit the loop
        if (completed == 1) {
            break;
        }
    }
}

void calculateTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void calculateAverageTime(int n, int bt[], int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    calculateWaitingTime(n, bt, wt, quantum); // Calculate waiting time
    calculateTurnaroundTime(n, bt, wt, tat); // Calculate turnaround time
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    double avg_wt = (double)total_wt / n; // Calculate average waiting time
    double avg_tat = (double)total_tat / n; // Calculate average turnaround time
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Name: Rajani Lamichhane\n");
    printf("Roll No: 25796\n");
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    calculateAverageTime(n, burst_time, quantum); // Calculate average waiting time and average turnaround time
    return 0;
}

