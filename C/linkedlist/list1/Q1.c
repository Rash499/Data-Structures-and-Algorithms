#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;  
};
display (struct node *head1){ //create a function to display numbers
    if(head1==NULL){
        printf("NULL\n");
    }
    else{
        printf("%d\n",head1->data); //print node 1 data
        display(head1->next); //call function inside the same func..
                                //to get the next data from next node
    }
}
//create fuction to concatinate two lists set lists as parameters
void join(struct node *list1,struct node *list2){
    if(list1 != NULL && list2 != NULL){
        if(list1->next == NULL){
            list1->next = list2; //when the last address is null
        }                //join it to next list's first node
        else{
            join(list1->next,list2); //then call function again 
        }
    }
    else{
        printf("List1 or List2 is Empty");
    }
}
int main(){
    struct node *current, *list1, *list2, *head; //initialize the structure
    int n;
    printf("Enter the elemets of list1: ");
    scanf("%d",&n);
    list1 = NULL;
    for(int i =0;i<n;i++){
        head = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&head->data);//get the values of the first list
        head->next = NULL;
        if(list1==NULL){
            list1 = head;
        }
        else{
            current->next = head;//link numbers
        }
        current = head; //set the head to next node
    }
    printf("Enter the elemets of list2: ");
    scanf("%d",&n);
    list2 = NULL;
    for(int i =0;i<n;i++){
        head = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&head->data);
        head->next = NULL;
        if(list2==NULL){
            list2 = head;
        }
        else{
            current->next = head;
        }
        current = head;
    }
    join(list1,list2); //call the function give list1,list2 as arguments
    display(list1);
    return 0;
}