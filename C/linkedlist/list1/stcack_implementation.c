// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;

void push(int n){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Stack underflow");
    }
    else{
        if(head==NULL)  
        {         
            ptr->data = n;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->data = n;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("%d  pushed to stack\n",n);  
    }
}
void pop(){
    int item;
    struct node *ptr;
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
       item = head->data;
       ptr = head;
       head =head->next;
       free(ptr);
       printf("Item poped\n");
    }
}
void peek(){
    if(head == NULL){
        printf("Underflow\n");
    }
    else{
       printf("%d\n",head->data);
    }
}
int main(){
   
    push(2);
    push(25);
    push(36);
    pop();
    push(45);
    pop();
    peek();
    pop();
    push(100);
    peek();
    return 0;
}

