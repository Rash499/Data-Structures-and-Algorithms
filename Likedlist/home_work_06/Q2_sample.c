#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBegin(struct Node* last, int data);
struct Node* insertAtEnd(struct Node* last, int data);
struct Node* deleteAtBegin(struct Node* last);
struct Node* deleteAtEnd(struct Node* last);
void printCircularList(struct Node* last);

int main() {
    struct Node* last = NULL;

    last = insertAtBegin(last, 7);
    last = insertAtEnd(last, 10);
    last = insertAtBegin(last, 5);
    last = insertAtEnd(last, 15);

    printCircularList(last);

    last = deleteAtBegin(last);
    last = deleteAtEnd(last);

    printCircularList(last);

    return 0;
}

struct Node* insertAtBegin(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    return last;
}

struct Node* insertAtEnd(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    return last;
}

struct Node* deleteAtBegin(struct Node* last) {
    if (last == NULL) {
        printf("Circular linked list is empty.\n");
        return last;
    }

    struct Node* first = last->next;
    if (first == last) {
        free(first);
        last = NULL;
    } else {
        last->next = first->next;
        free(first);
    }
    return last;
}

struct Node* deleteAtEnd(struct Node* last) {
    if (last == NULL) {
        printf("Circular linked list is empty.\n");
        return last;
    }

    struct Node* temp = last;
    while (temp->next != last) {
        temp = temp->next;
    }

    if (temp == last) {
        free(last);
        last = NULL;
    } else {
        temp->next = last->next;
        free(last);
        last = temp;
    }
    return last;
}

void printCircularList(struct Node* last) {
    if (last == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}