#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 100

int findPage(int pages[], int n, int page, int start) {
    for (int i = start; i < n; i++) {
        if (pages[i] == page) {
            return i;
        }
    }
    return -1;
}

void simulateOptimal(int pages[], int n, int frames) {
    int page_faults = 0;
    int page_table[MAX_FRAMES];
    bool page_present[MAX_FRAMES];
    
    for (int i = 0; i < frames; i++) {
        page_table[i] = -1;
        page_present[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        
        if (page_present[page] == false) {
            page_faults++;
            
            if (i < frames) {
                page_table[i] = page;
                page_present[page] = true;
            }
            else {
                int index = -1;
                int farthest = i;
                
                for (int j = 0; j < frames; j++) {
                    int next = findPage(pages, n, page_table[j], i + 1);
                    
                    if (next == -1) {
                        index = j;
                        break;
                    }
                    if (next > farthest) {
                        farthest = next;
                        index = j;
                    }
                }
                
                page_table[index] = page;
                page_present[page] = true;
            }
        }
    }

    printf("Page Faults: %d\n", page_faults);
    printf("Name: Rajani Lamichhane\n");
    printf("Roll No: 25796\n");
}

int main() {
    int n;
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[MAX_FRAMES];
    printf("Enter the page sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int frames;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    simulateOptimal(pages, n, frames);

    return 0;
}

