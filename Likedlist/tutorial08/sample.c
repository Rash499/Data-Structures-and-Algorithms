#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for doubly circular linked list
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add a new node at the end of the doubly circular linked list
void insertAtEnd(struct Node** head_ref, char data) {
    struct Node* newNode = createNode(data);

    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct Node* tail = (*head_ref)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head_ref;
        (*head_ref)->prev = newNode;
    }
}

// Function to check if the word is mirrored in the doubly circular linked list
int isMirrored(struct Node* head, int length) {
    struct Node* start = head;
    struct Node* end = head->prev;

    for (int i = 0; i < length / 2; i++) {
        if (start->data != end->data) {
            return 0;
        }
        start = start->next;
        end = end->prev;
    }

    return 1;
}

// Function to free the memory allocated for the doubly circular linked list
void freeList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* next = NULL;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}

int main() {
    char word1[10];
    printf("Input word: ");
    scanf("%s",&word1);

    struct Node* head = NULL;

    // Create the doubly circular linked list for the word1
    for (int i = 0; i < strlen(word1); i++) {
        insertAtEnd(&head, word1[i]);
    }

    // Check if the word1 is mirrored
    if (isMirrored(head, strlen(word1))) {
        printf("Input word: '%s' - Output: 'Mirrored'\n", word1);
    } else {
        printf("Input word: '%s' - Output: 'Not Mirrored'\n", word1);
    }

    // Free the memory allocated for the doubly circular linked list
    freeList(head);
    head = NULL;

    // Create the doubly circular linked list for the word2
    /*
    for (int i = 0; i < strlen(word2); i++) {
        insertAtEnd(&head, word2[i]);
    }

    // Check if the word2 is mirrored
    if (isMirrored(head, strlen(word2))) {
        printf("Input word: '%s' - Output: 'Mirrored'\n", word2);
    } else {
        printf("Input word: '%s' - Output: 'Not Mirrored'\n", word2);
    }
    */
    // Free the memory allocated for the doubly circular linked list
    freeList(head);
    return 0;
}
