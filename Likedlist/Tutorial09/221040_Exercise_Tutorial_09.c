#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *left;
    struct node *right;
};
struct node *createTree(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode; 
}
struct node *insert(struct node *root,int data){
    if(root == NULL){
        return createTree(data);
    }
    if(root->value < data){
        root->right = insert(root->right,data);
    }
    else if(root->value > data){
        root->left = insert(root->left,data);
    }
    return root;
}
void in_order_traversal(struct node *root){
    if(root != NULL){
        in_order_traversal(root->left);
        printf("%d ",root->value);
        in_order_traversal(root->right);
    }
}
int main(){
    struct node *root = NULL;

    root = insert(root,10);
    root = insert(root,70);
    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,45);
    root = insert(root,23);
    root = insert(root,70);

    in_order_traversal(root);
    return 0;
}