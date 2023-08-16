#include <stdio.h>

void calculateWaitingTime(int n, int bt[], int wt[]) {
    int remaining_bt[n];
    // Copy the burst times to a new array
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }
    int completed = 0, t = 0, shortest = 0, min_bt = 9999, finish_time;
    // Process until all processes are completed
    while (completed != n) {
        // Find the process with the minimum burst time
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] < min_bt && remaining_bt[i] > 0) {
                min_bt = remaining_bt[i];
                shortest = i;
            }
        }
        // Decrement the remaining burst time of the selected process
        remaining_bt[shortest]--;
        // Update the minimum burst time and check if the process is completed
        if (remaining_bt[shortest] == 0) {
            completed++;
            finish_time = t + 1;
            // Calculate the waiting time for the completed process
            wt[shortest] = finish_time - bt[shortest];
            // Reset the minimum burst time
            min_bt = 9999;
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

void calculateAverageTime(int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0;
    double total_tat = 0;

    calculateWaitingTime(n, bt, wt); // Calculate waiting time
    calculateTurnaroundTime(n, bt, wt, tat); // Calculate turnaround time

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    double avg_wt = (double)total_wt / n; // Calculate average waiting time
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

