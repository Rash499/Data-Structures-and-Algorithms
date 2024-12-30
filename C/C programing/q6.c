#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};  // Example array
    int length = sizeof(array) / sizeof(array[0]);  // Calculate the length of the array
    
    int number = 0;
    
    for (int i = 0; i < length; i++) {
        number = number * 10 + array[i];  // Build the number by multiplying by 10 and adding the current element
    }
    
    printf("Formed number: %d\n", number);
    
 return 0;
}