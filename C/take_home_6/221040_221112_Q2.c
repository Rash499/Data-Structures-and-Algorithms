#include<stdio.h>
#define MAX 4
int arr[MAX];
int arr2[MAX];
int top =-1;
void push(int n){
    top++;
    arr[top] = n;
}
void pop(){
    int i =0;
    arr2[i] = arr[top];
    top--; 
    printf("%d ",arr2[i]);
    i++;
}
int main(){
 
    push(1);
    push(2);
    push(3);
    push(4);
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Queue before reversing: \n");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\nQueue after reversing: \n");
    pop();
    pop();
    pop();
    pop();
    return 0;
}