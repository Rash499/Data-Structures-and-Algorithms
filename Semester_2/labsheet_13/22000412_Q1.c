#include <stdio.h>


int sumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return num % 10 + sumOfDigits(num / 10);
}

int digitalRoot(int num) {
    if (num < 10) {
        return num;
    }
    int sum = sumOfDigits(num);
    return digitalRoot(sum);
}

int main() {
 
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("The digital root of %d is: %d\n", number, digitalRoot(number));

    return 0;
}
