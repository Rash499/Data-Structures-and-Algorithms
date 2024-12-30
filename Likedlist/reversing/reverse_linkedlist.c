#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void reverse(struct node **head){
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void insert(struct node **head,int n){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->next = *head;
    *head = new_node;
}
void printList(struct node *head){
    struct node *node1 = head;
    while(node1 != NULL){
        printf("%d ",node1->data);
        node1 = node1->next;
    }
}
int main(){
    struct node *head = NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    printList(head);
    reverse(&head);
    printf("\n");
    printList(head);
    return 0;
}