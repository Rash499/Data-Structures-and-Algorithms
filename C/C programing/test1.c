#include <stdio.h>
    int main()
    {
        int rows;
        printf("How many times you want to loops? ");
        scanf("%d",&rows);
        
        for(int i =0; i<rows; i++){
        int x;
        char C;
        printf("Enter your number: \n");
        printf("Press Y to continue! \n");
        scanf("%d %c",&x,&C);
        if(C == 'Y'){
           if(x%2 == 1){
            printf("%d is a ODD number \n",x);
            }
           else{
            printf("%d is a EVEN number \n",x);
            }
        }
        else {
            printf("You exit from the program");
            break;
        }
        
        }
        
    }
    
