#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head; // Point the next of the only node to itself, creating a cycle.
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void printCircularList() {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void freeCircularList() {
    if (head == NULL) {
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(temp); // Free the last node
    head = NULL; // Reset the head pointer to NULL.
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(40);

    printf("Circular Linked List: ");
    printCircularList();

    freeCircularList(); // Free the memory before exiting the program.

    return 0;
}
