#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Global Variable
char stack[50];
int top=-1;
//Function to Push Elements into Stack
void push(char item)
{
    stack[++top]=item;
}
//Function to Pop Element From The Stack
char pop()
{
    return stack[top--];
}
void reverseString(char* str)
{
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

//function to convert from postfix to infix
void convert(char str[])
{
    int l,i,j=0;
    char tmp[20];
    reverseString(str); //reverse the string
    l=strlen(str);
    for(i=0;i<50;i++){
        stack[i]='\0'; 
    }
    printf("The Infix Expression is: \n");
    for(i=0;i<l;i++){
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
            push(str[i]);
        else{
            tmp[j++]=str[i];
            tmp[j++]=pop();
        }
    }
    tmp[j]=str[top--];
    reverseString(tmp);
    puts(tmp);
}
//Main Function
int main()
{
    char str[50];
    //taking postfix expression
    printf("Enter the Postfix Expression: \n");
    gets(str);
    //calling the function to convert the expression
    convert(str);
    return 0;
}