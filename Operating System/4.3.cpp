#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 100

int findPage(int pages[], int n, int page, int start) {
    for (int i = start; i >= 0; i--) {
        if (pages[i] == page) {
            return i;
        }
    }
    return -1;
}

void simulateLRU(int pages[], int n, int frames) {
    int page_faults = 0;
    int page_table[MAX_FRAMES];
    int counter[MAX_FRAMES];

    for (int i = 0; i < frames; i++) {
        page_table[i] = -1;
        counter[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;

        for (int j = 0; j < frames; j++) {
            if (page_table[j] == page) {
                counter[j] = i + 1;
                found = true;
                break;
            }
        }

        if (!found) {
            int index = 0;
            int least_recently_used = counter[0];

            for (int j = 1; j < frames; j++) {
                if (counter[j] < least_recently_used) {
                    least_recently_used = counter[j];
                    index = j;
                }
            }

            page_table[index] = page;
            counter[index] = i + 1;
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

    simulateLRU(pages, n, frames);

    return 0;
}

