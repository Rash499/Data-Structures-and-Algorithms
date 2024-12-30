#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User structure
struct User {
    char name[50];
    int age;
    int followers;
};

// AVL tree node
struct AVLNode {
    struct User user;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

// Function to get the height of a node
int getHeight(struct AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(struct AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to create a new user node
struct AVLNode* createUserNode(struct User user) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->user = user;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to perform a right rotation
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Function to perform a left rotation
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Function to insert a user into the AVL tree
struct AVLNode* insert(struct AVLNode* root, struct User user) {
    if (root == NULL) {
        return createUserNode(user);
    }

    if (strcmp(user.name, root->user.name) < 0) {
        root->left = insert(root->left, user);
    } else if (strcmp(user.name, root->user.name) > 0) {
        root->right = insert(root->right, user);
    } else {
        return root; // Duplicate names are not allowed
    }

    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    int balanceFactor = getBalanceFactor(root);

    // Left Heavy
    if (balanceFactor > 1 && strcmp(user.name, root->left->user.name) < 0) {
        return rightRotate(root);
    }

    // Right Heavy
    if (balanceFactor < -1 && strcmp(user.name, root->right->user.name) > 0) {
        return leftRotate(root);
    }

    // Left Right Heavy
    if (balanceFactor > 1 && strcmp(user.name, root->left->user.name) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Heavy
    if (balanceFactor < -1 && strcmp(user.name, root->right->user.name) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to find the node with the minimum value in the tree
struct AVLNode* findMin(struct AVLNode* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL) {
        return root;
    }
    return findMin(root->left);
}

// Function to delete a node from the AVL tree
struct AVLNode* deleteNode(struct AVLNode* root, char* name) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(name, root->user.name) < 0) {
        root->left = deleteNode(root->left, name);
    } else if (strcmp(name, root->user.name) > 0) {
        root->right = deleteNode(root->right, name);
    } else {
        if (root->left == NULL || root->right == NULL) {
            struct AVLNode* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            struct AVLNode* temp = findMin(root->right);
            root->user = temp->user;
            root->right = deleteNode(root->right, temp->user.name);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    int balanceFactor = getBalanceFactor(root);

    // Left Heavy
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    // Right Heavy
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    // Left Right Heavy
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Heavy
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform in-order traversal of the AVL tree
void inOrderTraversal(struct AVLNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Name: %s, Age: %d, Followers: %d\n", root->user.name, root->user.age, root->user.followers);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct AVLNode* root = NULL;

    // Insert users
    root = insert(root, (struct User){"Alice", 25, 1000});
    root = insert(root, (struct User){"Bob", 30, 500});
    root = insert(root, (struct User){"Charlie", 22, 750});
    root = insert(root, (struct User){"David", 28, 800});
    root = insert(root, (struct User){"Eve", 29, 1200});

    printf("After inserting users:\n");
    inOrderTraversal(root);

    // Remove user "Charlie"
    root = deleteNode(root, "Charlie");

    printf("\nAfter deleting Charlie:\n");
    inOrderTraversal(root);

    return 0;
}
