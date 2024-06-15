#include<stdio.h>
int main(){
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,10};
    int arr3[5] = {11,12,13,14,15};
    int arr[20];
    
    for(int j=0; j<5; j++){
            arr[j] = arr1[j];
            arr[j+5] = arr2[j];
            arr[j+10] =arr3[j];
    }
    for(int i =0; i<15; i++){
        printf("%d\n",arr[i]);
    }
    
    return 0;
}