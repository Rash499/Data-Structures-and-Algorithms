#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//code works
struct Student{
    int roll_number;
    char name[50];
    float marks;
};

void addStudentsRecords(FILE *file){
    struct Student student;
    printf("Enter the roll num: ");
    scanf("%d",&student.roll_number);
    printf("Enter Name: ");
    scanf("%s",student.name);
    printf("Enter marks: ");
    scanf("%f",&student.marks);
    fwrite("%f",sizeof(struct Student),1,file); //add the records to file
}

void displayStudentsRecords(FILE *file){
    struct Student student; //read from the file
    while(fread(&student,sizeof(struct Student),1,file)==1){
        printf("Roll number: %d, Name: %s, Marks: %.2f\n",student.roll_number,student.name,student.marks);
    
    }
}
void searchStudentRecords(FILE *file){
    int roll_number;
    struct Student student;

    printf("Enter the roll_number: ");
    scanf("%d",&roll_number);

    fseek(file,0,SEEK_SET); //move pointer to beginning
    while(fread(&student,sizeof(struct Student),1,file)==1){
        if(student.roll_number == roll_number){
            printf("Roll num: %d, Name: %s,Marks: %.2f\n",student.roll_number,student.name,student.marks);
            return; //exit from the function
        }
    }
    printf("Roll number: %d not found",roll_number);
}

void deleteStudentRecord(FILE *file){
    int roll_number;
    struct Student student;
    struct Student empty_student = {0,"",0.0};

    printf("Enter the roll_number: ");
    scanf("%d",&roll_number);
    //create a new file pointer
    FILE *file2 = fopen("temp.txt", "wb");
    if (file2 == NULL) {
        perror("Error creating temporary file");
        return;
    }
    //copy all records to the temp file
    fseek(file, 0, SEEK_SET);  //move pointer to beignning
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (student.roll_number != roll_number) { //check the condition
            fwrite(&student, sizeof(struct Student), 1, file2);
        }
    }
    //close both by renaming
    fclose(file);
    fclose(file2);
    remove("student_records.txt");
    rename("temp.txt","student_records.txt");

}
int main(){
    int num;
    FILE *file;

    file = fopen("student_records.txt","ab+");
    if (file==NULL){
        perror("Error");
        return 1;
    }
    while(1){
        printf("\nStudent record management system\n");
        printf("1. ADD student records\n");
        printf("2. Display all records\n");
        printf("3. Search student by roll number\n");
        printf("4. Delete student record\n");
        printf("5. Exit\n");
        printf("Enter the number: ");
        scanf("%d",&num);

        switch (num)
        {
        case 1:
            addStudentsRecords(file);
            break;
        case 2:
            displayStudentsRecords(file);
            break;
        case 3:
            searchStudentRecords(file);
            break;
        case 4:
            deleteStudentRecord(file);
            break;
        case 5:
            fclose(file);
            exit(0);
        default:
            printf("Invalid number\n");
        }
    }

    return 0;
}
//2200412