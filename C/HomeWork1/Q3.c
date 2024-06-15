#include<stdio.h>
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i =0; i<10; i++){
        printf("%d\n",arr[i]);
    }
    int pos = 9;
    for(int i =pos-1; i<9; i++){
        arr[i] = arr[i+1]; 
    }
    printf("\n");
    for(int i=0; i<9; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}