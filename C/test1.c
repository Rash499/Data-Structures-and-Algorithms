#include<stdio.h>
int main(){
    int a;
    int *p;
    p = &a;
    printf("Address of p is %d\n",p);
    printf("Address of p+1 is %d\n",p+1);
}