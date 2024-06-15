#include<stdio.h>
#include<string.h>
struct Date{
    int day;
    int month;
    int year;
};
int IsLeapYear(int year){ //function check leap year
    return ((year%4==0 && year%100==0) || year%400==0);
}
void addDays(struct Date *date,int num){ //create self reference pointer to access structure elemnts
     int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     //store days in months
     while(num > 0){
        if(IsLeapYear(date->year)) {
            daysInMonth[2] = 29; //if leap year set to 29
        }
        else{
            daysInMonth[2] = 28;
        }
        if(date->day + num <= daysInMonth[date->month]){
            date->day += num; //num lessthan or equal to its month days
            num = 0; // add num set num to 0
        }
        else{
            num -= (daysInMonth[date->month] - date->day + 1);
            //else subtract the current day+1 from month's days
            //again subtract it from num
            date->day = 1; //set the first day of the month
            date->month++; //increment the month by one

            if(date->month > 12){
                date->month = 1;
                date->year++; //set for next year
            }
        }
     }
}
int main(){
    struct Date current = {23,8,2023};
    int daysAdd = 45;
    addDays(&current,daysAdd);
    printf("Current Date: %d %d %d",current.day,current.month,current.year);

    return 0;
}