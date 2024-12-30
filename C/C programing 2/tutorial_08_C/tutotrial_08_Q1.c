#include<stdio.h>
#include<string.h>

struct Customer{
    char name[50];
    int accountNumber;
    double balance;
};

void printBalance(struct Customer customers[],int num){
    printf("Customers with balance less than Rs.200:\n");
    for(int i=0; i<num; i++){
        if(customers[i].balance < 200){
            printf("%s\n",customers[i].name);
        }
    }
}

void addBalaceforCustomers(struct Customer customer[],int num){
    printf("Update balance for > 1000: \n");
    for(int i=0; i<num; i++){
        if(customer[i].balance > 1000){
            customer[i].balance = customer[i].balance + 10;
            printf("%s: Rs.%lf\n",customer[i].name,customer[i].balance);
        }
    }
}
int main(){
    struct Customer customer[] = {
        {"Bob",1,2000},
        {"John",2,200},
        {"Jane",3,50},
        {"David",4,20},
        {"Matt",5,240},
        {"Jack",6,1500},
        {"Emily",7,800},
        {"Jones",8,1240},
        {"Rocky",9,2345},
        {"Maxx",10,75}
    };
    int num = sizeof(customer)/sizeof(customer[0]);
    printBalance(customer,num);
    printf("\n");
    addBalaceforCustomers(customer,num);
    return 0;
}