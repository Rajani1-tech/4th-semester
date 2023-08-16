#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
int abs(int a){ 
return (a < 0) ? -a : a; 
} 
int main(){ 
int n, head, i; 
int total_movement = 0; 
printf("Enter the number of disk requests: "); scanf("%d", &n); 
int requests[n]; 
printf("Enter the disk request sequence:\n"); for (i = 0; i < n; i++) { 
scanf("%d", &requests[i]); 
} 
printf("Enter the initial position of the disk head: "); scanf("%d", &head); 
printf("Disk Head Movement:\n"); 
printf("%d -> ", head); 
for (i = 0; i < n; i++) { 
total_movement += abs(requests[i] - head); 
head = requests[i]; 
printf("%d -> ", head); 
} 
printf("\nTotal Head Movement: %d\n", total_movement); printf("Name: Rajani Lamichhane\n"); 
printf("Roll No: 25796\n"); 
return 0; 
} 


