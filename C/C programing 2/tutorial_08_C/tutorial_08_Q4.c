#include<stdio.h>
struct Employee{
    char name[50];
    float salary;
    int hours;
};

int main(){
    struct Employee emp[] = {
        { "John",1200,8},
        { "Jane",800,8},
        { "Cathy",1300,10},
        { "Maxx",1500,12},
        { "David",700,8},
        { "Emily",1000,10}
    };
    int size = sizeof(emp)/sizeof(emp[0]);
    printf("Salary before: \nName Salary Hours\n");
    printf("_______________________________________\n");
    for(int i=0; i<size; i++){
        printf("%s %.2f %d\n",emp[i].name,emp[i].salary,emp[i].hours);
    }
    for(int i=0; i<size; i++){
        if(emp[i].hours==8){
            emp[i].salary = emp[i].salary + 500;
        }
        else if(emp[i].hours==10){
            emp[i].salary = emp[i].salary + 1000;
        }
        else if(emp[i].hours==12){
            emp[i].salary = emp[i].salary + 1500;
        }
    }
   printf("\n\nSalary After: \nName Salary Hours\n");
   printf("___________________________________________\n");
   for(int i=0; i<size; i++){
        printf("%s %.2f %d\n",emp[i].name,emp[i].salary,emp[i].hours);
    }
    return 0;
}