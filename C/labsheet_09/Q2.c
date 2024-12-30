#include <stdio.h>

struct data{
    char emp_name[20];
    int emp_no;
    float salary;
    int OT;
};
float calculateNetSalary(float basicSalary, int otHours) {
    float otAmount = otHours * 15.0;
    return basicSalary + (basicSalary * 0.35) + otAmount;
}
float totalSalaryExpenses(struct data DATA[], int numEmployees) {
    float total = 0.0;
    for (int i = 0; i < numEmployees; i++) {
        total += calculateNetSalary(DATA[i].salary, DATA[i].OT);
    }
    return total;
}

int main(){
    struct data DATA[] = {{"Nimal",001,35000.00,9},
                        {"Kamal",002,45000.00,10},
                        {"Sunil",003,55000.00,2},
                        {"Mallika",004,25000.00,5}};
    FILE *file = fopen("C:\\Users\\PR\\OneDrive\\Documents\\C and DSA\\C\\labsheet_09\\dataQ2.txt","w");
    for(int i=0; i<4; i++){
        fprintf(file,"%s   %d    %f    %d\n",DATA[i].emp_name,DATA[i].emp_no,DATA[i].salary,DATA[i].OT);
    }
    fprintf(file, "Employee No\tBasic Salary\tOT Amount\t\tNet Salary\n");

    float totalExpenses = 0.0;
    for (int i = 0; i < 4; i++) {
        float net = calculateNetSalary(DATA[i].salary, DATA[i].OT);
        fprintf(file, "%d\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f\n", DATA[i].emp_no, DATA[i].salary, DATA[i].OT * 15.0, net);
        totalExpenses += net;
    }

    fclose(file);

    printf("Total Salary Expenses: %.2f\n", totalExpenses);
    return 0;
}