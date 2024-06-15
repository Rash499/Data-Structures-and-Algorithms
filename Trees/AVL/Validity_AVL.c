#include <stdio.h>
#include <stdlib.h>

// Node structure for binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to calculate the height of the tree
int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to check if the tree is AVL
int isAVL(struct Node* root) {
    if (root == NULL) {
        return 1; // An empty tree is AVL
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check if the balance factor of this node is within -1 to 1
    if (abs(leftHeight - rightHeight) <= 1 &&
        isAVL(root->left) && isAVL(root->right)) {
        return 1;
    }
    return 0;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 36);
    
    if (isAVL(root)) {
        printf("The given BST is an AVL tree.\n");
    } else {
        printf("The given BST is not an AVL tree.\n");
    }
    
    return 0;
}
