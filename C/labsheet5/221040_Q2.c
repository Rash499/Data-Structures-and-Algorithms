#include<stdio.h>
    int arr[3][3] = { {3,5,7},
                    {1,6,5},
                    {4,9,8}};
    int arr2[3][3] = {{6,0,2},
                      {4,7,1},
                      {7,2,1}};
    int arr3[3][3];
void add(){
    printf("ADIITION\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr3[i][j] = arr[i][j] + arr2[i][j];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d  ",arr3[i][j]);
        }
        printf("\n");
    }
}
void subtraction(){
    printf("SUBTRACTION\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr3[i][j] = arr[i][j] - arr2[i][j];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d  ",arr3[i][j]);
        }
        printf("\n");
    }
}
void multipication(){
    printf("Multipication\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr3[i][j] = (arr[i][j]*arr2[i][j] + arr[i][j+1]*arr2[i+1][j] + arr[i][j+2]*arr2[i+2][j]);
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d  ",arr3[i][j]);
        }
        printf("\n");
    }
}
int main(){
    add();
    subtraction();
    multipication();
    return 0;
}