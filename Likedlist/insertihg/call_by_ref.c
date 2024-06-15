#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    // Allocate memory for a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Put the new data in the new node
    new_node->data = new_data;

    // Make the next of the new node point to the current head
    new_node->next = (*head_ref);

    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
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

    // Insert elements at the beginning of the linked list
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    // Print the linked list
    printf("Linked list elements: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
