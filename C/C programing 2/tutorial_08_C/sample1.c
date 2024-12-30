#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 10

// Structure to store customer information
struct Customer {
    char name[50];
    int accountNumber;
    double balance;
};

// Function to print names of customers with balance less than Rs.200
void printLowBalanceCustomers(struct Customer customers[], int count) {
    printf("Customers with balance less than Rs.200:\n");
    for (int i = 0; i < count; i++) {
        if (customers[i].balance < 200) {
            printf("%s\n", customers[i].name);
        }
    }
}

// Function to add Rs.100 to balance of customers with balance > Rs.1000
void addBalanceForRichCustomers(struct Customer customers[], int count) {
    printf("Updated balances for customers with balance > Rs.1000:\n");
    for (int i = 0; i < count; i++) {
        if (customers[i].balance > 1000) {
            customers[i].balance += 100;
            printf("%s: Rs.%.2lf\n", customers[i].name, customers[i].balance);
        }
    }
}

int main() {
    // Create an array of Customer structures
    struct Customer customers[MAX_CUSTOMERS] = {
        {"Alice", 101, 1500.50},
        {"Bob", 102, 450.25},
        {"Charlie", 103, 80.75},
        {"David", 104, 1100.90},
        // Add more customers here
    };

    int numCustomers = sizeof(customers) / sizeof(customers[0]);

    // Print names of customers with low balance
    printLowBalanceCustomers(customers, numCustomers);

    printf("\n");

    // Add balance for rich customers and print updated balances
    addBalanceForRichCustomers(customers, numCustomers);

    return 0;
}
