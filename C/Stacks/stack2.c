#include<stdio.h>
#define MAX 50
char str[MAX];
char stack[MAX];
int top = -1;
int size_str;

void push(char item){
    top = top + 1;
    stack[top] = item;
}
char pop(){
    char item = stack[top];
    top = top - 1;
    return item;
}


int main(){
    printf("Enter the expression: \n");
    scanf("%s",&str);
    size_str = sizeof(str)/sizeof(str[0]);
    for(int i =0; i<size_str; i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
                push(str[i]);
        }
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')'){
            if(top == -1){
                printf("Unbalanced\n");
                return 0;
            }
            char new_item = pop();
        }
       
    }
    if(top == -1){
        printf("balanced");
    }
    else{
        printf("unbalanced");
    }
 
    return 0;
}