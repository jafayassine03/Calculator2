```c
#include <stdio.h>
#include <math.h>
#include <string.h>

long long factorial(int n) {
    if (n < 0) return -1;
    long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

void decimalToBinary(int n) {
    int binary[64];
    int i = 0;

    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }

    printf("Binary: ");
    while (i > 0) {
        printf("%d", binary[--i]);
    }
    printf("\n");
}

void decimalToOctal(int n) {
    printf("Octal: %o\n", n);
}

void decimalToHex(int n) {
    printf("Hexadecimal: %X\n", n);
}

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0)
        return 0;

    int result = (a / gcd(a, b)) * b;

    if (result < 0)
        result = -result;

    return result;
}

int main() {
    int choice;
    double num1, num2;
    double memory = 0;
    double result = 0;
    char history[100][100];
    int historyCount = 0;

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
        printf("21. Average Calculator\n");
        printf("22. Number Base Converter\n");
        printf("23. Statistics Calculator\n");
        printf("24. Calculation History\n");
        printf("25. Save History to File\n");
        printf("26. Exit\n");
        printf("27. Quadratic Equation Solver\n");
        printf("28. Loan Payment Calculator\n");
        printf("29. GCD & LCM Calculator\n");
        printf("30. BMI Calculator\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "%.2lf + %.2lf = %.2lf", num1, num2, result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "%.2lf - %.2lf = %.2lf", num1, num2, result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "%.2lf * %.2lf = %.2lf", num1, num2, result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100, "%.2lf / %.2lf = %.2lf", num1, num2, result);
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
                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100, "%d %% %d = %d", a, b, a % b);
                }
                break;
            }

            case 6:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %.2lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "%.2lf ^ %.2lf = %.2lf", num1, num2, result);
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Error: Negative number!\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: %.2lf\n", result);
                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100, "sqrt(%.2lf) = %.2lf", num1, result);
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
                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100, "%d! = %lld", n, factorialResult);
                }
                break;
            }

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180);
                printf("Result: %.4lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "sin(%.2lf) = %.4lf", num1, result);
                break;

            case 10:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * M_PI / 180);
                printf("Result: %.4lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "cos(%.2lf) = %.4lf", num1, result);
                break;

            case 11:
                printf("Enter number and percentage: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2 / 100;
                printf("Result: %.2lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "%.2lf%% of %.2lf = %.2lf", num2, num1, result);
                break;

            case 12:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * M_PI / 180);
                printf("Result: %.4lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "tan(%.2lf) = %.4lf", num1, result);
                break;

            case 13:
                printf("Enter a positive number: ");
                scanf("%lf", &num1);

                if (num1 <= 0) {
                    printf("Error: Logarithm undefined for non-positive numbers!\n");
                } else {
                    result = log(num1);
                    printf("Result: %.4lf\n", result);
                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100, "ln(%.2lf) = %.4lf", num1, result);
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
                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100, "log10(%.2lf) = %.4lf", num1, result);
                }
                break;

            case 15:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = exp(num1);
                printf("Result: %.4lf\n", result);
                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "e^%.2lf = %.4lf", num1, result);
                break;

            case 16:
                num1 = 0;
                num2 = 0;
                result = 0;
                memory = 0;
                historyCount = 0;
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

            case 21: {
                int count;
                double number, sum = 0;

                printf("How many numbers? ");
                scanf("%d", &count);

                if (count <= 0) {
                    printf("Error: Number of values must be greater than zero!\n");
                } else {
                    for (int i = 1; i <= count; i++) {
                        printf("Enter number %d: ", i);
                        scanf("%lf", &number);
                        sum += number;
                    }

                    result = sum / count;
                    printf("Average: %.2lf\n", result);

                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100, "Average = %.2lf", result);
                }
                break;
            }

            case 22: {
                int baseChoice;
                int number;

                printf("\n=== NUMBER BASE CONVERTER ===\n");
                printf("1. Decimal to Binary\n");
                printf("2. Decimal to Octal\n");
                printf("3. Decimal to Hexadecimal\n");
                printf("4. Binary to Decimal\n");
                printf("5. Octal to Decimal\n");
                printf("6. Hexadecimal to Decimal\n");
                printf("Choose an option: ");
                scanf("%d", &baseChoice);

                switch (baseChoice) {
                    case 1:
                        printf("Enter a decimal number: ");
                        scanf("%d", &number);
                        decimalToBinary(number);
                        break;

                    case 2:
                        printf("Enter a decimal number: ");
                        scanf("%d", &number);
                        decimalToOctal(number);
                        break;

                    case 3:
                        printf("Enter a decimal number: ");
                        scanf("%d", &number);
                        decimalToHex(number);
                        break;

                    case 4: {
                        char binary[64];
                        int decimal = 0;
                        int valid = 1;

                        printf("Enter a binary number: ");
                        scanf("%63s", binary);

                        for (int i = 0; binary[i] != '\0'; i++) {
                            if (binary[i] != '0' && binary[i] != '1') {
                                valid = 0;
                                break;
                            }
                            decimal = decimal * 2 + (binary[i] - '0');
                        }

                        if (!valid)
                            printf("Error: Invalid binary number!\n");
                        else
                            printf("Decimal: %d\n", decimal);

                        break;
                    }

                    case 5: {
                        char octal[64];
                        int decimal = 0;
                        int valid = 1;

                        printf("Enter an octal number: ");
                        scanf("%63s", octal);

                        for (int i = 0; octal[i] != '\0'; i++) {
                            if (octal[i] < '0' || octal[i] > '7') {
                                valid = 0;
                                break;
                            }
                            decimal = decimal * 8 + (octal[i] - '0');
                        }

                        if (!valid)
                            printf("Error: Invalid octal number!\n");
                        else
                            printf("Decimal: %d\n", decimal);

                        break;
                    }

                    case 6: {
                        char hex[64];
                        int decimal = 0;
                        int valid = 1;

                        printf("Enter a hexadecimal number: ");
                        scanf("%63s", hex);

                        for (int i = 0; hex[i] != '\0'; i++) {
                            int value;

                            if (hex[i] >= '0' && hex[i] <= '9')
                                value = hex[i] - '0';
                            else if (hex[i] >= 'A' && hex[i] <= 'F')
                                value = hex[i] - 'A' + 10;
                            else if (hex[i] >= 'a' && hex[i] <= 'f')
                                value = hex[i] - 'a' + 10;
                            else {
                                valid = 0;
                                break;
                            }

                            decimal = decimal * 16 + value;
                        }

                        if (!valid)
                            printf("Error: Invalid hexadecimal number!\n");
                        else
                            printf("Decimal: %d\n", decimal);

                        break;
                    }

                    default:
                        printf("Invalid choice.\n");
                }

                break;
            }

            case 23: {
                int count;
                double numbers[100];
                double sum = 0;
                double mean;
                double variance = 0;
                double standardDeviation;
                double minimum;
                double maximum;

                printf("\n=== STATISTICS CALCULATOR ===\n");
                printf("How many numbers? ");
                scanf("%d", &count);

                if (count <= 0 || count > 100) {
                    printf("Error: Enter between 1 and 100 numbers.\n");
                    break;
                }

                for (int i = 0; i < count; i++) {
                    printf("Enter number %d: ", i + 1);
                    scanf("%lf", &numbers[i]);
                    sum += numbers[i];
                }

                mean = sum / count;
                minimum = numbers[0];
                maximum = numbers[0];

                for (int i = 0; i < count; i++) {
                    if (numbers[i] < minimum)
                        minimum = numbers[i];

                    if (numbers[i] > maximum)
                        maximum = numbers[i];

                    variance += pow(numbers[i] - mean, 2);
                }

                variance /= count;
                standardDeviation = sqrt(variance);

                printf("\nCount: %d\n", count);
                printf("Sum: %.2lf\n", sum);
                printf("Mean: %.2lf\n", mean);
                printf("Minimum: %.2lf\n", minimum);
                printf("Maximum: %.2lf\n", maximum);
                printf("Range: %.2lf\n", maximum - minimum);
                printf("Variance: %.2lf\n", variance);
                printf("Standard Deviation: %.2lf\n", standardDeviation);

                result = mean;

                if (historyCount < 100)
                    snprintf(history[historyCount++], 100, "Statistics Mean = %.2lf", mean);

                break;
            }

            case 24:
                printf("\n=== CALCULATION HISTORY ===\n");

                if (historyCount == 0) {
                    printf("No calculations yet.\n");
                } else {
                    for (int i = 0; i < historyCount; i++) {
                        printf("%d. %s\n", i + 1, history[i]);
                    }
                }
                break;

            case 25: {
                FILE *file = fopen("calculator_history.txt", "w");

                if (file == NULL) {
                    printf("Error: Could not create history file.\n");
                } else if (historyCount == 0) {
                    printf("No calculations to save.\n");
                    fclose(file);
                } else {
                    fprintf(file, "=== GREAT CALCULATOR HISTORY ===\n\n");

                    for (int i = 0; i < historyCount; i++) {
                        fprintf(file, "%d. %s\n", i + 1, history[i]);
                    }

                    fclose(file);
                    printf("History saved to calculator_history.txt\n");
                }

                break;
            }

            case 26:
                printf("Exiting calculator. Goodbye!\n");
                break;

            case 27: {
                double a, b, c;
                double discriminant;
                double root1, root2;

                printf("\n=== QUADRATIC EQUATION SOLVER ===\n");
                printf("Equation format: ax^2 + bx + c = 0\n");
                printf("Enter a, b and c: ");
                scanf("%lf %lf %lf", &a, &b, &c);

                if (a == 0) {
                    if (b == 0) {
                        if (c == 0)
                            printf("Infinite number of solutions.\n");
                        else
                            printf("No solution.\n");
                    } else {
                        root1 = -c / b;
                        printf("Linear equation solution: x = %.4lf\n", root1);
                    }
                } else {
                    discriminant = b * b - 4 * a * c;

                    if (discriminant > 0) {
                        root1 = (-b + sqrt(discriminant)) / (2 * a);
                        root2 = (-b - sqrt(discriminant)) / (2 * a);

                        printf("Two real solutions:\n");
                        printf("x1 = %.4lf\n", root1);
                        printf("x2 = %.4lf\n", root2);

                        if (historyCount < 100)
                            snprintf(history[historyCount++], 100,
                                     "%.2lfx^2 + %.2lfx + %.2lf = 0 -> x1=%.4lf, x2=%.4lf",
                                     a, b, c, root1, root2);
                    } else if (discriminant == 0) {
                        root1 = -b / (2 * a);

                        printf("One real solution:\n");
                        printf("x = %.4lf\n", root1);

                        if (historyCount < 100)
                            snprintf(history[historyCount++], 100,
                                     "%.2lfx^2 + %.2lfx + %.2lf = 0 -> x=%.4lf",
                                     a, b, c, root1);
                    } else {
                        double realPart = -b / (2 * a);
                        double imaginaryPart = sqrt(-discriminant) / (2 * a);

                        printf("Two complex solutions:\n");
                        printf("x1 = %.4lf + %.4lfi\n", realPart, imaginaryPart);
                        printf("x2 = %.4lf - %.4lfi\n", realPart, imaginaryPart);

                        if (historyCount < 100)
                            snprintf(history[historyCount++], 100,
                                     "%.2lfx^2 + %.2lfx + %.2lf = 0 -> complex roots",
                                     a, b, c);
                    }
                }

                break;
            }

            case 28: {
                double principal;
                double annualRate;
                double monthlyRate;
                double payments;
                double monthlyPayment;
                double totalPayment;
                double totalInterest;

                printf("\n=== LOAN PAYMENT CALCULATOR ===\n");
                printf("Enter loan amount: ");
                scanf("%lf", &principal);

                printf("Enter annual interest rate (%%): ");
                scanf("%lf", &annualRate);

                printf("Enter loan term in years: ");
                scanf("%lf", &payments);

                if (principal <= 0 || annualRate < 0 || payments <= 0) {
                    printf("Error: Invalid loan information.\n");
                } else {
                    monthlyRate = annualRate / 100 / 12;
                    payments *= 12;

                    if (monthlyRate == 0) {
                        monthlyPayment = principal / payments;
                    } else {
                        monthlyPayment = principal *
                                         (monthlyRate * pow(1 + monthlyRate, payments)) /
                                         (pow(1 + monthlyRate, payments) - 1);
                    }

                    totalPayment = monthlyPayment * payments;
                    totalInterest = totalPayment - principal;

                    printf("\nMonthly Payment: %.2lf\n", monthlyPayment);
                    printf("Total Payment: %.2lf\n", totalPayment);
                    printf("Total Interest: %.2lf\n", totalInterest);

                    result = monthlyPayment;

                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100,
                                 "Loan: $%.2lf/month, Total=$%.2lf, Interest=$%.2lf",
                                 monthlyPayment, totalPayment, totalInterest);
                }

                break;
            }

            case 29: {
                int a, b;
                int greatestCommonDivisor;
                int leastCommonMultiple;

                printf("\n=== GCD & LCM CALCULATOR ===\n");
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);

                if (a == 0 && b == 0) {
                    printf("Error: GCD and LCM are undefined for 0 and 0.\n");
                } else {
                    greatestCommonDivisor = gcd(a, b);
                    leastCommonMultiple = lcm(a, b);

                    printf("GCD: %d\n", greatestCommonDivisor);
                    printf("LCM: %d\n", leastCommonMultiple);

                    result = greatestCommonDivisor;

                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100,
                                 "GCD(%d, %d) = %d, LCM(%d, %d) = %d",
                                 a, b, greatestCommonDivisor,
                                 a, b, leastCommonMultiple);
                }

                break;
            }

            case 30: {
                double weight, height, bmi;

                printf("\n=== BMI CALCULATOR ===\n");
                printf("Enter weight in kilograms: ");
                scanf("%lf", &weight);
                printf("Enter height in meters: ");
                scanf("%lf", &height);

                if (weight <= 0 || height <= 0) {
                    printf("Error: Weight and height must be greater than zero.\n");
                } else {
                    bmi = weight / (height * height);
                    result = bmi;

                    printf("BMI: %.2lf\n", bmi);

                    if (bmi < 18.5)
                        printf("Category: Underweight\n");
                    else if (bmi < 25)
                        printf("Category: Normal weight\n");
                    else if (bmi < 30)
                        printf("Category: Overweight\n");
                    else
                        printf("Category: Obese\n");

                    if (historyCount < 100)
                        snprintf(history[historyCount++], 100,
                                 "BMI: %.2lf kg, %.2lf m = %.2lf",
                                 weight, height, bmi);
                }

                break;
            }

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 26);

    return 0;
}
```
