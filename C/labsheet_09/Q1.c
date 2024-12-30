#include <stdio.h>
struct Student{
    char reg_no[20];
    char name[50];
    int age;
};
int main(){

    struct Student students[2];
    for(int i = 0; i<2; i++){
        printf("Enter the details of student %d:\n",i+1);
        printf("Registration number: ");
        scanf("%s",students[i].reg_no);
        printf("Name: ");
        scanf("%s",students[i].name);
        printf("Age: ");
        scanf("%d",&students[i].age);
    }
    FILE *file = fopen("C:\\Users\\PR\\OneDrive\\Documents\\C and DSA\\C\\labsheet_09\\Student_details.txt","w");
    if(file == NULL){
        perror("Error opening file\n");
        return 1;
    }
    fprintf(file,"StRe_no St_name St_age\n");
    for(int i=0; i<2; i++){
        fprintf(file,"%s        %s        %d \n",students[i].reg_no,students[i].name,students[i].age);
    }
    fclose(file);
    printf("Successfully written to the file");
    return 0;
}