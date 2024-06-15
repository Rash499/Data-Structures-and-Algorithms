#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    int num;
    file = fopen("C:\\Users\\PR\\OneDrive\\Documents\\C and DSA\\C\\file_handling\\file_input.txt","w");

    if(file == NULL){
        printf("Error");
        exit(1);
    }
    
    printf("Enter a number: ");
    scanf("%d",&num);

    fprintf(file,"%d",num);
    fclose(file);
    return 0;
}