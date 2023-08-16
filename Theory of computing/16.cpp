#include <stdio.h>

int main() {
    int state = 0;
    char c;
    int count = 0;

    printf("Enter a string: ");

    while ((c = getchar()) != '\n' && c != EOF) {
        count++;
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
                    state = 2;
                } else {
                    state = 0;
                }
                break;
            case 2:
                if (c == 'a') {
                    state = 0;
                } else {
                    state = 1;
                }
                break;
        }
    }

    if (count > 0 && state == 0) {
        printf("The length of the string is divisible by 3\n");
    } else {
        printf("The length of the string is not divisible by 3\n");
    }

    return 0;
}

