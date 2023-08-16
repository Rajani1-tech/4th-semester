#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input

    if (strncmp(str, "abb", 3) == 0) {
        printf("The string starts with 'abb'\n");
    } else {
        printf("The string does not start with 'abb'\n");
    }

    return 0;
}

