#include <stdio.h>
#include <stdlib.h>

// Function to adjust the max heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

// Function to perform Heap Sort in descending order
void heapSortDescending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
    }
}

// Function to partition for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Use the leftmost element as the pivot
    int i = low;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            break;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

// Function to perform Quick Sort in descending order
void quickSortDescending(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortDescending(arr, low, pi - 1);
        quickSortDescending(arr, pi + 1, high);
    }
}

// Function to perform the custom sorting process
void customSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Perform Quick Sort on the left subarray
        quickSortDescending(arr, left, mid);

        // Perform Heap Sort on the right subarray
        heapSortDescending(arr + mid + 1, right - mid);

        // Merge the sorted subarrays
        customSort(arr, left, mid);
        customSort(arr, mid + 1, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {30, 4, 80, 75, 69, 43, 87, 90, 12, 67, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    // Perform the custom sorting process
    customSort(arr, 0, n - 1);

    printf("Sorted array in descending order:\n");
    //printArray(arr, n);
    for(int i=n-1; i>=0; i--){
        printf("%d ",arr[i]);
    }
    return 0;
}
