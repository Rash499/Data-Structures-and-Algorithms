#include <stdio.h>


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Choose the middle element as the pivot
        int pivot = arr[(low + high) / 2];

        // Partition the array into two sub-arrays
        int i = low, j = high;
        while (i <= j) {
            while (arr[i] > pivot)
                i++;
            while (arr[j] < pivot)
                j--;
            if (i <= j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }

        // Recursively sort the sub-arrays
        quickSort(arr, low, j);
        quickSort(arr, i, high);
    }
}

int main() {
    int arr[] = {30, 4, 89, 75, 69, 43, 87, 90, 12, 67, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform Quick Sort with Heap Sort
    quickSort(arr, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
    heapSort(arr, n);

    // Print the sorted array in descending order
    printf("Sorted array in descending order:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);

    return 0;
}