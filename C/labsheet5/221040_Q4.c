#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[10] = {1,2,3,3,44,53,53,53,1,8};
    int arr2[10];
    int temp;
    bool check;
    int count = 0;
    for(int i=0; i<10; i++){
        check = true;
        for(int j=0; j<i; j++){
            if(arr[i]==arr[j]){
                check = false;
                break;               
            }  
        }
        if(check){
            arr2[count] = arr[i];
            count++;
        }
    }
    printf("count: %d\n",count);
    for(int i=0;i<count; i++){
        printf("%d ",arr2[i]);
    }
    return 0;
}