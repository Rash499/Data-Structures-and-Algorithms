#include <stdio.h>

#define MAX 50

typedef struct {
    int priority;
    int processNum;
} Process;

void Enqueue(Process process, Process queue[], int* rear) {
    if (*rear == MAX - 1) {
        printf("Queue is full. Process with number %d and priority %d not enqueued\n", process.processNum, process.priority);
        return;
    }
    queue[++(*rear)] = process;
    printf("Process with number %d and priority %d added\n", process.processNum, process.priority);
}

Process Dequeue(Process queue[], int* front, int rear) {
    if (*front > rear) {
        Process emptyProcess = { -1, -1 };
        printf("Queue is empty. No processes to dispaly\n");
        return emptyProcess;
    }
    return queue[(*front)++];
}

int main() {
    Process highPriorityQueue[MAX], lowPriorityQueue[MAX];
    int highPriorityFront = 0, lowPriorityFront = 0;
    int highPriorityRear = -1, lowPriorityRear = -1;

    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (int i = 0; i < numProcesses; i++) {
        Process process;
        printf("Enter the priority (1 for highpriority, 2 for lowpriority) of process %d: ", i + 1);
        scanf("%d", &process.priority);
        process.processNum = i + 1;
        
        if (process.priority == 1) {
            Enqueue(process, highPriorityQueue, &highPriorityRear);
        } else if (process.priority == 2) {
            Enqueue(process, lowPriorityQueue, &lowPriorityRear);
        } else {
            printf("Invalid priority value. Process with number %d not added\n", process.processNum);
        }
    }

    printf("Display processes:\n");
    for (int i = 0; i < numProcesses; i++) {
        Process dequeue;
        if (highPriorityFront <= highPriorityRear) {
            dequeue = Dequeue(highPriorityQueue, &highPriorityFront, highPriorityRear);
        } else if (lowPriorityFront <= lowPriorityRear) {
            dequeue = Dequeue(lowPriorityQueue, &lowPriorityFront, lowPriorityRear);
        } else {
            Process empty = { -1, -1 };
            printf("No processes in the queues\n");
            dequeue = empty;
        }

        if (dequeue.processNum != -1) {
            printf("Process with Number %d and priority %d\n", dequeue.processNum, dequeue.priority);
        }
    }

    return 0;
}
