#include<stdio.h>
int main(){
    float inch;
    float feet;
    float height;
    printf("enter the inches: \n");
    scanf("%f",&inch);
    printf("enter the feet: \n");
    scanf("%f",&feet);

    height = inch*2.54 + feet*12*2.54;
    printf("%f",height);

}