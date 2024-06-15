#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the size of the integer array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation for the integer array failed. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Original integer array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    printf("Enter the size of the character array: ");
    scanf("%d", &n);

    char *str = (char *)calloc(n, sizeof(char));

    if (str == NULL) {
        printf("Memory allocation for the character array failed. Exiting...\n");
        return 1;
    }

    printf("Enter a string (up to %d characters): ", n - 1);
    scanf(" %s", str);

    printf("Entered string: %s\n", str);

    free(str);

    return 0;
}
