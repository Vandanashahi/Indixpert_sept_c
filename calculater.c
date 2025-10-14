#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b != 0)
        return (float)a / b;
    else {
        printf("Division by zero is not allowed.\n");
        return 0;
    }
}

int main() {
    int number1, number2, choice;
    float result;

    printf("ENTER FIRST NUMBER: ");
    scanf("%d", &number1);

    printf("ENTER SECOND NUMBER: ");
    scanf("%d", &number2);

    printf("\n  <<<<< CALCULATOR >>>>>    \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("RESULT: %d\n", add(number1, number2));
    }
    else if (choice == 2) {
        printf("RESULT: %d\n", subtract(number1, number2));
    }
    else if (choice == 3) {
        printf("RESULT: %d\n", multiply(number1, number2));
    }
    else if (choice == 4) {
        if (number2 != 0) {
            result = divide(number1, number2);
            printf("RESULT: %.2f\n", result);  
        } else {
            printf("Division by zero is not allowed.\n");
        }
    }
    
    else {
        printf("Invalid choice! TRY AGAIN.\n");
    }

   return 0;
