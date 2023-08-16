#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 100

typedef struct {
    int page;
    int frequency;
    bool allocated;
} PageEntry;

void simulateLFU(int pages[], int n, int frames) {
    int page_faults = 0;
    PageEntry page_table[MAX_FRAMES];

    for (int i = 0; i < frames; i++) {
        page_table[i].page = -1;
        page_table[i].frequency = 0;
        page_table[i].allocated = false;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool page_found = false;

        for (int j = 0; j < frames; j++) {
            if (page_table[j].page == page) {
                page_table[j].frequency++;
                page_found = true;
                break;
            }
        }

        if (!page_found) {
            int min_frequency = page_table[0].frequency;
            int min_frequency_index = 0;

            for (int j = 1; j < frames; j++) {
                if (page_table[j].frequency < min_frequency) {
                    min_frequency = page_table[j].frequency;
                    min_frequency_index = j;
                }
            }

            page_table[min_frequency_index].page = page;
            page_table[min_frequency_index].frequency = 1;
            page_table[min_frequency_index].allocated = true;
            page_faults++;
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

    simulateLFU(pages, n, frames);

    return 0;
}

