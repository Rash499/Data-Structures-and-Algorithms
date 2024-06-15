#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    char name[10];
    int marks;
} data;

typedef struct {
    data stack[MAX];
    int top;
} stk;

void initialize(stk *p) {
    p->top = -1;
}

int isEmpty(stk *p) {
    return p->top == -1;
}

int isFull(stk *p) {
    return p->top == MAX - 1;
}

void push(stk *p, data element) {
    if (isFull(p)) {
        printf("Stack Overflow\n");
        return;
    }
    p->stack[++p->top] = element;
}

data pop(stk *p) {
    if (isEmpty(p)) {
        printf("Stack Underflow\n");
        data empty = {"", 0};
        return empty;
    }
    return p->stack[p->top--];
}

void displayStack(stk *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Content of the stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%s ", s->stack[i].name);
    }
}

int main() {
    stk stack;
    initialize(&stack);

    data students[MAX] = {
        {"Sanduni", 68},
        {"Kasun", 88},
        {"Vihaga", 90},
        {"Khushi", 50},
        {"Ravindi", 75}
    };

    for (int i = 0; i < MAX; i++) {
        if (students[i].marks > 70) {
            push(&stack, students[i]);
        }
    }

    displayStack(&stack);

    return 0;
}
