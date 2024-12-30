#include<stdio.h>
#include<string.h>
struct Book{
    int number;
    char author[50];
    char title[50];
    int flag;
};
void DisplayBookInformation(struct Book book){ //function to display books
    printf("Accession Number:%d, Author: %s, Title: %s,Issued: %s\n",book.number,book.author,book.title,book.flag ? "Yes" : "No");
}
void AddNewBook(struct Book book[],int number,char author[],char title[],int flag,int *size){
    book[*size].number = number; //get the size by pointer call by reference
    strcpy(book[*size].author,author);
    strcpy(book[*size].title,title);
    book[*size].flag = 0;
    (*size)++; //increment the size
}
void DisplayBooksofAuthor(struct Book book[],char *author,int num){
    for(int i=0; i<num; i++){  //function to display books of authors
        if(strcmp(book[i].author,author)==0){ //check the condition
            DisplayBookInformation(book[i]); //call the display function
        }
    }
}
int DisplayBooksofTitle(struct Book book[],char *title,int num){
    int count = 0;
    for(int i=0; i<num; i++){
        if(strcmp(book[i].title,title) == 0){ //compare the strings
            count++; //increment the count by one
        } 
    }
    return count; //return the count back
}
void DisplayAllBooks(struct Book book[],int num){
    for(int i=0; i<num; i++){
        DisplayBookInformation(book[i]); //call the display book information function
    }
}
int totalNumberofBooks(struct Book book[],int num){
    return num; //return the size of the struct array
}
void issueBook(struct Book book[],int num,int number){
    for(int i=0; i<num; i++){
        if(book[i].number==number){ //check the maching number
            if(book[i].flag==0){ //check if it's not issued
                 book[i].flag = 1; 
                 printf("book number %d has been issued\n",number);
                 break;
            }
            else{
            printf("book number %d already issued\n",number);
           }
        }
        
    }
}
int main(){
    int n1;
    struct Book book[] = {
        {1,"john","The Sea",0},
        {2,"Emily","Mist",0},
        {3,"Charles","Earth",0},
    };
    int size = sizeof(book)/sizeof(book[0]);
    while(1){
        printf("Display Book Information: 1\n");
        printf("Add a new Book          : 2\n");
        printf("Displa books of a author: 3\n");
        printf("Display books of title  : 4\n");
        printf("Display total books     : 5\n");
        printf("Issue a book            : 6\n");
        printf("exit                    : 7\n");
        printf("Enter the number: \n");
        scanf("%d",&n1);
        if(n1==1){
            DisplayAllBooks(book,size);
        }
        else if(n1==2){
            printf("Enter the Details number,name,title: \n");
            int number;
            char name[50];
            char title[50];
            scanf("%d",&number);
            scanf("%s",name);
            scanf("%s",title);
            AddNewBook(book,number,name,title,0,&size);
        }
        else if(n1==3){
            char name[50];
            scanf("%s",&name);
            DisplayBooksofAuthor(book,name,size);
        }
        else if(n1==4){
            char title[50];
            scanf("%s",&title);
            int n = DisplayBooksofTitle(book,title,size);
            printf("Total Number of Books title: %d\n",n);
        }
        else if(n1==5){       
            printf("Total Number of Books in the library: %d\n",totalNumberofBooks(book,size));
        }
        else if(n1==6){
            int n;
            scanf("%d",&n);
            issueBook(book,size,n);
        }
        else if(n1==7){
            break;
        }
        else{
            printf("error\n");
        }
    }
    
    //get the size
    
   // AddNewBook(book,5,"Emily","Matrix",0,&size);
   return 0;
}