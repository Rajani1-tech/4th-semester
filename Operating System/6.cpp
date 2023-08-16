#include <stdio.h>

void calculateWaitingTime(int n, int bt[], int priority[], int wt[]) {
    int remaining_bt[n];

    // Copy the burst times to a new array
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }

    int completed = 0, t = 0, min_priority, shortest;

    // Process until all processes are completed
    while (completed != n) {
        shortest = -1;
        min_priority = 9999;

        // Find the process with the highest priority among the processes that have arrived
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0 && priority[i] < min_priority) {
                min_priority = priority[i];
                shortest = i;
            }
        }

        // Decrement the remaining burst time of the selected process
        remaining_bt[shortest]--;

        // If the burst time of a process is completed, calculate the waiting time
        if (remaining_bt[shortest] == 0) {
            completed++;
            wt[shortest] = t + 1 - bt[shortest];
        }

        // Increment the time
        t++;
    }
}

void calculateTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void calculateAverageTime(int n, int bt[], int priority[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    calculateWaitingTime(n, bt, priority, wt); // Calculate waiting time
    calculateTurnaroundTime(n, bt, wt, tat); // Calculate turnaround time

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], priority[i], wt[i], tat[i]);
    }

    double avg_wt = (double)total_wt / n; // Calculate average waiting time
    double avg_tat = (double)total_tat / n; // Calculate average turnaround time

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Name: Rajani Lamichhane\n");
    printf("Roll No: 25796\n");
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], priority[n];

    printf("Enter the burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }

    calculateAverageTime(n, burst_time, priority); // Calculate average waiting time and average turnaround time
    return 0;
}

