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
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to find the sum of node values at distance k from target node
void findSumAtDistanceK(struct Node* root, int k, int* sum) {
    if (root == NULL || k < 0)
        return;

    if (k == 0) {
        *sum += root->data;
        return;
    }

    findSumAtDistanceK(root->left, k - 1, sum);
    findSumAtDistanceK(root->right, k - 1, sum);
}

// Function to find the distance between nodes and the target
int findDistance(struct Node* root, int target, int* sum, int k) {
    if (root == NULL)
        return -1;

    if (root->data == target) {
        findSumAtDistanceK(root, k, sum);
        return 0;
    }

    int leftDistance = findDistance(root->left, target, sum, k);
    if (leftDistance != -1) {
        if (leftDistance + 1 == k)
            *sum += root->data;
        else
            findSumAtDistanceK(root->right, k - leftDistance - 2, sum);
        return leftDistance + 1;
    }

    int rightDistance = findDistance(root->right, target, sum, k);
    if (rightDistance != -1) {
        if (rightDistance + 1 == k)
            *sum += root->data;
        else
            findSumAtDistanceK(root->left, k - rightDistance - 2, sum);
        return rightDistance + 1;
    }

    return -1;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 30);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 25);
    root = insert(root, 40);

    int target = 8;
    int k = 2;
    int sum = 0;

    findDistance(root, target, &sum, k);
    printf("Sum of node values at distance %d from target %d: %d\n", k, target, sum);

    return 0;
}
