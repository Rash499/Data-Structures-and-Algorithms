#include<stdio.h>
int main(){
    int arr1[5] ={2,3,5,7,6};
    int arr2[5] ={45,6,7,98,43};
    int arr3[20];
    for(int i =0; i<5; i++){
        arr3[i]=arr1[i];
    }
    for(int i =0; i<5; i++){
        arr3[i+5]=arr2[i];
    }
    for(int i=0; i<10; i++){
        printf("%d\n",arr3[i]);
    }
    return 0;
    
}