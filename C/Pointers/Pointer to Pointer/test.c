#include<stdio.h>
int main(){
    int x = 5;
    int *p = &x;
    *p = 6;
    int **q = &p;
    int ***r = &q;
    ***r = 10;

    printf("%d\n",*p);
    printf("%d\n",*q);
    printf("%d\n",*(*q));
    printf("%d\n",*r);
    printf("%d\n",**r);
    printf("%d\n",***r);
}