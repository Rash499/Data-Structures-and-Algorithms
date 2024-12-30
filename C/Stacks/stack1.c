#include<stdio.h>
#define MAX 50
char* name[MAX];
char stack[MAX];
char arr[MAX];
int top = -1;
int size;

void Push(char item){
    top = top + 1;
    stack[top] = item;
    
}
char Pop(){
    char item = stack[top];
    top = top -1;
    return item;

}
int main(){
    printf("Enter a string: \n");
    scanf("%s",&name);
    size = sizeof(name)/sizeof(name[0]);
    for(int i =0; i<size; i++){
        Push(name[i]);
    }
    for(int i =0; i<size; i++){
        arr[i] = Pop();
    }
    
    printf("New string: \n");
    for(int i =0; i<size; i++){
        printf("%c",arr[i]);
    }

}