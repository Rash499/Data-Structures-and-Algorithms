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
    
    int max = 0;
    int secondmax = 0;

    for(int i=0;i<n;i++){
        if(numbers[i] > max){
            secondmax = max;
            max = numbers[i];
        }
        else if(numbers[i] > secondmax && numbers[i] != max){
            secondmax = numbers[i];
        }
    }
    if(secondmax != 0){
        printf("Second max = %d\n",secondmax);
    }
    else{
        printf("No Second max number!");
    }
    
    return 0;
}