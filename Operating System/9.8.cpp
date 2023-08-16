#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
int abs(int a){ 
return (a < 0) ? -a : a; 
} 
void clook(int *requests, int n, int head){ 
int total_movement = 0; 
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
if (requests[i] >= head) { 
head_index = i; 
break; 
} 
} 
printf("Disk Head Movement:\n"); 
printf("%d -> ", head); 
for (i = head_index; i < n; i++) { 
current_track = requests[i]; 
printf("%d -> ", current_track); 
total_movement += abs(head - current_track); head = current_track; 
} 
if (head_index > 0) { 
for (i = 0; i < head_index; i++){ 
current_track = requests[i]; 
printf("%d -> ", current_track); 
total_movement += abs(head - current_track); head = current_track; 
} 
} 

printf("\nTotal Head Movement: %d\n", total_movement); } 
int main(){ 
int n, head, i; 
printf("Enter the number of disk requests: "); scanf("%d", &n); 
int requests[n]; 
printf("Enter the disk request sequence:\n"); for (i = 0; i < n; i++) { 
scanf("%d", &requests[i]); 
} 
printf("Enter the initial position of the disk head: "); scanf("%d", &head); 
clook(requests, n, head); 
printf("Name: Rajani Lamichhane\n"); 
printf("Roll No: 25796\n"); 
return 0; 
} 







