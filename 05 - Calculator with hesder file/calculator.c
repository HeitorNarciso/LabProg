#include "calculator.h"
#include <stdio.h>

double add(double a, double b)
{
    return a + b;
}
double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}
double divide(double a, double b)
{
    if (b == 0)
    {
        fprintf(stderr, "Error: Division by zero is undefined.\n");
        return 0; /* Return 0 or some error code as needed */
    }
    return a / b;
}