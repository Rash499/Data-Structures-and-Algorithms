#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node from a given data
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to determine if the tree is symmetric
bool isSymmetricUtil(struct Node* leftSubtree, struct Node* rightSubtree) {
    if (leftSubtree == NULL && rightSubtree == NULL) {
        return true;
    }
    if (leftSubtree == NULL || rightSubtree == NULL) {
        return false;
    }
    
    return (leftSubtree->data == rightSubtree->data) &&
           isSymmetricUtil(leftSubtree->left, rightSubtree->right) &&
           isSymmetricUtil(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(struct Node* root) {
    if (root == NULL) {
        return true;
    }
    return isSymmetricUtil(root->left, root->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root)) {
        printf("The binary tree is symmetric.\n");
    } else {
        printf("The binary tree is not symmetric.\n");
    }

    // Free the allocated memory
    // ...

    return 0;
}
