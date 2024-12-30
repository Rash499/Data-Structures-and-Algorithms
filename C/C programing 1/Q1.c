#include<stdio.h>
int main(){
    printf("Input the number of elements tostore in the array : ");
    int n;
    scanf("%d",&n);
    int numbers[n];
    printf("Input %d number of elements in the array : \n",n);
    for(int i = 0; i<n; i++){
        printf("element - %d : ",i);
        scanf("%d",&numbers[i]);
    }
    printf("The values store into the array are: \n");
    for(int i = 0; i<n; i++){
        printf("  %d  ",numbers[i]);
    }
    printf("\n");
    printf("The values store into the array in reverse are: \n");
    for(int i = n-1; i>=0; i--){
        printf("  %d  ",numbers[i]);
    }
    return 0;
}