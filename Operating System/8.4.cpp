#include <stdio.h>
#include <stdbool.h>

#define MAX_FILES 100

typedef struct {
    int file_number;
    int start_block;
    int end_block;
    bool allocated;
} FileEntry;

FileEntry file_table[MAX_FILES];

void initializeFileTable() {
    for (int i = 0; i < MAX_FILES; i++) {
        file_table[i].file_number = -1;
        file_table[i].start_block = -1;
        file_table[i].end_block = -1;
        file_table[i].allocated = false;
    }
}

int findEmptyEntry() {
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_table[i].file_number == -1)
            return i;
    }
    return -1; // No empty entry found
}

void allocateFile(int file_number, int start_block, int end_block) {
    if (file_table[file_number].file_number != -1) {
        printf("File %d already exists.\n", file_number);
        return;
    }

    for (int i = start_block; i <= end_block; i++) {
        if (file_table[i].allocated) {
            printf("Block %d is already allocated.\n", i);
            return;
        }
    }

    // Check if block numbers are valid
    if (start_block < 0 || start_block >= MAX_FILES || end_block < 0 || end_block >= MAX_FILES) {
        printf("Invalid block number(s).\n");
        return;
    }

    int empty_entry = findEmptyEntry();
    if (empty_entry == -1) {
        printf("File allocation table is full.\n");
        return;
    }

    for (int i = start_block; i <= end_block; i++) {
        file_table[i].file_number = file_number;
        file_table[i].allocated = true;

        if (i == start_block)
            file_table[i].start_block = start_block;
        if (i == end_block)
            file_table[i].end_block = end_block;
    }

    printf("File %d allocated successfully.\n", file_number);
}

void deallocateFile(int file_number) {
    if (file_table[file_number].file_number == -1) {
        printf("File %d does not exist.\n", file_number);
        return;
    }

    for (int i = file_table[file_number].start_block; i <= file_table[file_number].end_block; i++) {
        file_table[i].file_number = -1;
        file_table[i].start_block = -1;
        file_table[i].end_block = -1;
        file_table[i].allocated = false;
    }

    printf("File %d deallocated successfully.\n", file_number);
}

void displayFileTable() {
    printf("File\tStart Block\tEnd Block\n");

    for (int i = 0; i < MAX_FILES; i++) {
        if (file_table[i].file_number != -1) {
            printf("%d\t%d\t\t%d\n", file_table[i].file_number, file_table[i].start_block, file_table[i].end_block);
        }
    }
}

int main(){ 
int choice; 
initializeFileTable(); 
do { 
printf("\n-- Menu --\n"); 
printf("1. Allocate file\n"); 
printf("2. Deallocate file\n"); 
printf("3. Display file table\n"); 
printf("4. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1:{ 
int file_number, start_block, end_block; 
printf("Enter the file number: "); 
scanf("%d", &file_number); 

printf("Enter the starting block: "); 
scanf("%d", &start_block); 
printf("Enter the ending block: "); 
scanf("%d", &end_block); 
allocateFile(file_number, start_block, end_block); break; 
} case 2: { 
int file_number; 
printf("Enter the file number: "); 
scanf("%d", &file_number); 
deallocateFile(file_number); 
break; 
}case 3: { 
displayFileTable(); 
break; 
} case 4: { 
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


