#include<stdio.h>
#include<stdlib.h>
// node structure
struct Node {
 int data;
 struct Node* next;
};
struct Node *head = NULL;
struct Node *temp = NULL;
 // sorts the linked list
void sort(struct Node* head,struct Node **temp){
    if(*temp == NULL || (*temp)->data >= head->data){
        head->data = *temp;
        *temp = head;
    }
    else{
        struct Node *current = *temp;
        while (current->next != NULL
               && current->next->data < head->data) {
            current = current->next;
        }
        head->next = current->next;
        current->next = head;
    }
}
struct Node* sortLinkedList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        sort(current, &temp);
        current = next;
    }
    return temp;
}
struct Node* deleteLinkedList(struct Node* head){

} // deletes the entire linked list
int main() {
    // your code here to create a linked list and add some elements
    int n;
    struct Node *p,*head;
    printf("Enter the number of elements in the list: ");
    scanf("%d ",&n);
    for(int i=0; i<n; i++){
        if(i==0){
             head = (struct Node*)malloc(sizeof(struct Node));
             p = head;
        }
        else{
            p->next = (struct Node*)malloc(sizeof(struct Node));
            p = p->next;
        }
        scanf("%d",&p->data);
    }
    p->next =NULL;
   // head = sortLinkedList(head);
    head = sortLinkedList(head);
    // your code here to print the sorted linked list
    int count =1;
    while (head != NULL){
        printf("NODE %d: %d \n",count,head->data);
        count++;
        head = head->next;
    }
    head = deleteLinkedList(head);
    // Check if the list is empty
    if(head == NULL) {
    printf("Linked list is deleted.\n");
    }
  return 0;
}