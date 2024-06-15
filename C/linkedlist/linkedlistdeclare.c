#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;
    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 20;
    current->next = NULL;
    head->next = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 30;
    head->next->next = NULL;
    head->next->next = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 40;
    head->next->next->next = NULL;
    head->next->next->next = current;
    return 0;
    
}