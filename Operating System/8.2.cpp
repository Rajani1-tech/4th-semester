#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_FILES 100

typedef struct Block {
    int block_number;
    struct Block* next;
} Block;

typedef struct File {
    int file_number;
    Block* start_block;
} File;

File files[MAX_FILES];

void initializeFiles() {
    for (int i = 0; i < MAX_FILES; i++) {
        files[i].file_number = -1;
        files[i].start_block = NULL;
    }
}

Block* createBlock(int block_number) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    new_block->block_number = block_number;
    new_block->next = NULL;
    return new_block;
}

void allocateFile(int file_number, int block_number) {
    if (files[file_number].file_number != -1) {
        printf("File %d already exists.\n", file_number);
        return;
    }

    Block* new_block = createBlock(block_number);
    files[file_number].file_number = file_number;
    files[file_number].start_block = new_block;
    printf("File %d allocated successfully.\n", file_number);
}

void deallocateFile(int file_number) {
    if (files[file_number].file_number == -1) {
        printf("File %d does not exist.\n", file_number);
        return;
    }

    Block* current_block = files[file_number].start_block;
    while (current_block != NULL) {
        Block* next_block = current_block->next;
        free(current_block);
        current_block = next_block;
    }

    files[file_number].file_number = -1;
    files[file_number].start_block = NULL;

    printf("File %d deallocated successfully.\n", file_number);
}

void displayFiles() {
    printf("File\tStart Block\tBlock Sequence\n");

    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].file_number != -1) {
            printf("%d\t%d\t\t", files[i].file_number, files[i].start_block->block_number);
            Block* current_block = files[i].start_block;

            while (current_block != NULL) {
                printf("%d ", current_block->block_number);
                current_block = current_block->next;
            }

            printf("\n");
        }
    }
}

int main() {
    int choice;
    initializeFiles();

    do {
        printf("\n-- Menu --\n");
        printf("1. Allocate file\n");
        printf("2. Deallocate file\n");
        printf("3. Display files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int file_number, block_number;
                printf("Enter the file number: ");
                scanf("%d", &file_number);
                printf("Enter the block number: ");
                scanf("%d", &block_number);
                allocateFile(file_number, block_number);
                break;
            }
            case 2:{ 
displayFiles(); 
break; 
} case 3:{ 
printf("Exiting the program.\n"); 
break; 
} 
default: { printf("Invalid choice. Please try again.\n"); 
break; 
} 
} 
} while (choice != 3); 
printf("Name: Rajani Lamichhane\n"); 
printf("Roll No: 25796\n"); 
return 0; 
} 


