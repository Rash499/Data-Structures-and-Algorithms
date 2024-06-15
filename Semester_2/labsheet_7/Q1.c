#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode **children;
    int num_children;
};

struct TreeNode* createNode(int value, int num_children) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->num_children = num_children;
    newNode->children = (struct TreeNode**)malloc(num_children * sizeof(struct TreeNode*));
    for (int i = 0; i < num_children; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    for (int i = 0; i < root->num_children; i++) {
        preorderTraversal(root->children[i]);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    if (root->num_children > 0) {
        inorderTraversal(root->children[0]);
    }

    printf("%d ", root->data);

    for (int i = 1; i < root->num_children; i++) {
        inorderTraversal(root->children[i]);
    }
}

int main() {
    int num_nodes;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &num_nodes);

    struct TreeNode* root = NULL;

    if (num_nodes > 0) {
        int root_value;
        printf("Enter the value for the root node: ");
        scanf("%d", &root_value);

        root = createNode(root_value, num_nodes - 1);

        printf("Enter the values for the child nodes: ");
        for (int i = 0; i < root->num_children; i++) {
            int child_value;
            scanf("%d", &child_value);
            root->children[i] = createNode(child_value, 0);
        }
    }

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
