#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char input;
    struct node *next;
    struct node *prev;
};
struct node *createList(char input){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->input = input;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void insert(struct node **head,char input){

    struct node *newnode = createList(input); //set the node
    if(*head == NULL){ //check head is null
        *head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else{
        struct node *end = (*head)->prev;
        end->next = newnode; //set the nodes and asign the address
        newnode->prev = end;
        newnode->next = *head;
        (*head)->prev = newnode;
    }
}
int checkMirrored(struct node *head,int size){
    struct node *start = head; //set start and end
    struct node *end = head->prev; 
    for(int i=0; i<(size/2); i++){
        if (start->input != end->input) {
            return 0; //if condition true return
        }
        start = start->next; 
        end = end->prev;
    }
    return 1;
}

int main(){
    char name[10];
    printf("Input word: ");//take user input
    scanf("%s",&name);

    struct node *head =NULL;
    for(int i=0; i<strlen(name); i++){
        insert(&head,name[i]); //store in the list
    }
    if(checkMirrored(head ,strlen(name))){
        printf("Output: 'Mirrored'\n");
    }
    else{
        printf("Output: 'Not Mirrored'\n");
    }
    return 0;
}