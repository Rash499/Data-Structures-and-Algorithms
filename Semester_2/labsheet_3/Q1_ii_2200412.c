#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Original array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int newSize = 2 * n;
    int *resizedArr = (int *)realloc(arr, newSize * sizeof(int));

    if (resizedArr == NULL) {
        printf("Memory reallocation failed. Exiting...\n");
        free(arr); 
        return 1;
    }

    for (int i = n; i < newSize; i++) {
        resizedArr[i] = i + 1;
    }
    printf("Modified array elements: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", resizedArr[i]);
    }
    printf("\n");

    free(resizedArr);

    return 0;
}
