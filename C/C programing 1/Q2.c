#include<stdio.h>
int main(){
    printf("Input the number of elements tostore in the array : ");
    int n;
    scanf("%d",&n);
    int numbers[n];
    int numbers_copy[n];
    printf("Input %d number of elements in the array : \n",n);
    for(int i = 0; i<n; i++){
        printf("element - %d : ",i);
        scanf("%d",&numbers[i]);
    }
   
    for(int i = 0; i<n; i++){
        numbers_copy[i] = numbers[i];
    }
    printf("The values store in the first array are: \n");
    for(int i = 0; i<n; i++){
        printf("  %d  ",numbers[i]);
    }
    printf("\n");
    printf("The values store in the second array are: \n");
    for(int i = 0; i<n; i++){
        printf("  %d  ",numbers_copy[i]);
    }
}