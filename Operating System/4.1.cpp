#include <stdio.h>
#define MAX_FRAMES 100

int findPage(int pages[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (pages[i] == page) {
            return i;
        }
    }
    return -1;
}

void simulateFIFO(int pages[], int n, int frames) {
    int page_faults = 0;
    int page_index = 0;
    int page_table[MAX_FRAMES];

    for (int i = 0; i < frames; i++) {
        page_table[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int index = findPage(page_table, frames, page);

        if (index == -1) {
            page_table[page_index] = page;
            page_faults++;
            page_index = (page_index + 1) % frames;
        }
    }

    printf("Page Faults: %d\n", page_faults);
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

    printf("Name: Rajani Lamichhane\n");
    printf("Roll No: 25796\n");

    simulateFIFO(pages, n, frames);

    return 0;
}

