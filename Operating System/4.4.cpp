#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 100

typedef struct {
    int page;
    bool referenced;
} PageEntry;

void simulateSecondChance(int pages[], int n, int frames) {
    int page_faults = 0;
    PageEntry page_table[MAX_FRAMES];

    for (int i = 0; i < frames; i++) {
        page_table[i].page = -1;
        page_table[i].referenced = false;
    }

    int page_index = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool page_found = false;

        for (int j = 0; j < frames; j++) {
            if (page_table[j].page == page) {
                page_table[j].referenced = true;
                page_found = true;
                break;
            }
        }

        if (!page_found) {
            while (1) {
                PageEntry *current_page = &page_table[page_index];

                if (!current_page->referenced) {
                    current_page->page = page;
                    current_page->referenced = true;
                    page_faults++;
                    page_index = (page_index + 1) % frames;
                    break;
                } else {
                    current_page->referenced = false;
                    page_index = (page_index + 1) % frames;
                }
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

    simulateSecondChance(pages, n, frames);

    return 0;
}

