#include <stdio.h> 
#define MAX_PROCESSES 10 
#define MAX_RESOURCES 10 

void checkSafeState(int processes, int resources, int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES]) { 
    int need[MAX_PROCESSES][MAX_RESOURCES]; 
    int finish[MAX_PROCESSES] = {0}; 
    int safeSequence[MAX_PROCESSES]; 
    int work[MAX_RESOURCES]; 

    // Initialize the need matrix and work array 
    for (int i = 0; i < processes; i++) { 
        for (int j = 0; j < resources; j++) { 
            need[i][j] = max[i][j] - allocation[i][j]; 
        } 
    } 

    for (int i = 0; i < resources; i++) { 
        work[i] = available[i]; 
    } 

    int count = 0; 
    while (count < processes) { 
        int found = 0; 
        for (int i = 0; i < processes; i++) { 
            if (!finish[i]) { 
                int j; 
                for (j = 0; j < resources; j++) { 
                    if (need[i][j] > work[j]) 
                        break; 
                } 
                if (j == resources) { 
                    for (int k = 0; k < resources; k++) { 
                        work[k] += allocation[i][k]; 
                    } 
                    safeSequence[count] = i; 
                    finish[i] = 1; 
                    count++; 
                    found = 1; 
                } 
            } 
        } 
        if (!found) 
            break; 
    } 

    if (count == processes) { 
        printf("Safe Sequence: "); 
        for (int i = 0; i < processes; i++) { 
            printf("%d ", safeSequence[i]); 
        } 
        printf("\n"); 
    } else { 
        printf("System is in an unsafe state.\n"); 
        printf("Name: Rajani Lamichhane\n"); 
        printf("Roll No: 25796\n"); 
    } 
} 

int main() { 
    int processes, resources; 
    printf("Enter the number of processes: "); 
    scanf("%d", &processes); 
    printf("Enter the number of resources: "); 
    scanf("%d", &resources); 

    if (processes > MAX_PROCESSES || resources > MAX_RESOURCES) { 
        printf("Exceeded maximum limits for processes or resources.\n"); 
        return 1; 
    } 

    int available[MAX_RESOURCES]; 
    printf("Enter the number of available resources for each type:\n"); 

    for (int i = 0; i < resources; i++){ 
printf("Resource %d: ", i + 1); 
scanf("%d", &available[i]); 
} 
int max[MAX_PROCESSES][MAX_RESOURCES]; 
int allocation[MAX_PROCESSES][MAX_RESOURCES]; 
printf("Enter the maximum demand of each process for each resource:\n"); for (int i = 0; i < processes; i++) { 
printf("Process %d:\n", i + 1); 
for (int j = 0; j < resources; j++) { 
printf("Resource %d: ", j + 1); 
scanf("%d", &max[i][j]); 
} 
} 
printf("Enter the allocation of each resource to each process:\n"); for (int i = 0; i < processes; i++) 
{ 
printf("Process %d:\n", i + 1); 
for (int j = 0; j < resources;
j++){ 
	printf("Resource %d: ", j + 1); 
	scanf("%d", &allocation[i][j]); 
	} 
} 
checkSafeState(processes, resources, available, max, allocation); 
return 0; 
} 


