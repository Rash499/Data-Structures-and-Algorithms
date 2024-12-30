#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 3
char* arr[MAX];
int front = -1;
int rear = -1;
bool isFull(){
    if(rear >= MAX -1){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    else{
        return false;
    }
}
void Enqueue(){
    if(isFull()){
        printf("Playlist is full\n");
    }
    else{
        rear = rear + 1;
        arr[rear] = (char*)malloc(100*sizeof(char));
        printf("Enter the song name: ");
        scanf("%s",&arr[rear]);
        printf("%s Entered to the Playlist\n",arr[rear]);
    }
} 
void Dequeue(){
    if(isEmpty()){
        printf("Playlist is empty\n");
    }
    else{
        front = front + 1;
        printf("%s removed from the playlist\n",arr[front]);
    }
}
int main(){
    //printf("Enter your Songs\n");
    //for(int i=0; i<MAX; i++){
     // Enqueue();  
   // }
   Enqueue();
    return 0;
}