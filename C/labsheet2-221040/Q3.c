#include<stdio.h>
int main(){
    int m =40;
    int n =20;
    int o =20;
    int p =30;

    if(m>n && m != 0){
        printf("%d\n",1);
    }
    else{
        printf("%d\n",0);
    }
    
    if(o>p || p !=0){
        printf("%d\n",1);
    }
    else{
        printf("%d\n",0);
    }
    if(!(m>n && m != 0)){
        printf("%d\n",1);
    }
    else{
        printf("%d\n",0);
    }
}