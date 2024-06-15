#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char* arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to enqueue an element
void enqueue(Queue* queue, const char* element) {
    if (isFull(queue)) {
        printf("Queue is full. Unable to enqueue.\n");
        return;
    }

    char* newElement = malloc(strlen(element) + 1);
    strcpy(newElement, element);

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->arr[queue->rear] = newElement;

    printf("Enqueued: %s\n", element);
}

// Function to dequeue an element
char* dequeue(Queue* queue) {
    char* element;

    if (isEmpty(queue)) {
        printf("Queue is empty. Unable to dequeue.\n");
        return NULL;
    }

    element = queue->arr[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        // Reset the queue indices if the queue becomes empty
        queue->front = -1;
        queue->rear = -1;
    }

    return element;
}

// Function to free memory used by the queue
void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        char* element = dequeue(queue);
        free(element);
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, "Hello");
    enqueue(&queue, "World");
    enqueue(&queue, "Queue");
    enqueue(&queue, "Example");

    printf("\nDequeuing strings:\n");
    char* dequeuedElement;
    while ((dequeuedElement = dequeue(&queue)) != NULL) {
        printf("Dequeued: %s\n", dequeuedElement);
        free(dequeuedElement);
    }

    freeQueue(&queue);

    return 0;
}
