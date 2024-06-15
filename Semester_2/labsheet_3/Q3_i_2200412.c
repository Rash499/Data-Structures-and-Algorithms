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
    free(persons);

    return 0;
}
