#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);

    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
        newNode->next = *head_ref;
    }

    *head_ref = newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// Function to print the doubly linked list in forward direction
void printForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to print the doubly linked list in reverse direction
void printReverse(struct Node* head) {
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);

    printf("Doubly Linked List (Forward): ");
    printForward(head);

    printf("Doubly Linked List (Reverse): ");
    printReverse(head);

    freeList(head);
    return 0;
}
