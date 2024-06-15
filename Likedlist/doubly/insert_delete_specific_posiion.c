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

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(struct Node** head_ref, int data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    struct Node* current = *head_ref;
    int currentPosition = 1;

    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < position) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        *head_ref = newNode;
    }

    current->prev = newNode;
}

// Function to delete a node at a specific position in the doubly linked list
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        printf("Invalid position or empty list.\n");
        return;
    }

    struct Node* current = *head_ref;
    int currentPosition = 1;

    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < position || current == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head_ref = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
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

    insertAtPosition(&head, 10, 1); // Insert at the beginning
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 30, 3);
    insertAtPosition(&head, 40, 2); // Insert at position 2
    insertAtPosition(&head, 50, 5); // Insert at the end

    printf("Doubly Linked List (Forward): ");
    printForward(head);

    deleteAtPosition(&head, 3); // Delete node at position 3

    printf("Doubly Linked List after deletion: ");
    printForward(head);

    freeList(head);
    return 0;
}
