#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Train {
    int trainId;
    char destination[50];
    struct Train* next;
} Train;

// Function to add a new train at the end of the schedule
void addTrain(Train** head, int trainId, const char* destination) {
    Train* newTrain = (Train*)malloc(sizeof(Train));
    newTrain->trainId = trainId;
    strncpy(newTrain->destination, destination, sizeof(newTrain->destination) - 1);
    newTrain->destination[sizeof(newTrain->destination) - 1] = '\0';
    newTrain->next = NULL;

    if (*head == NULL) {
        *head = newTrain;
    } else {
        Train* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTrain;
    }

    printf("Adding train: ID = %d, Destination = '%s'\n", trainId, destination);
}

// Function to simulate a train departure and remove the first train from the schedule
Train* departTrain(Train** head) {
    if (*head == NULL) {
        printf("No trains in the schedule. Departure not possible.\n");
        return NULL;
    }

    Train* departingTrain = *head;
    *head = (*head)->next;

    printf("Departing train: ID = %d, Destination = '%s'\n", departingTrain->trainId, departingTrain->destination);

    return departingTrain;
}

// Function to return the first train in the schedule without removing it
Train* nextTrain(Train* head) {
    if (head == NULL) {
        printf("No trains in the schedule.\n");
        return NULL;
    }

    printf("The next train is: ID = %d, Destination = '%s'\n", head->trainId, head->destination);
    return head;
}

// Function to print the current schedule
void printSchedule(Train* head) {
    Train* current = head;
    while (current != NULL) {
        printf("%d(%s) -> ", current->trainId, current->destination);
        current = current->next;
    }
    printf("Empty\n");
}

// Function to free the memory allocated for the schedule
void freeSchedule(Train* head) {
    Train* current = head;
    while (current != NULL) {
        Train* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Train* schedule = NULL;

    addTrain(&schedule, 101, "New York");
    printSchedule(schedule);

    addTrain(&schedule, 102, "Los Angeles");
    printSchedule(schedule);

    addTrain(&schedule, 103, "Chicago");
    printSchedule(schedule);

    departTrain(&schedule);
    printSchedule(schedule);

    departTrain(&schedule);
    printSchedule(schedule);

    departTrain(&schedule);
    printSchedule(schedule);

    return 0;
}
