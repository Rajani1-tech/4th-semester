#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input

    int len = strlen(str);
    if (len >= 4 && str[len-1] == 'a' && str[len-2] == 'a' && str[len-3] == 'a' && str[len-4] == 'a') {
        printf("The string ends with 4 consecutive 'a's\n");
    } else {
        printf("The string does not end with 4 consecutive 'a's\n");
    }

    return 0;
}

