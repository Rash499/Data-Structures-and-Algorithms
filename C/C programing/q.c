#include<stdio.h>
int main(){
    printf("Enter the size of array: \n");
    int n;
    int total = 0;
    float mean;
    scanf("%d",&n);
    int numbers[n];
    printf("Enter numbers!\n");
    for(int i=0; i<n; i++){
        scanf("%d",&numbers[i]);
        total = total + numbers[i];
    }

    mean = (float)total/(float)n;
    printf("Mean of the n numbers: %.3f\n",mean);
    return 0;

}