#include <stdio.h>

int main() {
    int state = 0;
    char c;

    printf("Enter a string: ");

    while ((c = getchar()) != '\n' && c != EOF) {
        switch(state) {
            case 0:
                if (c == 'a') {
                    state = 1;
                } else {
                    state = 0;
                }
                break;
            case 1:
                if (c == 'a') {
                    state = 0;
                } else {
                    state = 1;
                }
                break;
        }
    }

    if (state == 0) {
        printf("The string contains an even number of 'a's\n");
    } else {
        printf("The string contains an odd number of 'a's\n");
    }

    return 0;
}

