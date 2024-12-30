#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;            // Data for this node
    struct Node* prev;   // Pointer to the previous node
    struct Node* next;   // Pointer to the next node
};

// Declare the head pointer to the doubly linked list
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to insert a new node at a given position in the doubly linked list
void insertAtPosition(int data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1 || head == NULL) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = createNode(data);

    struct Node* current = head;
    int currentPosition = 1;

    while (currentPosition < position - 1 && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < position - 1 || current == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to delete the first node from the doubly linked list
void deleteAtBeginning() {
    if (head == NULL) {
        printf("Linked list is empty. Deletion not possible.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete the last node from the doubly linked list
void deleteAtEnd() {
    if (head == NULL) {
        printf("Linked list is empty. Deletion not possible.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);
}

// Function to delete a node at a given position in the doubly linked list
void deleteAtPosition(int position) {
    if (position <= 0 || head == NULL) {
        printf("Invalid position or empty list. Deletion not possible.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node* current = head;
    int currentPosition = 1;

    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < position || current == NULL) {
        printf("Position out of range.\n");
        return;
    }

    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

// Function to print the doubly linked list forward
void printListForward() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the doubly linked list backward
void printListBackward() {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the doubly linked list
void freeLinkedList() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(34);
    insertAtEnd(30);
    insertAtPosition(15, 2);

    printf("List Forward: ");
    printListForward();

    printf("List Backward: ");
    printListBackward();

    deleteAtBeginning();
    deleteAtEnd();
    deleteAtPosition(1);

    printf("List Forward after Deletions: ");
    printListForward();

    freeLinkedList();

    return 0;
}
