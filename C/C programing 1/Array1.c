#include<stdio.h>
#define MAX 5
int main(){
    int arr[MAX] = {11,22,33,4,5};
    /*arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;*/
    for(int i =0; i<MAX; i++){
        printf("%d\n",arr[i]);
    }
}