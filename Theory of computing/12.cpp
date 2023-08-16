#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input

    if (strstr(str, "aba") != NULL) {
        printf("The string contains 'aba'\n");
    } else {
        printf("The string does not contain 'aba'\n");
    }

    return 0;
}

