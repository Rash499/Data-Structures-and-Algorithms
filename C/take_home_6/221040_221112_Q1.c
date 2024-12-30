#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int front = -1;
int rear = -1;
int n;
/*
bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(){
    if(rear == MAX - 1){
        return true;
    }
} */
void enqueue(int num){
    char binary[100][100];
    front =0;
    rear = 0;
    strcpy(binary[rear++], "1");
    while(num>0 && front < rear){
        char* current = binary[front++];
        printf("%s ",current);
        char next[100];
        strcpy(next, current);
        strcat(next, "0");
        strcpy(binary[rear++], next);
        strcpy(next, current);
        strcat(next, "1");
        strcpy(binary[rear++], next);
        num--;
    }
}

int main(){
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Binary numbers between 0 and %d are: ", n);
    enqueue(n);
    printf("\n");
    return 0;
}