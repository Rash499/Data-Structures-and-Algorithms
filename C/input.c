#include <stdio.h>

int main(){
    int x;
    char y;
    char fullname[50];

    printf("What is your full name?: \n");
    fgets(fullname,sizeof(fullname),stdin);
    
    printf("Enter your marks and Grade?: \n");
    scanf("%d %c",&x,&y);

    printf("Your mark is: %d\n",x);
    printf("Your grade is: %c\n",y);
    printf("Hello %s",fullname);
}