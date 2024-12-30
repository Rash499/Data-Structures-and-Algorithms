#include<stdio.h>
#include<stdlib.h>
int num;
int random_num;
void check(int data,int random_num){
    if(data == 1 && random_num == 1){
        printf("Compuer gives: %d ",random_num);
        printf("Match tied\n");
    }
    else if(data == 2 && random_num == 1){
        printf("Compuer gives: %d ",random_num);
        printf("You won\n");
    }
    else if(data == 3 && random_num == 1){
        printf("Compuer gives: %d ",random_num);
        printf("You lose\n");
    }
    else if(data == 1 && random_num == 2){
        printf("Compuer gives: %d ",random_num);
        printf("Match lose\n");
    }
    else if(data == 2 && random_num == 2){
        printf("Compuer gives: %d ",random_num);
        printf("Match tied\n");
    }
    else if(data == 3 && random_num == 2){
        printf("Compuer gives: %d ",random_num);
        printf("You won\n");
    }
    else if(data == 1 && random_num == 3){
        printf("Compuer gives: %d ",random_num);
        printf("Match won\n");
    }
    else if(data == 2 && random_num == 1){
        printf("Compuer gives: %d ",random_num);
        printf("You lose\n");
    }
    else if(data == 3 && random_num == 3){
        printf("Compuer gives: %d ",random_num);
        printf("Match tied\n");
    }
}
int main(){
    for(int i =0; i<10; i++){
        printf("Enter rock=1 , paper=2 , scissor=3: ");
        scanf("%d",&num);
        if(num != 1 && num != 2 && num !=3){
            break;
        }
        else{
            random_num = rand() % (3 + 1 - 1) + 1;
            check(num,random_num);
        }
        
    }
 
}