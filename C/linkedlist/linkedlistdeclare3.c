#include<stdio.h>
#include<stdlib.h>
struct node{
    int age;
    struct node *next;
};
int insert_list(){

int k, n;
struct node *p,*head;
printf( "\nHow many elements to enter?");
scanf ("%d", &n);
for (k= 0 ; k<n; k++){
  if (k == 0 ){
    head = (struct node *)malloc( sizeof(struct node));
    p = head;
  }
  else {
   p->next = (struct node *)malloc( sizeof (struct node));
   p = p->next;
   scanf ("%d",&p->age);
  }
  p->next = NULL;
  return (head);
 }
}
int main(){
    struct node *head =(struct node*)malloc(sizeof(struct node));
    head = create_list();
    return 0;
}