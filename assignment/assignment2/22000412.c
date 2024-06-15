#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for student records
struct Student {
    int roll_number;
    char name[50];
    float marks;
};

// Function to add a new student record to the file
void addStudentRecord(FILE *file) {
    struct Student student;

    printf("Enter Roll Number: ");
    scanf("%d", &student.roll_number);
    printf("Enter Name: ");
    scanf("%s", student.name);
    printf("Enter Marks: ");
    scanf("%f", &student.marks);

    // Append the student record to the file
    fwrite(&student, sizeof(struct Student), 1, file);
}

// Function to display all student records from the file
void displayAllStudentRecords(FILE *file) {
    struct Student student;

    // Read and display all student records from the file
    while (!feof(file)) {
        fread(&student, sizeof(struct Student), 1, file);
        if (!feof(file)) {
            printf("Roll Number: %d, Name: %s, Marks: %.2f\n", student.roll_number, student.name, student.marks);
        }
    }
}

// Function to search for a student by roll number
void searchStudentRecord(FILE *file) {
    int roll_number;
    struct Student student;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll_number);

    // Search for the student record by roll number
    fseek(file, 0, SEEK_SET);  // Move the file pointer to the beginning
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (student.roll_number == roll_number) {
            printf("Roll Number: %d, Name: %s, Marks: %.2f\n", student.roll_number, student.name, student.marks);
            return; // Student found, exit the function
        }
    }

    printf("Student with Roll Number %d not found.\n", roll_number);
}

// Function to delete a student record by roll number
void deleteStudentRecord(FILE *file) {
    int roll_number;
    struct Student student, empty_student = {0, "", 0.0};

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll_number);

    // Open a temporary file for writing
    FILE *temp_file = fopen("temp.txt", "wb");
    if (temp_file == NULL) {
        perror("Error creating temporary file");
        return;
    }

    // Copy all records except the one to be deleted to the temporary file
    fseek(file, 0, SEEK_SET);  // Move the file pointer to the beginning
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (student.roll_number != roll_number) {
            fwrite(&student, sizeof(struct Student), 1, temp_file);
        }
    }

    // Close both files
    fclose(file);
    fclose(temp_file);

    // Rename the temporary file to the original file
    remove("student_records.txt");
    rename("temp.txt", "student_records.txt");

    printf("Student with Roll Number %d deleted successfully.\n", roll_number);
}

int main() {
    int choice;
    FILE *file;

    // Open the file in binary append mode
    file = fopen("student_records.txt", "ab+");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentRecord(file);
                break;
            case 2:
                displayAllStudentRecords(file);
                break;
            case 3:
                searchStudentRecord(file);
                break;
            case 4:
                deleteStudentRecord(file);
                break;
            case 5:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
