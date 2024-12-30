#include<stdio.h>

int main(){
 int arr[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<=10; j++){
            arr[i][j] = (i+1)*(j+1);
        }
    }
    printf("            ************** Mulitipication Table **************\n\n");
    printf("     ");
    for(int i=1; i<=10; i++){
        printf("\t%d",i);
    }
    printf("\n\n");
    for(int i=0; i<10; i++){
        printf("%d  > ",i+1);
        for(int j=0; j<10; j++){
            printf("\t%d",arr[i][j]);
        }
        
        printf("\n");
        printf("________________________________________________________________________________\n\n");
    }
    return 0;
}