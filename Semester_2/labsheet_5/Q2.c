#include <stdio.h>
#include <stdlib.h>

void printAdjMatrix(int** adjMatrix, int V) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int** adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i)
        adjMatrix[i] = (int*)calloc(V, sizeof(int));

    printf("Enter pairs of vertices representing edges:\n");
    for (int i = 0; i < E; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    printAdjMatrix(adjMatrix, V);

    for (int i = 0; i < V; ++i)
        free(adjMatrix[i]);
    free(adjMatrix);

    return 0;
}
