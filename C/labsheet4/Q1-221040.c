#include<stdio.h>
#include<math.h>
float tot =0;
void name(float a,float b){

   for(int i = b; i<=a; i++){
        tot = tot + pow(i,2);
   }
   printf("Sum: %f",tot);
}
int main(){
    float a,b;
    name(8,5);
}