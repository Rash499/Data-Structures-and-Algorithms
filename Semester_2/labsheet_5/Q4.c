#include <stdio.h>
#include <stdlib.h>

#define USERS 3

int main() {
    int adjMatrix[USERS][USERS];

    for (int i = 0; i < USERS; ++i) {
        for (int j = 0; j < USERS; ++j) {
            if (i != j)
                adjMatrix[i][j] = 1; 
            else
                adjMatrix[i][j] = 0; 
        }
    }

    printf("Adjacency Matrix representing the social network:\n");
    for (int i = 0; i < USERS; ++i) {
        for (int j = 0; j < USERS; ++j) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
