#include<stdio.h>
int main(){
    int a; 
    int *p;
    a = 10;
    p = &a;
    printf("%d\n",p);
    printf("%d\n",&a);
    printf("%d\n",&p);
    printf("%d,%d\n",*p,a);

    int b =20;
    *p = b;
    printf("%d\n",p);
    printf("%d\n",&b);
    printf("%d\n",*p);
}