#include <stdio.h>
#include <stdbool.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void detectDeadlock(int processes, int resources, int allocation[][MAX_RESOURCES], int request[][MAX_RESOURCES], int available[]) {
    bool finish[MAX_PROCESSES] = {false};
    int work[MAX_RESOURCES];
    // Initialize the work array with the available resources
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }
    bool found;
    bool deadlocked[MAX_PROCESSES] = {false};
    int deadlockedCount = 0;

    do {
        found = false;
        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                bool canExecute = true;
                for (int j = 0; j < resources; j++) {
                    if (request[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    // Release the allocated resources
                    for (int j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
    } while (found);

    // Check for any unfinished processes (deadlocked processes)
    for (int i = 0; i < processes; i++) {
        if (!finish[i]) {
            deadlocked[i] = true;
            deadlockedCount++;
        }
    }

    if (deadlockedCount > 0) {
        printf("Deadlocked Processes: ");
        for (int i = 0; i < processes; i++) {
            if (deadlocked[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("No Deadlocked Processes\n");
    }
}

int main() {
    int processes, resources;
    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int request[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];

    printf("Enter the allocation of each resource to each process:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d:\n", i);
        for (int j = 0; j < resources;j++){ 
printf("Resource %d: ", j + 1); 
scanf("%d", &allocation[i][j]); 
} 
} 
printf("Enter the request of each resource by each process:\n"); for (int i = 0; i < processes; i++) { 
printf("Process %d:\n", i + 1); 
for (int j = 0; j < resources; j++) { 
printf("Resource %d: ", j + 1); 
scanf("%d", &request[i][j]); 
} 
} 
printf("Enter the number of available resources for each type:\n"); for (int i = 0; i < resources; i++) { 
printf("Resource %d: ", i + 1); 
scanf("%d", &available[i]); 
} 
printf("Name: Rajani Lamichhane\n"); 
printf("Roll No: 25796"); 
detectDeadlock(processes, resources, allocation, request, available); return 0; 
} 


