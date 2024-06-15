#include<stdio.h>
int main(){
    char fname[] = "Rashmika";
    char lanme[] = "Dilmin";
    char address[] = "Patisaragewaththa katukurunda habaraduwa";
    char dob[] = "2001.06.30";
    int indexnumber = 221040;

    printf("Name: %s %s \n",fname,lanme);
    printf("Index Number: %d\n",indexnumber);
    printf("Address: %s\n",address);
    printf("Date of Birth: %s\n\n",dob);

    printf("\"Hello\"\nWhat are you doing ?\n\'my first day\'\n\n");

    char First = 'A';
    char second = 'C';
    char third = 'T';
    int age = 3;

    printf("how old is your %c%c%c\n%d years",second,First,third,age);
    return 0;

}