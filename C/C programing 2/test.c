#include <stdio.h>

#define MAX_SIZE 50

typedef struct {
    int priority;
    int processId;
} Process;

void enqueueProcess(Process process, Process queue[], int* rear) {
    if (*rear == MAX_SIZE - 1) {
        printf("Queue is full. Process with ID %d and priority %d not enqueued\n", process.processId, process.priority);
        return;
    }
    queue[++(*rear)] = process;
    printf("Process with ID %d and priority %d enqueued\n", process.processId, process.priority);
}

Process dequeueProcess(Process queue[], int* front, int rear) {
    if (*front > rear) {
        Process emptyProcess = { -1, -1 };
        printf("Queue is empty. No processes to dequeue\n");
        return emptyProcess;
    }
    return queue[(*front)++];
}

int main() {
    Process highPriorityQueue[MAX_SIZE], lowPriorityQueue[MAX_SIZE];
    int highPriorityFront = 0, lowPriorityFront = 0;
    int highPriorityRear = -1, lowPriorityRear = -1;

    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (int i = 0; i < numProcesses; i++) {
        Process process;
        printf("Enter the priority (1 for high, 2 for low) of process %d: ", i + 1);
        scanf("%d", &process.priority);
        process.processId = i + 1;
        
        if (process.priority == 1) {
            enqueueProcess(process, highPriorityQueue, &highPriorityRear);
        } else if (process.priority == 2) {
            enqueueProcess(process, lowPriorityQueue, &lowPriorityRear);
        } else {
            printf("Invalid priority value. Process with ID %d not enqueued\n", process.processId);
        }
    }

    printf("Dequeuing processes:\n");
    for (int i = 0; i < numProcesses; i++) {
        Process dequeuedProcess;
        if (highPriorityFront <= highPriorityRear) {
            dequeuedProcess = dequeueProcess(highPriorityQueue, &highPriorityFront, highPriorityRear);
        } else if (lowPriorityFront <= lowPriorityRear) {
            dequeuedProcess = dequeueProcess(lowPriorityQueue, &lowPriorityFront, lowPriorityRear);
        } else {
            Process emptyProcess = { -1, -1 };
            printf("No processes in the queues\n");
            dequeuedProcess = emptyProcess;
        }

        if (dequeuedProcess.processId != -1) {
            printf("Process with ID %d and priority %d dequeued\n", dequeuedProcess.processId, dequeuedProcess.priority);
        }
    }

    return 0;
}
