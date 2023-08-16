#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <limits.h> 
int abs(int a){ 
return (a < 0) ? -a : a; 
} 
int findShortestSeekTime(int *requests, bool *visited, int head, int n){ int shortest_seek_time = INT_MAX; 
int shortest_seek_index = -1; 
for (int i = 0; i < n; i++) { 
if (!visited[i]) { 
int seek_time = abs(requests[i] - head); 
if (seek_time < shortest_seek_time) { 
shortest_seek_time = seek_time; 
shortest_seek_index = i; 
} 
} 
} 
return shortest_seek_index; 
} 
int main(){ 
int n, head, i; 
int total_movement = 0; 
printf("Enter the number of disk requests: "); 
scanf("%d", &n); 
int requests[n]; 
bool visited[n]; 
printf("Enter the disk request sequence:\n"); 
for (i = 0; i < n; i++) { 
scanf("%d", &requests[i]); 
visited[i] = false; 
} 
printf("Enter the initial position of the disk head: "); 
scanf("%d", &head); 
printf("Disk Head Movement:\n"); 
printf("%d -> ", head); 
for (i = 0; i < n; i++) { 
int shortest_seek_index = findShortestSeekTime(requests, visited, head, n); total_movement += abs(requests[shortest_seek_index] - head); 
head = requests[shortest_seek_index]; 
visited[shortest_seek_index] = true; 
printf("%d -> ", head); 
} 

printf("\nTotal Head Movement: %d\n", total_movement); printf("Name: Rajani Lamichhane\n"); 
printf("Roll No: 25796\n"); 
return 0; 
} 

