#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 8
char array[MAX];
bool Condition1(char *arr[],int size){
    //int size = sizeof(arr)/sizeof(arr[0]);
    if(size != 8){
        return false;
    }
    else{
        return true;
    }
}
bool Condition2(char *arr[]){
    if(arr[0] == 'S'){
        return true;
    }
    else{
        return false;
    }
}
bool Condition3(char *arr[]){
    if(arr[1] == '/' && arr[4] == '/'){
        return true;
    }
    else{
        return false;
    }
}
bool Condition4(char *arr[]){
    if(isdigit(arr[2]) && isdigit(arr[4])){
        return true;
    }
    else{
        return false;
    }
}
bool Condition5(char *arr[]){
    if(isdigit(arr[5]) && isdigit(arr[6]) && isdigit(arr[7])){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    printf("Enter the index number: ");
    scanf("%s",&array);

    printf("--------------------VALIDATING REGISTRATION NUMBER: ");
     for(int i=0; i<MAX; i++){
       printf("%c",array[i]);   
    }
    printf("---------------\n\n");
    printf("%c",array[0]);

/*
    printf("Condition 1 : There are exacatly 8 characters: \n");
    if(Condition1(array,MAX)){
        printf("The first condition satisfies\n");
    }
    else{
        printf("The first condition not satisfies\n");
    }


    printf("\nCondition 2 : First letter should be 'S'\n");
    if(Condition2(array)){
        printf("The second condition satisfies\n");
    }
    else{
        printf("The second condition not satisfies\n");
    }


    printf("\nThere should be excatly two '/'s\n");
    if(Condition3(array)){
        printf("The third condition satisfies\n");
    }
    else{
        printf("The third condition not satisfies\n");
    }*/
    return 0;
    //(arr[2] == '0' || arr[2] == '1' || arr[2] == '2' || arr[2] == '3' || arr[2] == '4' ||
    //arr[2] == '5' || arr[2] == '6' || arr[2] == '7' || arr[2] == '8' || arr[2] == '9') &&
    //(arr[3] == '0' || arr[3] == '1' || arr[3] == '2' || arr[3] == '3' || arr[3] == '4' ||
    //arr[3] == '5' || arr[3] == '6' || arr[3] == '7' || arr[3] == '8' || arr[3] == '9'))
}