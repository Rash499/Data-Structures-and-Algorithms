#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *insert(){
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
}
int main(){
    struct node *head;
    head = insert();
    print(head);
    return 0;
}