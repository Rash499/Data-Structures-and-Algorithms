#include<stdio.h>

int main(){
    int arr[] = {250,150,350,200,300};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Initial array: ");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    printf("\nSorted array: ");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}