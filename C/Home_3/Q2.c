#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[5] = {20,40,4,55,30};
   
    int num;
    bool valid = false;
    printf("Enter element to delete\n");
    scanf("%d",&num);
    for(int i =0; i<5; i++){
        if(arr[i]==num){
            for(int j=i; j<5; j++){
               arr[j] = arr[j+1];  
            }
            break;
        } 
        else{
            printf("Enter a valid number!\n");
            break;
            valid = true;
        }
    }
    
    if(valid == true){
         printf("New array: ");
    for(int i=0; i<4; i++){
        printf("%d ",arr[i]);
        }
    }
   
    return 0;
}