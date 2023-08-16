#include <stdio.h>
#include <stdbool.h>
#define MAX_BLOCKS 100

bool disk[MAX_BLOCKS] = {false};

void allocateFile(int start_block, int end_block) {
    bool can_allocate = true;

    for (int i = start_block; i <= end_block; i++) {
        if (disk[i]) {
            can_allocate = false;
            break;
        }
    }

    if (can_allocate) {
        for (int i = start_block; i <= end_block; i++) {
            disk[i] = true;
        }
        printf("File allocated successfully.\n");
    } else {
        printf("File allocation failed. Some blocks are already allocated.\n");
    }
}

void deallocateFile(int start_block, int end_block) {
    for (int i = start_block; i <= end_block; i++) {
        disk[i] = false;
    }
    printf("File deallocated successfully.\n");
}

void displayDiskStatus(int disk_size) {
    printf("Disk Status:\n");
    printf("Block\tAllocated\n");

    for (int i = 0; i < disk_size; i++) {
        printf("%-4d\t%s\n", i, disk[i] ? "Yes" : "No");
    }
}

int main() {
    int disk_size;
    printf("Enter the size of the disk: ");
    scanf("%d", &disk_size);

    int choice;
    do {
        printf("\n-- Menu --\n");
        printf("1. Allocate file\n");
        printf("2. Deallocate file\n");
        printf("3. Display disk status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int start_block, end_block;
                printf("Enter the starting block number: ");
                scanf("%d", &start_block);
                printf("Enter the ending block number: ");
                scanf("%d", &end_block);
                allocateFile(start_block, end_block);
                break;
            }
            case 2: {
                int start_block, end_block;
                printf("Enter the starting block number: ");
                scanf("%d", &start_block);
                printf("Enter the ending block number: ");
                scanf("%d", &end_block);
                deallocateFile(start_block, end_block);
                break;
            }
            case 3: {
                displayDiskStatus(disk_size);
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
    return 0;
}

