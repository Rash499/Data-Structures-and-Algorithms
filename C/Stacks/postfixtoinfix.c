#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack data structure
struct Stack {
    char data[MAX_SIZE][MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, const char* item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->top++;
    strcpy(stack->data[stack->top], item);
}

// Function to pop an element from the stack
void pop(struct Stack* stack, char* item) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    strcpy(item, stack->data[stack->top]);
    stack->top--;
}

// Function to check if a character is an operand
bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

// Function to convert a postfix expression to infix
void postfixToInfix(const char* postfix, char* infix) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(postfix);
    for (int i = 0; i < length; i++) {
        if (isOperand(postfix[i])) {
            char operand[2] = { postfix[i], '\0' };
            push(&stack, operand);
        } else {
            char op1[MAX_SIZE], op2[MAX_SIZE];
            pop(&stack, op1);
            pop(&stack, op2);

            char temp[MAX_SIZE];
            snprintf(temp, sizeof(temp), "(%s%c%s)", op2, postfix[i], op1);
            push(&stack, temp);
        }
    }

    pop(&stack, infix);
}

int main() {
    const char* postfix = "ab*c+";
    char infix[MAX_SIZE];
    postfixToInfix(postfix, infix);
    printf("Postfix: %s\n", postfix);
    printf("Infix: %s\n", infix);
    return 0;
}
