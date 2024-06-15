#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* push(struct node *head,int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;

}
void printList(struct node* head) {
    struct node  *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
/*struct node *insert(){
    int k,n;
    struct node *p,*head;
    printf("how many elements: ");
    scanf("%d",&n);

    for(k=0; k<n; k++){
        if(k==0){
            head = (struct node*)malloc(sizeof(struct node));
            p=head;
        }
        else{
            p->next = (struct node*)malloc(sizeof(struct node));
            p = p->next;
        }
        scanf("%d",&p->data);
    }
    p->next = NULL;
    return head;

}
void print(struct node *head){
    int count =1;
    struct node *p;
    p=head;
    while(p != NULL){
        printf("NODE %d: %d \n",count,p->data);
        count++;
        p = p->next;
    }
    printf("\n");
} */
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = 20;
    p->next = NULL;
    head->next =p;

    p = (struct node*)malloc(sizeof(struct node));
    p->data = 230;
    p->next = NULL;
    head->next->next = p;
    //print(head);
    head = push(head,500);
    //printf("\n");
    printList(head);
    return 0;
}