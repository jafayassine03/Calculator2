#include <stdio.h>
#include <math.h>

long long factorial(int n) {
    if (n < 0) return -1;
    long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

int main() {
    int choice;
    double num1, num2;
    double memory = 0;
    double result = 0;

    do {
        printf("\n=== GREAT CALCULATOR ===\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Square Root\n");
        printf("8. Factorial\n");
        printf("9. Sine\n");
        printf("10. Cosine\n");
        printf("11. Percentage\n");
        printf("12. Tangent\n");
        printf("13. Natural Log (ln)\n");
        printf("14. Log Base 10\n");
        printf("15. Exponential (e^x)\n");
        printf("16. Clear / Reset\n");
        printf("17. Memory Add (M+)\n");
        printf("18. Memory Subtract (M-)\n");
        printf("19. Memory Recall (MR)\n");
        printf("20. Memory Clear (MC)\n");
        printf("21. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                }
                break;

            case 5: {
                int a, b;
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                if (b == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    result = a % b;
                    printf("Result: %d\n", a % b);
                }
                break;
            }

            case 6:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %.2lf\n", result);
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Error: Negative number!\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: %.2lf\n", result);
                }
                break;

            case 8: {
                int n;
                printf("Enter an integer: ");
                scanf("%d", &n);
                long long factorialResult = factorial(n);
                if (factorialResult == -1) {
                    printf("Error: Factorial of negative number!\n");
                } else {
                    result = factorialResult;
                    printf("Result: %lld\n", factorialResult);
                }
                break;
            }

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180);
                printf("Result: %.4lf\n", result);
                break;

            case 10:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * M_PI / 180);
                printf("Result: %.4lf\n", result);
                break;

            case 11:
                printf("Enter number and percentage: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2 / 100;
                printf("Result: %.2lf\n", result);
                break;

            case 12:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * M_PI / 180);
                printf("Result: %.4lf\n", result);
                break;

            case 13:
                printf("Enter a positive number: ");
                scanf("%lf", &num1);
                if (num1 <= 0) {
                    printf("Error: Logarithm undefined for non-positive numbers!\n");
                } else {
                    result = log(num1);
                    printf("Result: %.4lf\n", result);
                }
                break;

            case 14:
                printf("Enter a positive number: ");
                scanf("%lf", &num1);
                if (num1 <= 0) {
                    printf("Error: Logarithm undefined for non-positive numbers!\n");
                } else {
                    result = log10(num1);
                    printf("Result: %.4lf\n", result);
                }
                break;

            case 15:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = exp(num1);
                printf("Result: %.4lf\n", result);
                break;

            case 16:
                num1 = 0;
                num2 = 0;
                result = 0;
                memory = 0;
                printf("Calculator has been cleared and reset.\n");
                break;

            case 17:
                memory += result;
                printf("Memory: %.2lf\n", memory);
                break;

            case 18:
                memory -= result;
                printf("Memory: %.2lf\n", memory);
                break;

            case 19:
                result = memory;
                printf("Memory: %.2lf\n", memory);
                break;

            case 20:
                memory = 0;
                printf("Memory has been cleared.\n");
                break;

            case 21:
                printf("Exiting calculator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 21);

    return 0;
}