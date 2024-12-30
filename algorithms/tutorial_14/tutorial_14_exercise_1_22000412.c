#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int arr[], int n, int i) { //function to get the max heap
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

void heapSortDescending(int arr[], int n) { //heap sorting function
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
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

void quickSortDescending(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  //quicksorting function
        quickSortDescending(arr, low, pi - 1); //pass the arguments
        quickSortDescending(arr, pi + 1, high);
    }
}

void customSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        quickSortDescending(arr, left, mid);

        heapSortDescending(arr + mid + 1, right - mid);

        customSort(arr, left, mid); //merge two arrys
        customSort(arr, mid + 1, right);
        //quickSortDescending(arr, left, left);
    }
}

void printArray(int arr[], int size) { //print array
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {30, 4, 80, 75, 69, 43, 87, 90, 12, 67, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    customSort(arr, 0, n - 1);

    printf("Sorted array in descending order:\n");
    for(int i=n-1; i>=0; i--){ 
        printf("%d ",arr[i]);
    }
    return 0;
}
