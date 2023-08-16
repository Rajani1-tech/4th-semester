#include <stdio.h> 
#include <stdbool.h> 
#define MAX_FILES 100 
typedef struct{ 
int file_number; 
int file_size; 
int block_numbers[10]; 
bool allocated; 
} Inode; 
Inode inodes[MAX_FILES]; 
void initializeInodes(){ 
for (int i = 0; i < MAX_FILES; i++) { 
inodes[i].file_number = -1; 
inodes[i].file_size = 0; 
for (int j = 0; j < 10; j++) { 
inodes[i].block_numbers[j] = -1; 
} 
inodes[i].allocated = false; 
} 
} 
int findEmptyInode(){ 
for (int i = 0; i < MAX_FILES; i++){ 
if (inodes[i].file_number == -1) 
return i; 
} 
return -1; // No empty inode found 
} 
int findEmptyBlock(){ 
for (int i = 0; i < MAX_FILES; i++){ 
if (inodes[i].file_number == -1) { 
inodes[i].allocated = true; 
return i; 
} 
} 
return -1; // No empty block found 
} 
void allocateFile(int file_number, int file_size){ if (inodes[file_number].file_number != -1){ printf("File %d already exists.\n", file_number); return; 
} 
int required_blocks = file_size / 100; 
if (file_size % 100 != 0) 
required_blocks++; 

int empty_inode = findEmptyInode(); 
if (empty_inode == -1){ 
printf("No empty inode available.\n"); 
return; 
} 
int allocated_blocks = 0; 
for (int i = 0; i < MAX_FILES && allocated_blocks < required_blocks; i++) { if (inodes[i].file_number == -1) { 
inodes[i].file_number = file_number; 
inodes[i].file_size = file_size; 
int blocks_needed = required_blocks - allocated_blocks; 
int empty_blocks = findEmptyBlock(); 
if (empty_blocks == -1) { 
printf("Not enough blocks available for file allocation.\n"); 
inodes[i].file_number = -1; 
inodes[i].file_size = 0; 
return; 
} 
for (int j = 0; j < blocks_needed; j++) { 
inodes[i].block_numbers[j] = empty_blocks + j; 
} 
allocated_blocks += blocks_needed; 
} 
} 
if (allocated_blocks < required_blocks) { 
printf("Not enough blocks available for file allocation.\n"); 
inodes[empty_inode].file_number = -1; 
inodes[empty_inode].file_size = 0; 
} 
else{ 
printf("File %d allocated successfully.\n", file_number); 
} 
} 
void deallocateFile(int file_number){ 
if (inodes[file_number].file_number == -1){ 
printf("File %d does not exist.\n", file_number); 
return; 
} 
int empty_inode = findEmptyInode(); 
if (empty_inode == -1){ 
printf("No empty inode available for deallocation.\n"); 
return; 
} 
int deallocated_blocks = 0; 
for (int i = 0; i < MAX_FILES && deallocated_blocks < inodes[file_number].file_size / 100; i++){ 
if (inodes[i].file_number == file_number) { 

inodes[i].file_number = -1; 
inodes[i].file_size = 0; 
for (int j = 0; j < 10; j++){ 
inodes[i].block_numbers[j] = -1; 
} 
inodes[i].allocated = false; 
deallocated_blocks++; 
} 
} 
printf("File %d deallocated successfully.\n", file_number); 
} 
void displayInodes(){ 
printf("Inode\tFile Number\tFile Size\tBlock Numbers\n"); 
for (int i = 0; i < MAX_FILES; i++) { 
if (inodes[i].file_number != -1) { 
printf("%d\t%d\t\t%d\t\t", i, inodes[i].file_number, inodes[i].file_size); for (int j = 0; j < 10; j++) { 
if (inodes[i].block_numbers[j] != -1) { 
printf("%d ", inodes[i].block_numbers[j]); 
} 
} 
printf("\n"); 
} 
} 
} 
int main(){ 
int choice; 
initializeInodes(); 
do { 
printf("\n-- Menu --\n"); 
printf("1. Allocate file\n"); 
printf("2. Deallocate file\n"); 
printf("3. Display inodes\n"); 
printf("4. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { case 1: { 
int file_number, file_size; 
printf("Enter the file number: "); 
scanf("%d", &file_number); 
printf("Enter the file size: "); 
scanf("%d", &file_size); 
allocateFile(file_number, file_size); 
break; 
} 
case 2: 
{ 

int file_number; 
printf("Enter the file number: "); 
scanf("%d", &file_number); 
deallocateFile(file_number); 
break; 
} 
case 3: { 
displayInodes(); 
break; 
} 
case 4:{ 
printf("Exiting the program.\n"); 
break; 
} 
default:{ 
printf("Invalid choice. Please try again.\n"); break; 
} 
} 
} while (choice != 4); 
printf("Name: Rajani Lamichhane\n"); 
printf("Roll No: 25796\n"); 
return 0; 
} 




