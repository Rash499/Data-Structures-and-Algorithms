#include<stdio.h>
#include<stdlib.h>
struct node1{
    int data;
    struct node1 *next;
};
struct node2{
    int data2;
    struct node2 *next2;
};
struct node1 *head,*current =NULL;
struct node2 *head2,*current2 =NULL;
void addDataToLinkedlist1(int element){
    struct node1 *new_node = (struct node1*)malloc(sizeof(struct node1));
    new_node->data = element;
    new_node->next = NULL;
    if(head == NULL ){
        head = new_node;
        current = new_node;
    }
    else{
        current->next = new_node;
        current = new_node;
    }
}
void addDataToLinkedlist2(int element){
    struct node2 *new_node2 = (struct node2*)malloc(sizeof(struct node2));
    new_node2->data2 = element;
    new_node2->next2 = NULL;
    if(head2 == NULL ){
        head2 = new_node2;
        current2 = new_node2;
    }
    else{
        current2->next2 = new_node2;
        current2 = new_node2;
    }
}
void concatenate(struct node1 *l1,struct node2 *l2){
    if(l1->next == NULL){
        l1->next = l2;
    }
    else{
        concatenate(l1->next,l2);
    }
}
void DisplayLinkedlit1(){
    struct node1 *current1 = head;
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }
    printf("Displaying Linkedlist 1 data\n");
    while(current1 != NULL){
        printf("%d ",current1->data);
        current1 = current1->next;
    }
    printf("\n");
}
void DisplayLinkedlist2(){
    struct node2 *current2 = head2;
    if(head2 == NULL) {  
        printf("List is empty\n");  
        return;  
    }
    printf("Displaying Linkedlist 2 data\n");
    while(current2 != NULL){
        printf("%d ",current2->data2);
        current2 = current2->next2;
    }
    printf("\n");
}
int main(){
    addDataToLinkedlist1(10);
    addDataToLinkedlist1(20);
    addDataToLinkedlist1(30);
    DisplayLinkedlit1();
    addDataToLinkedlist2(100);
    addDataToLinkedlist2(200);
    addDataToLinkedlist2(300);
    DisplayLinkedlist2();
    //concatenate(*l1,l2);
    return 0;
}