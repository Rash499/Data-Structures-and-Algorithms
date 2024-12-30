#include <stdio.h>
#include <stdlib.h>

// Binary tree node consists of data, a
// pointer to the left child and a
// pointer to the right child
struct node {
	int data;
	struct node* left;
	struct node* right;
};

// Function to create new Binary Tree node
struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Function to return the sum of all
// the nodes at Kth level using
// level order traversal
int sumOfNodesAtNthLevel(struct node* root,int k)
{

	// If the current node is NULL
	if (root == NULL)
		return 0;

	// Create Queue
	struct node** que = (struct node**)malloc(10000 * sizeof(struct node*));
	int front = -1, rear = -1;

	// Enqueue the root node
	que[++rear] = root;

	// Level is used to track
	// the current level
	int level = 0;

	// To store the sum of nodes
	// at the Kth level
	int sum = 0;

	// flag is used to break out of
	// the loop after the sum of all
	// the nodes at Nth level is found
	int flag = 0;

	// Iterate the queue till its not empty
	while (front != rear) {

		// Calculate the number of nodes
		// in the current level
		int size = rear - front;

		// Process each node of the current
		// level and enqueue their left
		// and right child to the queue
		while (size--) {
			struct node* ptr = que[++front];

			// If the current level matches the
			// required level then calculate the
			// sum of all the nodes at that level
			if (level == k) {

				// Flag initialized to 1
				// indicates that sum of the
				// required level is calculated
				flag = 1;

				// Calculating the sum of the nodes
				sum += ptr->data;
			}
			else {

				// Traverse to the left child
				if (ptr->left)
					que[++rear] = ptr->left;

				// Traverse to the right child
				if (ptr->right)
					que[++rear] = ptr->right;
			}
		}

		// Increment the variable level
		// by 1 for each level
		level++;

		// Break out from the loop after the sum
		// of nodes at K level is found
		if (flag == 1)
			break;
	}
	free(que);
	return sum;
}

// Driver code
int main()
{
	struct node* root = newNode(50);
	root->left = newNode(30);
	root->right = newNode(70);
	root->left->left = newNode(20);
	root->left->right = newNode(40);
	root->right->left = newNode(60);
	int level = 2;
	int result = sumOfNodesAtNthLevel(root, level);

	// Printing the result
	printf("%d\n", result);

	return 0;
}
