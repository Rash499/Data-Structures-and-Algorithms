#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;//create structure node
};
struct queue{
    struct node *front,*rear;//create queue
};
struct node* newnode(int element){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element; //create a new linkedlist node
    temp->next = NULL;
    return temp;
}
struct queue* createqueue(){
    struct queue* que = (struct queue*)malloc(sizeof(struct queue));
    que->front = que->rear = NULL;
    return que;
}
void Enqueue(struct queue *que,int element){
    struct node *temp = newnode(element);//create a new node
    // If queue is empty, then new node is front and rear
	// both
    if(que->rear == NULL){
        que->front = que->rear = temp;
        return;
    }
    	// Add the new node at the end of queue and change rear
    que->rear->next = temp;
    que->rear = temp;

}
void Dequeue(struct queue *que){
    printf("Dequeue : %d \n", ((que->front != NULL) ? (que->front)->data : -1));
	if (que->front == NULL)
		return;
    //queue is empty return null
    struct node* temp = que->front;// Store previous front and move front one node ahead
	que->front = que->front->next;
    if(que->front == NULL){//If front becomes NULL, then change rear also as NULL
        que->rear = NULL;
    }
    free(temp);
}
int main(){
    struct queue *que = createqueue();
    Enqueue(que,10);
    Enqueue(que,20);
    Enqueue(que,30);
    Dequeue(que);
    Dequeue(que);
     return 0;
}