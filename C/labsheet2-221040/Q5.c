#include<stdio.h>
int main(){
    float x =2.0;
    int n =3;
    float pow  =1;
    for(int i=1; i<=5; i++){
      pow = pow * x;
    }
    printf("%f",pow);
}