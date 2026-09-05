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
        printf("11. Tangent\n");
        printf("12. Clear / Reset\n");
        printf("13. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", num1 + num2);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", num1 - num2);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", num1 * num2);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    printf("Result: %.2lf\n", num1 / num2);
                }
                break;

            case 5: {
                int a, b;
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                if (b == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    printf("Result: %d\n", a % b);
                }
                break;
            }

            case 6:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", pow(num1, num2));
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Error: Negative number!\n");
                } else {
                    printf("Result: %.2lf\n", sqrt(num1));
                }
                break;

            case 8: {
                int n;
                printf("Enter an integer: ");
                scanf("%d", &n);
                long long result = factorial(n);

                if (result == -1) {
                    printf("Error: Factorial of negative number!\n");
                } else {
                    printf("Result: %lld\n", result);
                }
                break;
            }

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                printf("Result: %.4lf\n", sin(num1 * M_PI / 180));
                break;

            case 10:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                printf("Result: %.4lf\n", cos(num1 * M_PI / 180));
                break;

            case 11:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                printf("Result: %.4lf\n", tan(num1 * M_PI / 180));
                break;

            case 12:
                num1 = 0;
                num2 = 0;
                printf("Calculator has been cleared and reset.\n");
                break;

            case 13:
                printf("Exiting calculator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 13);

    return 0;
}
