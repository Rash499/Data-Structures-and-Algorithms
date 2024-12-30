#include<stdio.h>
#include<stdbool.h>
#define MAX 5
int arr[MAX];
int front = -1;
int rear = -1;

bool isEmpty(){
    if (front == -1 && rear == -1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(){
    if(rear == MAX -1){
        return true;
    }
    else{
        return false;
    }
}
void Enqueue(int data){
    if((rear+1)%MAX==front){
        printf("Queue is FUll\n");
    }
    else{
        rear = (rear+1)%MAX;
        arr[rear] = data;
        printf("%d Enqueued\n",data);
    }
}
int Dequeue(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%MAX;
        printf("%d Dequeued\n",arr[front]);
    }
}
void frnt(){
    front = front + 1;
    int data = arr[front];
    printf("%d is the front\n",data);

}
void printQueue(){
    if(front - rear == 1){
        for(int i=0; i<MAX; i++){
            printf("%d ",arr[i]);
        }
    }
    else{
       for(int i=front+1; i<=rear; i++){
        printf("%d ",arr[i]);
    }   
    }
  
    printf("\n");
}
int main(){
    Enqueue(10);
    Enqueue(15);
    Enqueue(20);
    Enqueue(25);
    Enqueue(30);
    //Enqueue(35);
    Dequeue();
    Dequeue();
    printQueue();
    Enqueue(35);
    printQueue();
    //frnt();
    return 0;
}