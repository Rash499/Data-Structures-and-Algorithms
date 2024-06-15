#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    printf("Sum of the entered numbers: %d\n", sum);
    free(numbers);

    return 0;
}
