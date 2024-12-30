#include<stdio.h>
#include<stdlib.h>
int main(){
   int n;
   int *arr;
   int total;
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
 
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<n; i++){
        total = total + arr[i];
    }
    printf("%d",total);
}