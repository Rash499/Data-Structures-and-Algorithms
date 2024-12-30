#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    int numbers[n];
    printf("Enter numbers!\n");
    for(int i=0; i<n; i++){
        scanf("%d",&numbers[i]);
    }
    int min = numbers[0];
    int m;
    for(int i =0;i<n;i++){
        if(numbers[i] < min){
            min = numbers[i];
            m = i;
        }
        
    }
    printf("Minimum number position: %d",m);
    return 0;
}