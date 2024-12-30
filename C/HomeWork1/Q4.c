#include<stdio.h>
int main(){
    int arr[5] = {1,3,5,7,9};
    for(int i=0; i<5; i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
    int num = 5;
    for(int i = 0; i<5; i++ ){
        if(arr[i]>=num){
            for(int j=i; j<5; j++){
                arr[j] = arr[j+1];
            }
            break;
        }
      
    }
    for(int i=0;i<4;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}