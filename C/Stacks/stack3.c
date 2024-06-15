#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    return stack[top--];
}

void convert(char str[])
{
    int len = strlen(str);
    char tmp[MAX];
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            char op2 = pop();
            char op1 = pop();
            //tmp[j++] = '(';
            tmp[j++] = op1;
            tmp[j++] = str[i];
            tmp[j++] = op2;
            //tmp[j++] = ')';
            push(tmp[j - 1]);
        }
        else
        {
            push(str[i]);
            tmp[j++] = str[i];
        }
    }

    tmp[j] = '\0';
    printf("The Infix Expression is: %s\n", tmp);
}

int main()
{
    char str[MAX];

    printf("Enter the Postfix Expression: ");
    scanf("%s", str);

    convert(str);

    return 0;
}

