#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    char* names[9] = {"one","two","three","four","five","six","seven","eight","nine"};
    for(int i= a; i <= b; i++ ){
        if(i >= 1 && i <= 9){
            printf("%s\n",names[i-1]);
        }
        else if(i > 9 && i%2==0){
            printf("Even \n");
        }
        else if(i > 9 && i%2==1){
            printf("Odd \n");
        }
        else{
            printf("Error");
            break;
        }
        
    }
    return 0;
}