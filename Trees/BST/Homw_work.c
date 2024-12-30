#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
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

// Function to insert a new node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to search for a node in the binary search tree
struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

// Function to find the minimum value node in a binary search tree
struct Node* findMin(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Function to find the maximum value node in a binary search tree
struct Node* findMax(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to calculate the height of the binary search tree
int findHeight(struct Node* root) {
    if (root == NULL)
        return -1;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to calculate the size (number of nodes) of the binary search tree
int findSize(struct Node* root) {
    if (root == NULL)
        return 0;

    return findSize(root->left) + 1 + findSize(root->right);
}

// Function to create a mirror image of the binary search tree
struct Node* mirrorImage(struct Node* root) {
    if (root == NULL)
        return NULL;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    root->left = mirrorImage(root->left);
    root->right = mirrorImage(root->right);

    return root;
}

// Function to print the binary search tree in-order
void inOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);


    printf("In-order traversal of the original tree:\n");
    inOrderTraversal(root);
    printf("\n");

    // Search for a node
    int key = 40;
    struct Node* searchResult = searchNode(root, key);
    if (searchResult)
        printf("Node with key %d found!\n", key);
    else
        printf("Node with key %d not found.\n", key);

    // Delete a node
    key = 30;
    root = deleteNode(root, key);
    printf("In-order traversal after deleting node with key %d:\n", key);
    inOrderTraversal(root);
    printf("\n");

    // Find minimum and maximum nodes
    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);
    printf("Minimum node value: %d\n", minNode->data);
    printf("Maximum node value: %d\n", maxNode->data);

    // Calculate height and size of the tree
    int height = findHeight(root);
    int size = findSize(root);
    printf("Height of the tree: %d\n", height);
    printf("Size of the tree: %d\n", size);

    // Create a mirror image of the tree
    root = mirrorImage(root);
    
    printf("In-order traversal of the mirror image tree:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}