#include <stdio.h>

void generateBinaryNumbers(int n) {
    char binaryNumbers[100][100]; // Array to store binary numbers
    int front = 0;
    int rear = 0;

    strcpy(binaryNumbers[rear++], "1"); // Enqueue the first binary number "1"

    while (n > 0 && front < rear) {
        // Dequeue the front element
        char* current = binaryNumbers[front++];

        // Print the current binary number
        printf("%s ", current);

        // Generate and enqueue the next binary numbers
        char next[100];

        // Generate next binary number by appending '0'
        strcpy(next, current);
        strcat(next, "0");
        strcpy(binaryNumbers[rear++], next);

        // Generate next binary number by appending '1'
        strcpy(next, current);
        strcat(next, "1");
        strcpy(binaryNumbers[rear++], next);

        n--;
    }
}

int main() {
    int N;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    printf("Binary numbers between 0 and %d are: ", N);
    generateBinaryNumbers(N);
    printf("\n");

    return 0;
}
