#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 10

struct Book {
    int accessionNumber;
    char author[50];
    char title[100];
    int isIssued;
};

void displayBookInfo(struct Book book) {
    printf("Accession Number: %d\n", book.accessionNumber);
    printf("Author: %s\n", book.author);
    printf("Title: %s\n", book.title);
    printf("Is Issued: %s\n", book.isIssued ? "Yes" : "No");
    printf("\n");
}

void addNewBook(struct Book library[], int *totalBooks, int accessionNumber, const char *author, const char *title) {
    if (*totalBooks < MAX_BOOKS) {
        library[*totalBooks].accessionNumber = accessionNumber;
        strcpy(library[*totalBooks].author, author);
        strcpy(library[*totalBooks].title, title);
        library[*totalBooks].isIssued = 0;
        (*totalBooks)++;
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void displayBooksByAuthor(struct Book library[], int totalBooks, const char *author) {
    printf("Books by Author '%s':\n", author);
    for (int i = 0; i < totalBooks; i++) {
        if (strcmp(library[i].author, author) == 0) {
            displayBookInfo(library[i]);
        }
    }
}

int countBooksByTitle(struct Book library[], int totalBooks, const char *title) {
    int count = 0;
    for (int i = 0; i < totalBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            count++;
        }
    }
    return count;
}

void displayAllBooks(struct Book library[], int totalBooks) {
    printf("Library Book Information:\n");
    for (int i = 0; i < totalBooks; i++) {
        displayBookInfo(library[i]);
    }
}

int main() {
    struct Book library[MAX_BOOKS];
    int totalBooks = 0;

    // Add new books
    addNewBook(library, &totalBooks, 1, "John Doe", "Introduction to Programming");
    addNewBook(library, &totalBooks, 2, "Jane Smith", "Data Structures and Algorithms");
    addNewBook(library, &totalBooks, 3, "Alice Johnson", "C Programming for Beginners");

    // Display all books
    displayAllBooks(library, totalBooks);

    // Display books by author
    displayBooksByAuthor(library, totalBooks, "Jane Smith");

    // Display number of books by title
    int count = countBooksByTitle(library, totalBooks, "Introduction to Programming");
    printf("Number of books with title 'Introduction to Programming': %d\n", count);

    // Display total number of books
    printf("Total number of books in the library: %d\n", totalBooks);

    return 0;
}
