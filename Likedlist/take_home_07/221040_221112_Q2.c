#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Train {
    int trainId;
    char destination[50];
    struct Train* next;
} Train;
void addtrain(Train **head,int id,const char* destination){
    Train *newnode = (Train*)malloc(sizeof(Train));
    newnode->trainId = id;
    strncpy(newnode->destination, destination, sizeof(newnode->destination) - 1);
    newnode->destination[sizeof(newnode->destination) - 1] = '\0';
    newnode->next = NULL;
    if(*head==NULL){
        *head = newnode;
    }
    else{
        Train *temp = *head;
        while(temp->next != NULL ){
            temp = temp->next;
        }
        temp->next = newnode; //add in the start position
    }
      printf("Adding train: ID = %d, Destination = '%s'\n", id, destination);
}
Train *removetrain(Train **head){
    if (*head == NULL) {
        printf("No trains in the schedule. Departure not possible.\n");
        return NULL;
    }
    Train *remove = *head;
    *head = (*head)->next; //remove the node from the list
     printf("Remove train: ID = %d, Destination = '%s'\n", remove->trainId, remove->destination);

    return remove; //return the pointer
}
Train *nextTrain(Train *head){
    if (head == NULL) {
        printf("No trains in the schedule.\n");
        return NULL;
    }
    printf("The next train is: ID = %d, Destination = '%s'\n",head->trainId,head->destination);
    return head; //return the first node
}
void print(Train *head){
    Train *temp = head;
    while(temp != NULL){
        printf("%d(%s) -> ",temp->trainId,temp->destination);
        temp=temp->next;
    }
    printf("Empty\n");
}
void freelist(Train *head){
    Train *temp = head;
    while(temp != NULL){
        Train *current = temp;
        current = current->next;
        free(current);
    }
}
int main(){
    Train *head = NULL;
    addtrain(&head,101,"New york");
    addtrain(&head,102,"Los Angeles");
    addtrain(&head,103,"Chicago");
    print(head);
    removetrain(&head);
    print(head);
    nextTrain(head);
    return 0;
}
