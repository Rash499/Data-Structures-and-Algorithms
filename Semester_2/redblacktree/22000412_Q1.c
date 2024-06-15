#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct Node {
    int key;
    int color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->key = key;
        newNode->color = RED;
        newNode->parent = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void fixInsertViolation(Node** root, Node* z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }

    (*root)->color = BLACK;
}

void insertRBTree(Node** root, int key) {
    Node* z = createNode(key);
    Node* y = NULL;
    Node* x = *root;

    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NULL) {
        *root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    fixInsertViolation(root, z);
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d(%s) ", root->key, (root->color == RED) ? "RED" : "BLACK");
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    int keys[] = {10, 20, 30, 15, 25, 5};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        insertRBTree(&root, keys[i]);
        printf("After inserting %d: ", keys[i]);
        inorderTraversal(root);
        printf("\n");
    }


    return 0;
}
