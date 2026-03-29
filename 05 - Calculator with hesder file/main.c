#include "calculator.h"
#include <stdio.h>

int main(void)
{
    double num1, num2;
    char option;

    do
    {
        printf("Welcome to the calculator!\n");
        printf("Enter the option you want to perform:\n");
        printf("a) Addition\n");
        printf("b) Subtraction\n");
        printf("c) Multiplication\n");
        printf("d) Division\n");
        printf("e) Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &option); // espaço para consumir whitespaces pendentes

        if (option == 'e')
        {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        printf("Enter the first number: ");
        if (scanf("%lf", &num1) != 1)
        {
            fprintf(stderr, "Entrada inválida para o primeiro número.\n");
            break;
        }

        printf("Enter the second number: ");
        if (scanf("%lf", &num2) != 1)
        {
            fprintf(stderr, "Entrada inválida para o segundo número.\n");
            break;
        }

        switch (option)
        {
        case 'a':
            printf("Result: %.2lf\n", add(num1, num2));
            break;
        case 'b':
            printf("Result: %.2lf\n", subtract(num1, num2));
            break;
        case 'c':
            printf("Result: %.2lf\n", multiply(num1, num2));
            break;
        case 'd':
            printf("Result: %.2lf\n", divide(num1, num2));
            break;
        default:
            printf("Invalid option. Please select a, b, c, d or e.\n");
            break;
        }

    } while (option != 'e');

    return 0;
}