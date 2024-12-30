#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the singly linked list
struct Node {
    int id;
    char name[16];
    float gpa;
    struct Node* next;
};

// Function to create a new node with student information
struct Node* createStudent(int id, const char* name, float gpa) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';
    newNode->gpa = gpa;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new student to the list in ascending order of ID (sorted by GPA)
void addStudent(struct Node** head_ref, int id, const char* name, float gpa) {
    struct Node* newNode = createStudent(id, name, gpa);

    if (*head_ref == NULL || gpa > (*head_ref)->gpa) {
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL && gpa <= current->next->gpa) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete a student by ID from the list
int deleteStudent(struct Node** head_ref, int id) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return 0; // Student not found
    }

    if (prev == NULL) {
        *head_ref = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    return 1; // Success
}

// Function to convert the linked list to an array of students
struct Node** listToArray(struct Node* head, int* size) {
    struct Node** arr = NULL;
    int count = 0;

    struct Node* current = head;
    while (current != NULL) {
        arr = realloc(arr, (count + 1) * sizeof(struct Node*));
        arr[count] = current;
        current = current->next;
        count++;
    }

    *size = count;
    return arr;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, GPA: %.1f\n", current->id, current->name, current->gpa);
        current = current->next;
    }
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

    // Add students to the list
    addStudent(&head, 1, "Alice", 3.9);
    addStudent(&head, 2, "Bob", 3.7);
    addStudent(&head, 3, "Charlie", 3.5);
    addStudent(&head, 4, "David", 3.6);
    addStudent(&head, 5, "Eva", 3.8);
    addStudent(&head, 6, "Frank", 3.1);
    addStudent(&head, 7, "Grace", 3.4);
    addStudent(&head, 8, "Hank", 3.3);
    addStudent(&head, 9, "Ivy", 3.2);
    addStudent(&head, 10, "Jack", 3.0);

    printf("List after adding students:\n");
    printList(head);

    // Delete students from the list
    printf("\nDelete the 1st Student in the list:\n");
    deleteStudent(&head, 1);
    printList(head);

    printf("\nDelete the Student with the ID: 5 from the list:\n");
    deleteStudent(&head, 5);
    printList(head);

    printf("\nDelete the last Student from the list:\n");
    deleteStudent(&head, 10);
    printList(head);

    // Convert list to an array and print the content of the array
    int arraySize;
    struct Node** arr = listToArray(head, &arraySize);

    printf("\nList to Array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("Array[%d] -> ID: %d, Name: %s, GPA: %.1f\n",
               i, arr[i]->id, arr[i]->name, arr[i]->gpa);
    }

    // Free the memory allocated for the linked list and array
    freeList(head);
    free(arr);

    return 0;
}
