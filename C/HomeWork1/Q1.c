#include<stdio.h>
int main(){
    int arr[5] = {1,2,3,4,5};
    
     for(int i=0; i<5; i++){
        printf("%d\n",arr[i]);
    }
    int pos = 3;

    for(int i=5; i>=pos; i--){
        arr[i] = arr[i-1];
    }
    printf("\n");
    arr[2] = 21;
    for(int i=0; i<=5; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}