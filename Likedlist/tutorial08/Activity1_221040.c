#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void printList(struct node *head){
    struct node *current = head;
    while(current != NULL){
        printf("Data = %d\n",current->data);
        current= current->next;
    }
}
void insertEnd(int data){
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    if(head==NULL){
        head = newnode;
    }
    else{
        struct node *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next= newnode;
    }

}
int main(){
    int n;
    printf("input the number of node: ");
    scanf("%d",&n);
    struct node *head = NULL;
    for(int i=0; i<n; i++){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Input data for node %d: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
        } 
        else{
            struct node *current = head;
            while(current->next != NULL){
                current =current->next;
            }
            current->next =newnode;
        }
    }
   // struct node *current = head;
   // while(current != NULL){
    //    printf("Data = %d\n",current->data);
    //    current= current->next;
    //}
    printList(head);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("input data to insert at the end of the list: ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    if(head==NULL){
        head = newnode;
    }
    else{
        struct node *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next= newnode;
        newnode->next= NULL;
    }
    printf("Data after inserted in the list are\n");
    printList(head);
    //struct node *current = head;
   // while(current != NULL){
   //     printf("Data = %d\n",current->data);
   //     current= current->next;
   // }
    return 0;
}