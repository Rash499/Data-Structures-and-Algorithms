#include<stdio.h>
#include<stdlib.h> //memory allocation
int main(){
   int n;
   int *arr;
   int total;
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));//memory dynamically allocated for array arr
    //set the size
 
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);//loop and read values of the elements
    }
    for(int i=0; i<n; i++){
        total = total + arr[i];
    }
    printf("%d",total);
}