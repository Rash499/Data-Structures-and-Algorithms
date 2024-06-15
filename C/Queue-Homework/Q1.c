#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 10
typedef struct{
    char array[MAX][10];
    int front;
    int rear;
} queue;
void makeQueue(queue *que){
    que->front=-1;
    que->rear=-1;
}
int isEmpty(queue *que){
    return (que->front == -1);
}
int isFull(queue *que){
    return (que->rear == MAX -1);
}
void Enqueue(queue *que,const char *data){
    if(isFull(que)){
        printf("Playlist is Full\n");
        return;
    }
    if(isEmpty(que)){
        que->front=0;
    }
    que->rear++;
    strcpy(que->array[que->rear], data);
    printf("Song added to playlist: %s\n",data);
}
char* dequeue(queue *que) {
    char* element;

    if (isEmpty(que)) {
        printf("Playlist is empty. Unable to dequeue.\n");
        return NULL;
    }

    element = que->array[que->front];
    que->front++;

    if (que->front > que->rear) {
        // Reset the queue indices if the queue becomes empty
        que->front = -1;
        que->rear = -1;
    }

    return element;
}
int main(){
    queue que;
    makeQueue(&que);
    char input[10];
    printf("Add songs to the playlist: type \'exit\' to exit.\n ");
    while(true){
        printf("Song name: ");
        fgets(input,sizeof(input),stdin);
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input,"exit") == 0){
            break;
        }
        Enqueue(&que,input);
    }
   printf("\nDispaly Songs in the playlist\n");
    char* song;
    while ((song = dequeue(&que)) != NULL) {
        printf("Display song: %s\n", song);
    }
    return 0;
}