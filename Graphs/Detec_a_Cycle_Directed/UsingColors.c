#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list for each vertex
struct AdjList {
    struct Node* head;
};

// Structure to represent the directed graph
struct Graph {
    int vertices;
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));

    for (int i = 0; i < vertices; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Helper function for DFS to detect a cycle
int detectCycleDFS(struct Graph* graph, int vertex, int* colors) {
    colors[vertex] = GRAY; // Mark the current node as gray (being explored)

    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int neighbor = temp->vertex;

        // If the neighbor is gray, a cycle is detected
        if (colors[neighbor] == GRAY) {
            return 1; // Cycle found
        }

        // If the neighbor is white, recursively explore it
        if (colors[neighbor] == WHITE && detectCycleDFS(graph, neighbor, colors)) {
            return 1; // Cycle found during exploration
        }

        temp = temp->next;
    }

    colors[vertex] = BLACK; // Mark the current node as black (fully explored)
    return 0; // No cycle found during exploration
}

// Function to detect a cycle in the graph
int hasCycle(struct Graph* graph) {
    int* colors = (int*)malloc(graph->vertices * sizeof(int));

    // Initialize colors for all vertices as white
    for (int i = 0; i < graph->vertices; ++i) {
        colors[i] = WHITE;
    }

    // Traverse all vertices using DFS
    for (int i = 0; i < graph->vertices; ++i) {
        if (colors[i] == WHITE) {
            if (detectCycleDFS(graph, i, colors)) {
                free(colors);
                return 1; // Cycle found
            }
        }
    }

    free(colors);
    return 0; // No cycle found
}

int main() {
    // Example: Creating a directed graph
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // Detecting a cycle
    if (hasCycle(graph)) {
        printf("The graph contains a cycle.\n");
    } else {
        printf("The graph does not contain a cycle.\n");
    }

    // Free allocated memory
    // Note: You should have a proper function to free the graph in a real-world scenario
    free(graph);

    return 0;
}
