#include<stdio.h>

int main(){
    int arr[] = {54, 28, 64, 22, 11,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<size; i++){
        if(arr[i] < arr[i+1]){
            for(int j=0; j<size-i-1; j++){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}