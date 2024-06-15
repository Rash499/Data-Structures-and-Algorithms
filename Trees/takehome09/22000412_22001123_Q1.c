#include<stdio.h>
#include<stdlib.h>

struct Node{
    char name[50];
    struct Node *left;
    struct Node *right;
    int num;
};
struct Node *createNode(const char *name){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name,name);
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->num=0;
    return newNode;
}
int calculateSubordinates(struct Node* root) {
    if(root == NULL){
        return 0;
    }
    int leftsubordinates = calculateSubordinates(root->left);
    int rightsubordinates = calculateSubordinates(root->right);

    root->num = leftsubordinates + rightsubordinates;
    return root->num + 1;
}
int getTotalSubordinates(struct Node *root){
    if(root==NULL){
        return 0;
    }
    return root->num + 1;
}
void inorderTraversal(struct Node *root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("Employee: %s, Total Subordinates: %d\n",root->name,getTotalSubordinates(root));
        inorderTraversal(root->right);
    }
}
int main(){
    struct Node *root = createNode("CEO");
    root->left = createNode("Manager 1");
    root->left->left = createNode("Employee 1");
    root->left->right = createNode("Employee 2");
    root->left->right->left = createNode("Employee 3");
    root->right = createNode("Manager 2");
    root->right->left = createNode("Employee 4");

    calculateSubordinates(root);
    printf("Employee Names and Total Subordinates:\n");
    inorderTraversal(root);
    return 0;
}