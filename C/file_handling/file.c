#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *file;
    char s;
    file = fopen("C:\\Users\\PR\\OneDrive\\Documents\\C and DSA\\C\\file_handling\\file.txt","r");
    //fprintf(file, "Hello! Welcome to C Programming.\nHello World");
    //fprintf(file, "Hello World.\n");
    if (file == NULL) {
        printf("\n CAN NOT OPEN FILE");
            exit(1);
    }
    do {
        s = getc(file); // Read file character by character.
        printf("%c", s);
    }
    while (s != EOF); 
    fclose(file);
        return 0;
}
