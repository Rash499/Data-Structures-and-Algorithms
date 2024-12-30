
#include <stdio.h>
#define MAX 20
int cot = 0;
int calculateNegativeSum(int arr[], int size){
    int count =0;
    for(int i=0; i<size; i++){
        if(arr[i] < 0){
            count=count + arr[i];
        }
    }
    return count;
}
int countPositiveAboveThreshold(int arr[], int size, int threshold){
    int count= 0;
    for(int i=0; i<size; i++){
        if(arr[i] > threshold){
            count++;
        }
    }
    return count;
}
 int removeZeros(int arr[], int size){
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i; j++){
            if(arr[j] == 0){
            arr[j] = arr[j+1];
            cot++;
        }   
        }
    }

 }
int main(){
    int n;
    int thres;
    
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the threshold value: ");
    scanf("%d",&thres);
    printf("sum of negative values: %d\n",calculateNegativeSum(arr,n));
    printf("Number of positive values above threshold: %d\n",countPositiveAboveThreshold(arr,n,thres));

    removeZeros(arr,n);
    int size1 = sizeof(arr)/sizeof(arr[0]);
    printf("Array after removing zeros: ");
    for(int i=0; i<n-cot; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}