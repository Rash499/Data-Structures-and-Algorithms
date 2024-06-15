#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE][100];
    int front;
    int rear;
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to enqueue an element
void enqueue(Queue *queue, const char *element) {
    if (isFull(queue)) {
        printf("Queue is full. Unable to enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    strcpy(queue->arr[queue->rear], element);

    printf("Enqueued: %s\n", element);
}

// Function to dequeue an element
char* dequeue(Queue *queue) {
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

int main() {
    Queue queue;
    initializeQueue(&queue);

    char input[100];

    printf("Enter strings to enqueue (type 'exit' to stop):\n");
    while (1) {
        printf("String: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove the trailing newline character

        if (strcmp(input, "exit") == 0)
            break;

        enqueue(&queue, input);
    }
    
    printf("\nDequeuing strings:\n");
    char* dequeuedElement;
    while ((dequeuedElement = dequeue(&queue)) != NULL) {
        printf("Dequeued: %s\n", dequeuedElement);
    }
    
    return 0;
}
