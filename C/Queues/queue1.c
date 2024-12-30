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
    if(isFull()){
        printf("Queue is Full\n");
    }
    else{
        rear = rear + 1;
        arr[rear] = data;
        printf("%d enqueued\n",data);
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
        front = front + 1;
        printf("%d Dequeued\n",arr[front]);
    }
}
void frnt(){
    front = front + 1;
    int data= arr[front];
    printf("%d is the front\n",data);
    

}
void printQueue(){
    for(int i=front+1; i<=rear; i++){
        printf("%d ",arr[i]);
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
    //Enqueue(35);
    frnt();
    return 0;
}