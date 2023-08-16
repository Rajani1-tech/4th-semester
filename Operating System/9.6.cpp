#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
int abs(int a){ 
return (a < 0) ? -a : a; 
} 
void cscan(int *requests, int n, int head, char direction){ int total_movement = 0; 
int current_track; 
int i, j; 
// Sort the requests in ascending order 
for (i = 0; i < n - 1; i++) { 
for (j = i + 1; j < n; j++) { 
if (requests[j] < requests[i]) { 
int temp = requests[i]; 
requests[i] = requests[j]; 

requests[j] = temp; 
} 
} 
} 
int head_index; 
for (i = 0; i < n; i++) { 
if (requests[i] >= head){ 
head_index = i; 
break; 
} 
} 
printf("Disk Head Movement:\n"); 
printf("%d -> ", head); 
if (direction == 'L') { 
for (i = head_index; i >= 0; i--) { current_track = requests[i]; 
printf("%d -> ", current_track); 
total_movement += abs(head - current_track); head = current_track; 
} 
total_movement += abs(head - 0); 
head = 0; 
printf("0 -> "); 
total_movement += abs(0 - (n - 1)); 
head = n - 1; 
for (i = n - 1; i > head_index; i--) { current_track = requests[i]; 
printf("%d -> ", current_track); 
total_movement += abs(head - current_track); head = current_track; 
} 
} else if (direction == 'R') { 
for (i = head_index; i < n; i++) { current_track = requests[i]; 
printf("%d -> ", current_track); 
total_movement += abs(head - current_track); head = current_track; 
} 
total_movement += abs(head - (n - 1)); 
head = n - 1; 
printf("%d -> ", n - 1); 
total_movement += abs(n - 1 - 0); 
head = 0; 
for (i = 0; i < head_index; i++) { 
current_track = requests[i]; 
printf("%d -> ", current_track); 
total_movement += abs(head - current_track); 

head = current_track; 
} 
} 
printf("\nTotal Head Movement: %d\n", total_movement); } 
int main(){ 
int n, head, i; 
char direction; 
printf("Enter the number of disk requests: "); scanf("%d", &n); 
int requests[n]; 
printf("Enter the disk request sequence:\n"); for (i = 0; i < n; i++){ 
scanf("%d", &requests[i]); 
} 
printf("Enter the initial position of the disk head: "); scanf("%d", &head); 
printf("Enter the direction (L/R): "); 
scanf(" %c", &direction); 
cscan(requests, n, head, direction); 
printf("Name: Rajani Lamichhane\n"); 
printf("Roll No: 25796\n"); 
return 0; 
} 

