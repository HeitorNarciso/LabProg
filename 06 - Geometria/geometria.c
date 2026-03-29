#include <math.h>
#include "geometria.h"

static const double PI = 3.14159;

double area_circle(double radius)
{
    return PI * radius * radius;
}

double perimetro_circle(double radius)
{
    return 2 * PI * radius;
}
double area_triangle(double base, double height)
{
    return (base * height) / 2;
}
double perimetro_triangle(double side1, double side2, double side3)
{
    return side1 + side2 + side3;
}
double area_rectangle(double length, double width)
{
    return length * width;
}

double perimetro_rectangle(double length, double width)
{
    return 2 * (length + width);
}
double area_square(double side)
{
    return side * side;
}
double perimetro_square(double side)
{
    return 4 * side;
}
