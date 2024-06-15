#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct Book {
    long long isbn;
    char title[100];
    char author[100];
} Book;

typedef struct Node {
    Book book;
    int color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(Book book) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->book = book;
    newNode->color = RED;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void leftRotate(Node** root, Node* x);
void rightRotate(Node** root, Node* y);
void fixInsertViolation(Node** root, Node* z);
void insertRBTree(Node** root, Book book);
void inorderTraversal(Node* root);

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

void insertRBTree(Node** root, Book book) {
    Node* z = createNode(book);
    Node* y = NULL;
    Node* x = *root;

    while (x != NULL) {
        y = x;
        if (z->book.isbn < x->book.isbn) {
            x = x->left;
        } else if (z->book.isbn > x->book.isbn) {
            x = x->right;
        } else {
            printf("Error: Book with ISBN %lld already exists.\n", z->book.isbn);
            free(z);
            return;
        }
    }

    z->parent = y;

    if (y == NULL) {
        *root = z;
    } else if (z->book.isbn < y->book.isbn) {
        y->left = z;
    } else {
        y->right = z;
    }

    fixInsertViolation(root, z);

    printf("Book with ISBN %lld inserted. Updated inventory:\n", z->book.isbn);
    inorderTraversal(*root);
    printf("\n");
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%lld(%s) ", root->book.isbn, (root->color == RED) ? "RED" : "BLACK");
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    Book book1 = {9780133594140, "The C Programming Language", "Kernighan & Ritchie"};
    Book book2 = {9780321714114, "Clean Code", "Robert C. Martin"};
    Book book3 = {9780596007126, "Head First Design Patterns", "Freeman & Freeman"};
    Book book4 = {9780131103627, "Effective C++", "Scott Meyers"};

    insertRBTree(&root, book1);
    insertRBTree(&root, book2);
    insertRBTree(&root, book3);
    insertRBTree(&root, book4);

    Book duplicateBook = {9780321714114, "Duplicate Book", "Author"};
    insertRBTree(&root, duplicateBook);

    return 0;
}
