#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    FILE *fptr;
    if ((fptr = fopen("C:\\Users\\PR\\OneDrive\\Documents\\C and DSA\\C\\file_handling\\file_input.txt","r")) == NULL){
        printf("Error! opening file");
            exit(1);
    }
    fscanf(fptr,"%d", &num);
    printf("Value of n=%d", num);

    FILE *file;
    file = fopen("C:\\Users\\PR\\OneDrive\\Documents\\C and DSA\\C\\file_handling\\file.txt","a");
    fprintf(file,"\nThis file updated\n");
    fclose(fptr); 
        return 0;
}