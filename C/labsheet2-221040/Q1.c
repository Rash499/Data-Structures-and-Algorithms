#include<stdio.h>
int main(){
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    float result;
    result = (float)(a+b)/(c+d);
    printf("%.2f\n",result); //0.43
    result = (a+b/(c+d));
    printf("%.2f\n",result);
    result = (a+b)/c+d;
    printf("%.2f\n",result);//5.00
    result = (float) a*b/c*d;
    printf("%.2f",result); //2.67

    return 0;

}