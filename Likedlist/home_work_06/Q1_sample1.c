#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to sort and insert a node into the sorted list
void sort(struct Node* head, struct Node** temp) {
    if (*temp == NULL || (*temp)->data >= head->data) {
        head->next = *temp;
        *temp = head;
    } else {
        struct Node* current = *temp;
        while (current->next != NULL && current->next->data < head->data) {
            current = current->next;
        }
        head->next = current->next;
        current->next = head;
    }
}

// Function to sort the entire linked list
struct Node* sortLinkedList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        sort(current, &temp);
        current = next;
    }
    return temp;
}

// Function to delete the entire linked list
struct Node* deleteLinkedList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return NULL; // Return NULL as the new head pointer after deleting the list
}

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* p;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            head = (struct Node*)malloc(sizeof(struct Node));
            p = head;
        } else {
            p->next = (struct Node*)malloc(sizeof(struct Node));
            p = p->next;
        }
        scanf("%d", &p->data);
    }
    p->next = NULL;

    head = sortLinkedList(head);

    // Print the sorted linked list
    int count = 1;
    while (head != NULL) {
        printf("NODE %d: %d\n", count, head->data);
        count++;
        head = head->next;
    }

    head = deleteLinkedList(head);
    // Check if the list is empty
    if (head == NULL) {
        printf("Linked list is deleted.\n");
    }

    return 0;
}
