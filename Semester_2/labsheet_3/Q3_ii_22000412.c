#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    int numPersons;
    printf("Enter the number of persons: ");
    scanf("%d", &numPersons);
    struct Person *persons = (struct Person *)calloc(numPersons, sizeof(struct Person));
    if (persons == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    for (int i = 0; i < numPersons; i++) {
        printf("Enter details for Person %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", persons[i].name);
        printf("Enter age: ");
        scanf("%d", &persons[i].age);
    }
    printf("Entered details for %d persons:\n", numPersons);
    for (int i = 0; i < numPersons; i++) {
        printf("Person %d - Name: %s, Age: %d\n", i + 1, persons[i].name, persons[i].age);
    }
    printf("Do you want to add more persons? Enter the number of additional persons: ");
    int additionalPersons;
    scanf("%d", &additionalPersons);
    persons = (struct Person *)realloc(persons, (numPersons + additionalPersons) * sizeof(struct Person));
    if (persons == NULL) {
        printf("Memory reallocation failed. Exiting...\n");
        free(persons); 
        return 1;
    }
    for (int i = numPersons; i < numPersons + additionalPersons; i++) {
        printf("Enter details for additional Person %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", persons[i].name);
        printf("Enter age: ");
        scanf("%d", &persons[i].age);
    }
    printf("Details after adding %d more persons:\n", additionalPersons);
    for (int i = 0; i < numPersons + additionalPersons; i++) {
        printf("Person %d - Name: %s, Age: %d\n", i + 1, persons[i].name, persons[i].age);
    }
    free(persons);

    return 0;
}

