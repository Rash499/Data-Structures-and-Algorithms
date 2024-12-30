// C program for the above operation
#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct node {
	int info;
	struct node* next;
};

// Pointer to last node in list
struct node* last = NULL;

// Function to add a new node
// at the end of the list
void addatlast(int data)
{
	// Initialize a new node
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	// If the new node is the only
	// node in the list
	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}

	// Else the new node will be the
	// last node and will contain
	// the reference of head node
	else {
		temp->info = data;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

// Function to delete the first
// element of the list
void deletefirst()
{
	struct node* temp;

	// If list is empty
	if (last == NULL)
		printf("\nList is empty.\n");

	// Else last node now contains
	// reference of the second node
	// in the list because the
	// list is circular
	else {
		temp = last->next;
		last->next = temp->next;
		free(temp);
	}
}

// Function to print the list
void viewList()
{
	// If list is empty
	if (last == NULL)
		printf("\nList is empty\n");

	// Else print the list
	else {
		struct node* temp;
		temp = last->next;
		do {
			printf("\nData = %d", temp->info);
			temp = temp->next;
		} while (temp != last->next);
	}
}

// Driver Code
int main()
{
	// Initialize the list
	addatlast(10);
	addatlast(20);
	addatlast(30);

	printf("Before deletion:\n");
	viewList();

	// Function Call
	deletefirst();

	// Print list
	printf("\n\nAfter deletion:\n");
	viewList();

	return 0;
}
