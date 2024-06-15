#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int id;
    char name[15];
    float GPA;
    struct node *next;
};
//create the nodes and function to add details
struct node* createStudents(int id, const char* name, float GPA){
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); //create a node
    newnode->id=id;
    strncpy(newnode->name, name, sizeof(newnode->name) - 1); //this return the copy of string
    newnode->name[sizeof(newnode->name) - 1] = '\0';//set the null-operator to end of the string
    newnode->GPA = GPA;
    newnode->next = NULL;
    return newnode;
}
//function to add students
void addStudents(struct node **head,int id,const char* name,float GPA){
    struct node *newnode = createStudents(id,name,GPA);//set values
    if(*head == NULL || GPA > (*head)->GPA){
        newnode->next= (*head);//if head null or GPA greater than first node
        (*head) = newnode;  //set it's as first node
    }
    else{
        struct node *current = *head;
        while (current->next != NULL && GPA <= current->next->GPA) {
            current = current->next; //search the maching position
        }
        newnode->next = current->next; //set the addresses
        current->next = newnode;
    }
    
}
int deleteStudent(struct node **head,int id){
    struct node *temp = *head; //use to traverse
    struct node *prev = NULL; //traverse one before the temp
    while (temp != NULL && temp->id == id){
        prev =temp; 
        temp = temp->next; //find the maching node
    }
    if(temp==NULL){
        return 0; //fail to find the maching one
    }
    if(prev == NULL){
        *head = temp->next; //only one node in the list
    }
    else{
        prev->next = temp->next; //set the addresses
    }
    free(temp); //free the space the allocate in the memory
    return 1;
}
struct node **listtoarray(struct node *head, int *size){
    struct node **arr = NULL; //create a pointer to pointer
    int count = 0; //for traversing

    struct node *current = head;
    while(current != NULL){
        arr = realloc(arr, (count + 1)*sizeof(struct node));
        arr[count] = current; //set the values to the array elements
        current = current->next;
        count++;
    }
    *size = count; //set the array size
    return arr; //return the array
}
void printList(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("ID: %d, Name: %s, GPA: %.1f\n",temp->id,temp->name,temp->GPA);
        temp = temp->next;
    }
}
void freeList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next; //free the space
        free(temp);
    }
}
int main(){
    struct node *head =NULL;
    //addStudents(&head,1,"rash",3.5);
    //printList(head);
    addStudents(&head, 1, "Alice", 3.9);
    addStudents(&head, 2, "Bob", 3.7);
    addStudents(&head, 3, "Charlie", 3.5);
    addStudents(&head, 4, "David", 3.6);
    addStudents(&head, 5, "Eva", 3.8);
    addStudents(&head, 6, "Frank", 3.1);
    addStudents(&head, 7, "Grace", 3.4);
    addStudents(&head, 8, "Hank", 3.3);
    addStudents(&head, 9, "Ivy", 3.2);
    addStudents(&head, 10, "Jack", 3.0);

    printf("List after adding students: \n");
    printList(head);

    printf("Delete student in the list\n");
    deleteStudent(&head,1);
    deleteStudent(&head,5);
    printf("List after deleting the students: \n");
    printList(head);

    int arraysize;
    struct node **arr = listtoarray(head,&arraysize); //call the function.print array
    printf("\nList to array\n");
    for(int i=0; i<arraysize; i++){
        printf("Array[%d] -> ID: %d, Name: %s, GPA: %.1f\n",i,arr[i]->id,arr[i]->name,arr[i]->GPA);
    }
    freeList(head);
    free(arr);
    return 0;
}