#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertAtBegin(struct Node* last, int data);
struct Node* insertAtEnd(struct Node* last, int data);
struct Node* deleteAtBegin(struct Node* last);
struct Node* deleteAtEnd(struct Node* last);
void printCircularDoublyList(struct Node* last);

int main() {
    struct Node* last = NULL;

    // insert nodes
    last = insertAtEnd(last, 10);
    last = insertAtEnd(last, 20);
    last = insertAtEnd(last, 30);

    // print the circular doubly linked list after insertion
    printf("After insertion: ");
    printCircularDoublyList(last);

    // delete at beginning and end
    last = deleteAtBegin(last);
    last = deleteAtEnd(last);

    // print the circular doubly linked list after deletion
    printf("After deletion: ");
    printCircularDoublyList(last);

    return 0;
}

// inserts a node at the beginning of the circular doubly linked list
struct Node* insertAtBegin(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        last->next = last;
        last->prev = last;
    } else {
        newNode->next = last->next;
        newNode->prev = last;
        last->next->prev = newNode;
        last->next = newNode;
    }

    return last;
}

// inserts a node at the end of the circular doubly linked list
struct Node* insertAtEnd(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        last->next = last;
        last->prev = last;
    } else {
        newNode->next = last->next;
        newNode->prev = last;
        last->next->prev = newNode;
        last->next = newNode;
        last = newNode;
    }

    return last;
}

// deletes a node from the beginning of the circular doubly linked list
struct Node* deleteAtBegin(struct Node* last) {
    if (last == NULL) {
        printf("Circular doubly linked list is empty, cannot delete.\n");
        return NULL;
    }

    struct Node* temp = last->next;

    if (temp == last) {
        free(temp);
        return NULL;
    }

    last->next = temp->next;
    temp->next->prev = last;
    free(temp);
    return last;
}

// deletes a node from the end of the circular doubly linked list
struct Node* deleteAtEnd(struct Node* last) {
    if (last == NULL) {
        printf("Circular doubly linked list is empty, cannot delete.\n");
        return NULL;
    }

    if (last->next == last) {
        free(last);
        return NULL;
    }

    struct Node* temp = last;
    last->prev->next = last->next;
    last->next->prev = last->prev;
    last = last->prev;
    free(temp);
    return last;
}

// utility function to print the circular doubly linked list
void printCircularDoublyList(struct Node* last) {
    if (last == NULL) {
        printf("Circular doubly linked list is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("%d (circular)\n", temp->data);
}
