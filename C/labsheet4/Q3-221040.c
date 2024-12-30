#include<stdio.h>
#include<string.h>
#define MAX 10
char* arr[MAX];
int count =0;
void check(char arr[]){
    for(int i=0;i<strlen(arr); i++){
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
                count = count + 1;
        }
    }
    printf("%d",count);
}
int main(){
    printf("Enter the string: ");
    fgets(arr,sizeof(arr),stdin);
    check(arr);
}