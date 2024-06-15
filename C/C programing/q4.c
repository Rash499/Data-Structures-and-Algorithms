#include <stdio.h>

int main() {
    int number;
    int n;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Enter the number of digits to extract: ");
    scanf("%d", &n);

    // Calculate the number of digits in the input number
    int temp = number;
    int numDigits = 0;
    while (temp != 0) {
        temp /= 10;
        numDigits++;
    }

    // Create an array to store the extracted digits
    int digits[n];

    // Extract the digits from the number
    for (int i = 0; i < n; i++) {
        digits[i] = number % 10;
        number /= 10;
    }

    // If the number of digits extracted is less than n, pad with 0s
    for (int i = n; i < numDigits; i++) {
        digits[i] = 0;
    }

    // Print the extracted digits in reverse order
    printf("Extracted digits: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", digits[i]);
    }

    return 0;
}
