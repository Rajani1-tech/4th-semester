#include <stdio.h>

struct Process {
    int pid;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(struct Process processes[], int n) {
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].burstTime, processes[i].arrivalTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }

    double averageWaitingTime = 0, averageTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        averageWaitingTime += processes[i].waitingTime;
        averageTurnaroundTime += processes[i].turnaroundTime;
    }

    averageWaitingTime /= n;
    averageTurnaroundTime /= n;

    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

void fcfsScheduling(struct Process processes[], int n) {
    calculateTimes(processes, n);
    displayResults(processes, n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    fcfsScheduling(processes, n);

    return 0;

 printf(" Name: Rajani Lamichhane");
 printf(" Rollno: 25796");
 printf(" ");
}
