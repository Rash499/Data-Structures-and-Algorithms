#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 8
char array[MAX];
bool Condition1(char *arr[],int size1){
    //int size = sizeof(arr)/sizeof(arr[0]);
    if(size1 != 8){
        return false;
    }
    else{
        return true;
    }
}
bool Condition2(char arr){
    if(arr == 'S'){
        return true;
    }
    else{
        return false;
    }
}
bool Condition3(char arr1,char arr2){
    if(arr1 == '/' && arr2 == '/'){
        return true;
    }
    else{
        return false;
    }
}
bool Condition4(char arr1,char arr2){
    if((arr1>= '0' && arr1<= '9') && (arr2>= '0' && arr2<= '9') ){
        return true;
    }
    else{
        return false;
    }
}
bool Condition5(char arr1,char arr2,char arr3){
    if((arr1>= '0' && arr1<= '9') && (arr2>= '0' && arr2<= '9') && (arr3>= '0' && arr3<= '9')){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int count =0;
    printf("Enter the index number: ");
    scanf("%s",&array);
    int size = sizeof(array)/sizeof(array[0]);
    printf("--------------------VALIDATING REGISTRATION NUMBER: ");
     for(int i=0; i<size; i++){
       printf("%c",array[i]);   
    }
    printf("---------------\n\n");

//-------------------------------------------------------------------------------
    printf("Condition 1 : There are exacatly 8 characters: \n");
    if(Condition1(array,MAX)){
        printf("\t\tThe first condition satisfies\n");
        count++;
    }
    else{
        printf("\t\tThe first condition not satisfies\n");
    }

//---------------------------------------------------------------------------
    printf("\nCondition 2 : First letter should be 'S'\n");
    if(Condition2(array[0])){
        printf("\t\tThe second condition satisfies\n");
        count++;
    }
    else{
        printf("\t\tThe second condition not satisfies\n");
    }

//----------------------------------------------------------------------------
    printf("\nThere should be excatly two '/'s\n");
    if(Condition3(array[1],array[4])){
        printf("\t\tThe third condition satisfies\n");
        count++;
    }
    else{
        printf("\t\tThe third condition not satisfies\n");
    }
//----------------------------------------------------------------------------
    printf("\nThe year should represented by two digits in between '/'s\n");
    if(Condition4(array[2],array[3])){
        printf("\t\tThe fourth condition satisfies\n");
        count++;
    }
    else{
        printf("\t\tThe fourth condition not satisfies\n");
    }
//--------------------------------------------------------------------------------
    printf("\nLast three digits immediatley after the second slash represent the student number\n");
    if(Condition5(array[5],array[6],array[7])){
        printf("\t\tThe fifth condition satisfies\n");
        count++;
    }
    else{
        printf("\t\tThe fifth condition not satisfies\n");
    }
    if(count == 5){
        printf("-------------------THE REGISTRATION NUMBER IS VALID----------------------");
    }
    else{
        printf("-------------------THE REGISTRATION NUMBER IS NOT VALID----------------------");
    }
    return 0;
    //(arr[2] == '0' || arr[2] == '1' || arr[2] == '2' || arr[2] == '3' || arr[2] == '4' ||
    //arr[2] == '5' || arr[2] == '6' || arr[2] == '7' || arr[2] == '8' || arr[2] == '9') &&
    //(arr[3] == '0' || arr[3] == '1' || arr[3] == '2' || arr[3] == '3' || arr[3] == '4' ||
    //arr[3] == '5' || arr[3] == '6' || arr[3] == '7' || arr[3] == '8' || arr[3] == '9'))
}