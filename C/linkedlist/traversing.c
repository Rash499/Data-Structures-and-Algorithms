#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void count_of_nodes(struct node *head){
    int count = 0;
    if(head == NULL){
        printf("Linkedlist is empty\n");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    } 
    printf("Number of nodes: %d\n",count);
}
void print_data(struct node *head){
    if(head == NULL){
        printf("Link list is empty\n");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    //head->next = NULL;
    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 20;
    //current->next = NULL;
    head->next = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 30;
    //head->next->next = NULL;
    head->next->next = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 40;
    //head->next->next->next = NULL;
    head->next->next->next = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 50;
    head->next->next->next->next =NULL;
    //head->next->next->next->next = current;

    count_of_nodes(head);
    print_data(head);
    return 0;
}