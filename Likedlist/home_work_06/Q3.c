#include<stdio.h>
#include<stdlib.h>
// node structure
struct Node {
int data;
struct Node* prev;
struct Node* next;
};
struct Node* insertAtBegin(struct Node* last, int data); // inserts a node at the beginning
struct Node* insertAtEnd(struct Node* last, int data); // inserts a node at the end
struct Node* deleteAtBegin(struct Node* last); // deletes a node from the beginning
struct Node* deleteAtEnd(struct Node* last); // deletes a node from the end
void printList(struct Node *last){
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = last->next;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != last->next);
    printf("%d \n",temp->data);
}
int main() {
    struct Node* last = NULL;
    // insert nodes and print the circular doubly linked list
    last = insertAtBegin(last,5);
    last = insertAtBegin(last,3);
    last = insertAtBegin(last,6);
    last = insertAtEnd(last,11);
    printList(last);
    last = deleteAtBegin(last);
    last = deleteAtEnd(last);
    // print the circular doubly linked list after deletion
    printList(last);
    return 0;
}
struct Node *insertAtBegin(struct Node *last,int data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    if(last==NULL){
        last = newnode;
        last->next = last;
        last->prev = last;
    }
    else{
        newnode->next = last->next;
        newnode->prev = last;
        last->next->prev = newnode;
        last->next = newnode;
    }
    return last;  
}
struct Node *insertAtEnd(struct Node *last,int data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    
    if (last == NULL) {
        last = newnode;
        last->next = last;
        last->prev = last;
    } else {
        newnode->next = last->next;
        newnode->prev = last;
        last->next->prev = newnode;
        last->next = newnode;
        last = newnode;
    }
    return last;
}
struct Node *deleteAtBegin(struct Node *last){
    if(last == NULL) {
        printf("linkedlist is empty\n");
        return NULL;
    }
    struct Node *temp = last->next;

    if(temp == last){
        free(temp);
        return NULL;
    }
    last->next = temp->next;
    temp->next->prev = last;
    free(temp);
    return last;
}
struct Node* deleteAtEnd(struct Node* last) {
    if (last == NULL) {
        printf("Circular doubly linked list is empty, cannot delete.\n");
        return NULL;
    }

    if (last->next == last) {
        free(last);
        return NULL;
    }

    struct Node* temp = last;
    last->prev->next = last->next;
    last->next->prev = last->prev;
    last = last->prev;
    free(temp);
    return last;
}