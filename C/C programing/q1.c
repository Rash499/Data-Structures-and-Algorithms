#include<stdio.h>
int main(){
    int n;
    int total = 0;
    int mean = 0;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    int numbers[n];
    printf("Enter numbers!\n");
    for(int i=0; i<n; i++){
        scanf("%d",&numbers[i]);
        total = total + numbers[i];
    }
    //printf("%d",total);

    mean = total/n;
    printf("Mean of the n numbers: %d\n",mean);
    return 0;

}