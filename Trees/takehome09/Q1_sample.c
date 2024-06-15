#include <stdio.h>
#include <stdlib.h>

// Node structure for organizational structure binary tree
struct Node {
    char name[50];
    struct Node* left;
    struct Node* right;
    int numSubordinates;
};

// Function to create a new employee node
struct Node* createNode(const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->numSubordinates = 0;
    return newNode;
}

// Function to calculate the total number of subordinates for an employee
int calculateSubordinates(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftSubordinates = calculateSubordinates(root->left);
    int rightSubordinates = calculateSubordinates(root->right);
    
    root->numSubordinates = leftSubordinates + rightSubordinates;
    return root->numSubordinates + 1;
}

// Helper function to recursively calculate total subordinates
int getTotalSubordinates(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->numSubordinates + 1;
}

// Function to perform in-order traversal and print employee names and total subordinates
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Employee: %s, Total Subordinates: %d\n", root->name, getTotalSubordinates(root));
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = createNode("CEO");
    root->left = createNode("Manager 1");
    root->left->left = createNode("Employee 1");
    root->left->right = createNode("Employee 2");
    root->left->right->left = createNode("Employee 3");
    root->right = createNode("Manager 2");
    root->right->left = createNode("Employee 4");

    calculateSubordinates(root);

    printf("Employee Names and Total Subordinates:\n");
    inOrderTraversal(root);

    // Free the allocated memory
    // ...

    return 0;
}
