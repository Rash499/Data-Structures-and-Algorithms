#include<stdio.h>

int main(){
    int arr[] = {10,22,9,33,21,50,41,60,80};
    int size = sizeof(arr)/sizeof(arr[0]);
    int arr1[size];

    for(int i=0; i<size; i++){
        arr1[i] = 1; //initialize each element for 1
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && arr1[i] < arr1[j] + 1){
                arr1[i] = arr1[j] +1;
            }
        }
    }
    printf("Output: ");
    for(int i=0; i<size; i++){
        printf("%d ",arr1[i]);
    }
    return 0;
}