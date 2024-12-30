#include<stdio.h>
int main(){
    int years;
    int days;
    printf("Enter years: \n");
    scanf("%d",&years);
    printf("Enter days: \n");
    scanf("%d",&days);
    int min = 60*60*24*365*years + 60*60*24*days;
    printf("%d",min);
}