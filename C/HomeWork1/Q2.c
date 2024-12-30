#include<stdio.h>
int main(){
    int arr[5] = {1,3,5,7,9};

    for(int i =0; i<5; i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
    int num = 8;
    for(int i =0; i<5; i++){

        if(arr[i]>=num){
            
            for(int j=5; j>=i; j--){
                arr[j] =arr[j-1];
            }
            arr[i]=num;
            break;
        }
        else{
            arr[i+5] = num;
        }
      
    }
    
    for(int i =0; i<=5; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}