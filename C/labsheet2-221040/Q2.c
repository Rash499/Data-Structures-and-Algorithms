#include<stdio.h>
int main(){
    int a = 1;
    int b;
    printf("%d\n",a);
    b = a++;  //a increment by 1 a=2 and and original value assing to b 
    printf("%d\n",b); //b=1
    b = ++a; //a increment by 1 a=3 and assign to b
    printf("%d\n",b);//b=3
    b = a--; //a decrement by 1 a=2 and original value assign to b
    printf("%d\n",b);//b=3
    b = --a; //a decrement by 1 a=1 and assign to b
    printf("%d\n",b); //b=1

    return 0;
}