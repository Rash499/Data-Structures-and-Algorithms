#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
    char name[50];
    int age;
    int followers;
};

struct NodeAvl{
    struct user ur;
    struct NodeAvl *left;
    struct NodeAvl *right;
    int height;
};

int height(struct NodeAvl *node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int getBalanceFactor(struct NodeAvl *node){
    if(node ==NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct NodeAvl *createUserNode(struct user ur){
    struct NodeAvl *newNode = (struct NodeAvl*)malloc(sizeof(struct NodeAvl));
    newNode->ur = ur;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

struct NodeAvl *rightRotate(struct NodeAvl *y){
    struct NodeAvl *x = y->left;
    struct NodeAvl *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

struct NodeAvl *leftRotate(struct NodeAvl *x){
    struct NodeAvl* y = x->right;
    struct NodeAvl* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

struct NodeAvl *insert(struct NodeAvl *root,struct user user){
    if(root==NULL){
        return createUserNode(user);
    }
    if (strcmp(user.name, root->ur.name) < 0) {
        root->left = insert(root->left, user);
    } else if (strcmp(user.name, root->ur.name) > 0) {
        root->right = insert(root->right, user);
    } else {
        return root; 
    }
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && strcmp(user.name, root->left->ur.name) < 0) {
        return rightRotate(root);
    }

    if (balanceFactor < -1 && strcmp(user.name, root->right->ur.name) > 0) {
        return leftRotate(root);
    }

    if (balanceFactor > 1 && strcmp(user.name, root->left->ur.name) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balanceFactor < -1 && strcmp(user.name, root->right->ur.name) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}

struct NodeAvl *findMin(struct NodeAvl *root){
    if(root=NULL){
        return NULL;
    }
    if (root->left == NULL){
        return root;
    }
    return findMin(root->left);
}

struct NodeAvl *deleteNode(struct NodeAvl *root, char *name){
     if (root == NULL) {
        return root;
    }

    if (strcmp(name, root->ur.name) < 0) {
        root->left = deleteNode(root->left, name);
    } else if (strcmp(name, root->ur.name) > 0) {
        root->right = deleteNode(root->right, name);
    } else {
        if (root->left == NULL || root->right == NULL) {
            struct NodeAvl *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            struct NodeAvl* temp = findMin(root->right);
            root->ur = temp->ur;
            root->right = deleteNode(root->right, temp->ur.name);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(struct NodeAvl *root){
    if(root != NULL){
        inOrder(root->left);
        printf("Name: %s, Age: %d, Followers: %d\n", root->ur.name, root->ur.age, root->ur.followers);
        inOrder(root->right);
    }
}

int main(){

    struct NodeAvl *root = NULL;
    root = insert(root, (struct user){"Alice", 25, 1000});
    root = insert(root, (struct user){"Bob", 30, 500});
    root = insert(root, (struct user){"Charlie", 22, 750});
    root = insert(root, (struct user){"David", 28, 800});
    root = insert(root, (struct user){"Eve", 29, 1200});

    printf("After inserting users:\n");
    inOrder(root);

    // Remove user "Charlie"
    root = deleteNode(root, "Charlie");

    printf("\nAfter deleting Charlie:\n");
    inOrder(root);
    return 0;
}

