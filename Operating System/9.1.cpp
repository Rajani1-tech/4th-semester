#include <stdio.h> 
#include <stdbool.h> 
#define MAX_BLOCKS 100 
bool bitmap[MAX_BLOCKS]; 
void initializeBitmap(int total_blocks){ 
for (int i = 0; i < total_blocks; i++) { 
bitmap[i] = false; 
} 
} 
void allocateBlock(int block_number){ 
if (bitmap[block_number]) { 
printf("Block %d is already allocated.\n", block_number); } else { 
bitmap[block_number] = true; 
printf("Block %d allocated successfully.\n", block_number); } 
} 
void deallocateBlock(int block_number){ 
if (bitmap[block_number]) { 
bitmap[block_number] = false; 
printf("Block %d deallocated successfully.\n", block_number); } 
else { 
printf("Block %d is already deallocated.\n", block_number); } 
} 
void displayBitmap(int total_blocks){ 
printf("Block\tStatus\n"); 
for (int i = 0; i < total_blocks; i++) { 
printf("%d\t%s\n", i, bitmap[i] ? "Allocated" : "Deallocated"); } 
} 
int main(){ 
int choice; 
int total_blocks; 
printf("Enter the total number of blocks: "); 
scanf("%d", &total_blocks); 
initializeBitmap(total_blocks); 
do { 
printf("\n-- Menu --\n"); 
printf("1. Allocate block\n"); 
printf("2. Deallocate block\n"); 
printf("3. Display bitmap\n"); 
printf("4. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { case 1: 
{ 
int block_number; 
printf("Enter the block number to allocate: "); 
scanf("%d", &block_number); 
if (block_number < 0 || block_number >= total_blocks){ 
printf("Invalid block number. Please try again.\n"); 
break; 
} 
allocateBlock(block_number); 
break; 
} 
case 2: { 
int block_number; 
printf("Enter the block number to deallocate: "); 
scanf("%d", &block_number); 
if (block_number < 0 || block_number >= total_blocks) { printf("Invalid block number. Please try again.\n"); 
break; 
} 
deallocateBlock(block_number); 
break; 
} 
case 3: { 
displayBitmap(total_blocks); 
break; 
} 
case 4: { 
printf("Exiting the program.\n"); 
break; 
} 
default: { 
printf("Invalid choice. Please try again.\n"); 
break; 
} 
} 
} while (choice != 4); 
printf("Name: Rajani Lamichhane\n"); 

printf("Roll No: 25796\n"); 
return 0; } 



