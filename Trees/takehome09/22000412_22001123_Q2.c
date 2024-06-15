#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
bool isSymmetricUtil(struct Node *leftSubTree,struct Node *rightSubTree){
    if(leftSubTree == NULL && rightSubTree == NULL){
        return true;
    }
    if(leftSubTree == NULL || rightSubTree == NULL){
        return false;
    }
    return (leftSubTree->data == rightSubTree->data) && isSymmetricUtil(leftSubTree->left,rightSubTree->right) && isSymmetricUtil(leftSubTree->right,rightSubTree->left);

}
bool isSymmetric(struct Node *root){
    if(root == NULL){
        return true;
    }
    return isSymmetricUtil(root->left,root->right);
}
int main(){
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if(isSymmetric(root)){
        printf("The binary tree is symmetric\n");
    }
    else{
        printf("The binary tree is not symmetric\n");
    }
    return 0;
}