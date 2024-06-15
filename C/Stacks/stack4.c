#include<stdio.h>
#include<stdbool.h>
#define MAX 10
int top = -1;
int arr[MAX];
int stack[MAX];
bool isEmpty(){
    if(top <= -1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(){
    if(top == MAX -1){
        return true;
    }
    else{
        return false;
    }
}
int peek(){
    //int element;
    //stack[top];
    printf("Peek value is: %d\n",stack[top]);
}
void push(int data){
    if(isFull()){
        printf("Stack Overflow\n");
        return 0;
    }
    else{
        top = top + 1;
        stack[top] = data;
        printf("%d value push to the stack\n",data);
    }
    
}
int pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return 0;
    }
    else{
        int data = stack[top];
        top = top - 1;
        printf("%d value popped from the stack\n",data);
        return data; 
    }
    
}
void printStack(){
    for(int i=0; i<=top; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
    push(10);
    push(9);
    push(8);
    push(7);
    push(6);
    printStack();
    pop();
    pop();
    printStack();
    isEmpty();
    isFull();
    peek();
    return 0;
}