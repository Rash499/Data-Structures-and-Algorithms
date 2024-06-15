#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *sort = NULL;
void add(int element){
    //memory allocate
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element; //link list to new node
    newnode->next = head; //move the head to point newnode
    head = newnode;
}
void sortedinsert(struct node *newnode){
    if(sort == NULL || sort->data == newnode->data){
        newnode->next = sort;
        sort = newnode;
    }
    else{ //Locate the node before the point of insertion
        struct node *current = sort;
        	while (current->next != NULL
			&& current->next->data < newnode->data) {
			current = current->next;
		}
		newnode->next = current->next;
		current->next = newnode;
	}

}
void insertionsort(){
    struct node* current = head;
    while(current != NULL){
        //store next for next iteration
        struct node* next = current->next;
        sortedinsert(current); //set current 
        current = next; //update the current pointer
    }
    head = sort;// Update head to point to sorted linked list
}
void printlist(struct node *head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main(){
    add(12);
    add(23);
    add(11);
    add(3);
    printf("Linkedlist before: ");
    printlist(head);
    printf("\n");

    insertionsort(head);

    printf("Linkedlist after: ");
    printlist(head);
    printf("\n");
    return 0;

}