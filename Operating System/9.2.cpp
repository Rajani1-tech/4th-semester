#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
typedef struct Node{ 
int block_number; 
struct Node *next; 
} Node; 
Node *head = NULL; 
void initializeList(int total_blocks){ 
for (int i = total_blocks - 1; i >= 0; i--) { 
Node *newNode = (Node *)malloc(sizeof(Node)); 
newNode->block_number = i; 
newNode->next = head; 
head = newNode; 
} 
}void allocateBlock(){ 
if (head == NULL) { 
printf("No free blocks available for allocation.\n"); 
} 
else { 
Node *allocatedBlock = head; 
head = head->next; 
printf("Block %d allocated successfully.\n", allocatedBlock->block_number); free(allocatedBlock); 
} 
} 
void deallocateBlock(int block_number){ 
Node *newNode = (Node *)malloc(sizeof(Node)); 
newNode->block_number = block_number; 

newNode->next = head; 
head = newNode; 
printf("Block %d deallocated successfully.\n", block_number); } 
void displayList(){ 
if (head == NULL) { 
printf("The list is empty.\n"); 
} 
else { 
printf("Free Blocks: "); 
Node *current = head; 
while (current != NULL) { 
printf("%d ", current->block_number); 
current = current->next; 
} printf("\n"); 
} 
} 
void freeList(){ 
Node *current = head; 
while (current != NULL) { 
Node *temp = current; 
current = current->next; 
free(temp); 
} 
head = NULL; 
} 
int main(){ 
int choice; 
int total_blocks; 
printf("Enter the total number of blocks: "); 
scanf("%d", &total_blocks); 
initializeList(total_blocks); 
do { 
printf("\n-- Menu --\n"); 
printf("1. Allocate block\n"); 
printf("2. Deallocate block\n"); 
printf("3. Display list\n"); 
printf("4. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: { 
allocateBlock(); 
break; 
} case 2: { 
int block_number; 
printf("Enter the block number to deallocate: "); 
scanf("%d", &block_number); 
if (block_number < 0 || block_number >= total_blocks){ printf("Invalid block number. Please try again.\n"); break; 
} 
deallocateBlock(block_number); 
break; 
} 
case 3: { 
displayList(); 
break; 
} 
case 4: { 
printf("Exiting the program.\n"); 
break; 
} 
default: 
{ 
printf("Invalid choice. Please try again.\n"); 
break; 
} 
} 
} while (choice != 4); 
freeList(); 
printf("Name: Rajani Lamichhane\n"); 
printf("Roll No: 25796\n"); 
return 0; 
} 





