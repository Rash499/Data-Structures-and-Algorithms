#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task structure
struct Task {
    int taskId;
    char description[100];
    int completed;
    struct Task* next;
};

struct Task* head = NULL; // Global variable to store the head of the linked list

// Function to add a new task to the to-do list
void addTask(int id, const char* desc) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    newTask->taskId = id;
    strcpy(newTask->description, desc);
    newTask->completed = 0; // 0 indicates task is not completed initially
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        struct Task* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

// Function to mark a task as completed
void markCompleted(int id) {
    struct Task* temp = head;
    while (temp != NULL) {
        if (temp->taskId == id) {
            temp->completed = 1; // 1 indicates task is completed
            return;
        }
        temp = temp->next;
    }
    printf("Task with ID %d not found!\n", id);
}

// Function to remove a task from the to-do list
void removeTask(int id) {
    struct Task *prev = NULL, *temp = head;
    while (temp != NULL) {
        if (temp->taskId == id) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Task with ID %d not found!\n", id);
}

// Function to display the entire to-do list
void displayTasks() {
    struct Task* temp = head;
    printf("To-Do List:\n");
    while (temp != NULL) {
        printf("ID: %d | Description: %s | Completed: %s\n", temp->taskId, temp->description,
               (temp->completed == 1) ? "Yes" : "No");
        temp = temp->next;
    }
}

int main() {
    int choice, taskId;
    char desc[100];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. Remove Task\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Task ID: ");
                scanf("%d", &taskId);
                printf("Enter Task Description: ");
                scanf(" %[^\n]s", desc);
                addTask(taskId, desc);
                break;
            case 2:
                printf("Enter Task ID to mark as completed: ");
                scanf("%d", &taskId);
                markCompleted(taskId);
                break;
            case 3:
                printf("Enter Task ID to remove: ");
                scanf("%d", &taskId);
                removeTask(taskId);
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                printf("Exiting the application.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}