#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the size of the character array: ");
    scanf("%d", &n);

    char *str = (char *)calloc(n, sizeof(char));

    if (str == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Enter a string (up to %d characters): ", n - 1);
    scanf(" %s", str);

    printf("Entered string: %s\n", str);
    free(str);

    return 0;
}
