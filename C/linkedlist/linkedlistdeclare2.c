#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
void count_nodes(struct node *head){
    int count =0;
    if(head == NULL){
        printf("Linkedlist is empty\n");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("Count of nodes: %d\n",count);
}
void print_data(struct node *head){
    if(head == NULL){
        printf("Linkedlist is full");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d \n",ptr->data);
        ptr = ptr->link;
    }
}
int main(){
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));

    one->data = 10;
    two->data = 20;
    three->data =30;

    one->link = two;
    two->link = three;
    three->link = NULL;
    count_nodes(one);
    print_data(one);
    return 0;
}