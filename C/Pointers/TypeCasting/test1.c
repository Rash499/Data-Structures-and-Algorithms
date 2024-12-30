#include<stdio.h>
int main(){
    int a = 1025;
    int *p = &a;
    printf("%d\n",p+1);
    printf("%d\n",*p);
    printf("%d\n",&a);
    printf("%d\n",&p);
    printf("%d",a);
}