#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10

struct TreeNode {
    char name[100];
    struct TreeNode *children[MAX_CHILDREN];
    int num_children;
};

struct TreeNode *create_node(const char *name) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node != NULL) {
        strcpy(node->name, name);
        node->num_children = 0;
        for (int i = 0; i < MAX_CHILDREN; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

void add_child(struct TreeNode *parent, struct TreeNode *child) {
    if (parent->num_children < MAX_CHILDREN) {
        parent->children[parent->num_children++] = child;
    }
}

void breadth_first_traversal(struct TreeNode *root) {
    if (root == NULL) return;

    struct TreeNode *queue[MAX_CHILDREN];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode *current = queue[front++];
        printf("%s\n", current->name);
        for (int i = 0; i < current->num_children; i++) {
            queue[rear++] = current->children[i];
        }
    }
}

void depth_first_traversal(struct TreeNode *root) {
    if (root == NULL) return;

    printf("%s\n", root->name);
    for (int i = 0; i < root->num_children; i++) {
        depth_first_traversal(root->children[i]);
    }
}

int main() {
    int levels;
    printf("Enter the number of levels in the file system tree: ");
    scanf("%d", &levels);

    struct TreeNode *root = NULL;
    for (int i = 0; i < levels; i++) {
        int num_nodes;
        printf("Enter the number of nodes in level %d: ", i + 1);
        scanf("%d", &num_nodes);

        for (int j = 0; j < num_nodes; j++) {
            char name[100];
            printf("Enter the name of node %d in level %d: ", j + 1, i + 1);
            scanf("%s", name);

            struct TreeNode *node = create_node(name);
            if (i == 0) {
                root = node;
            } else {
                struct TreeNode *parent;
                printf("Enter the name of parent node of %s: ", name);
                scanf("%s", name);
                parent = root;
                add_child(parent, node);
            }
        }
    }

    printf("\nBreadth-First Traversal:\n");
    breadth_first_traversal(root);

    printf("\nDepth-First Traversal:\n");
    depth_first_traversal(root);

    return 0;
}
