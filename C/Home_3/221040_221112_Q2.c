#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[5] = {20,40,4,55,30};
   
    int num;
    printf("Enter element to delete\n");
    scanf("%d",&num);//get user input
    for(int i =0; i<5; i++){
        if(arr[i]==num){ //loop through the array and find the number
            for(int j=i; j<5; j++){ //get the index
               arr[j] = arr[j+1];  //shift values backwords till the index match
            }
            printf("New array: ");
            for(int k=0; k<4; k++){
               printf("%d ",arr[k]);//print the new array
            } 
            break;//break out from the loop
        }
        
        
    }
    return 0;
}