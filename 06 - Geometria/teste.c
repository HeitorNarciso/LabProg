#include <stdio.h>
#include "geometria.h"

int main()
{
    char option;
    do
    {
        printf("Welcome to the geometry calculator!\n");
        printf("Enter the option you want to perform:\n");
        printf("a) Calculate the area of a circle\n");
        printf("b) Calculate the perimeter of a circle\n");
        printf("c) Calculate the area of a rectangle\n");
        printf("d) Calculate the perimeter of a rectangle\n");
        printf("e) Calculate the area of a triangle\n");
        printf("f) Calculate the perimeter of a triangle\n");
        printf("g) Calculate the area of a square\n");
        printf("h) Calculate the perimeter of a square\n");
        printf("i) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &option); // espaço para consumir whitespaces pendentes

        if (option == 'i')
        {
            printf("Exiting the geometry calculator. Goodbye!\n");
            break;
        }

        switch (option)
        {
        case 'a':
        {
            double radius;
            printf("Enter the radius of the circle: ");
            if (scanf("%lf", &radius) != 1 || radius < 0)
            {
                fprintf(stderr, "Invalid input for radius.\n");
                break;
            }
            printf("Area of the circle: %.2lf\n", area_circle(radius));
        }
        break;
        case 'b':
        {
            double radius;
            printf("Enter the radius of the circle: ");
            if (scanf("%lf", &radius) != 1 || radius < 0)
            {
                fprintf(stderr, "Invalid input for radius.\n");
                break;
            }
            printf("Perimeter of the circle: %.2lf\n", perimetro_circle(radius));
        }
        break;
        case 'c':
        {
            double length, width;
            printf("Enter the length of the rectangle: ");
            if (scanf("%lf", &length) != 1 || length < 0)
            {
                fprintf(stderr, "Invalid input for length.\n");
                break;
            }
            printf("Enter the width of the rectangle: ");
            if (scanf("%lf", &width) != 1 || width < 0)
            {
                fprintf(stderr, "Invalid input for width.\n");
                break;
            }

            printf("Area of the rectangle: %.2lf\n", area_rectangle(length, width));
        }
        break;
        case 'd':
        {
            double length, width;
            printf("Enter the length of the rectangle: ");
            if (scanf("%lf", &length) != 1 || length < 0)
            {
                fprintf(stderr, "Invalid input for length.\n");
                break;
            }
            printf("Enter the width of the rectangle: ");
            if (scanf("%lf", &width) != 1 || width < 0)
            {
                fprintf(stderr, "Invalid input for width.\n");
                break;
            }
            printf("Perimeter of the rectangle: %.2lf\n", perimetro_rectangle(length, width));
        }
        break;
        case 'e':
        {
            double base, height;
            printf("Enter the base of the triangle: ");
            if (scanf("%lf", &base) != 1 || base < 0)
            {
                fprintf(stderr, "Invalid input for base.\n");
                break;
            }
            printf("Enter the height of the triangle: ");
            if (scanf("%lf", &height) != 1 || height < 0)
            {
                fprintf(stderr, "Invalid input for height.\n");
                break;
            }
            printf("Area of the triangle: %.2lf\n", area_triangle(base, height));
        }
        break;
        case 'f':
        {
            double side1, side2, side3;
            printf("Enter the first side of the triangle: ");
            if (scanf("%lf", &side1) != 1 || side1 < 0)
            {
                fprintf(stderr, "Invalid input for side1.\n");
                break;
            }
            printf("Enter the second side of the triangle: ");
            if (scanf("%lf", &side2) != 1 || side2 < 0)
            {
                fprintf(stderr, "Invalid input for side2.\n");
                break;
            }
            printf("Enter the third side of the triangle: ");
            if (scanf("%lf", &side3) != 1 || side3 < 0)
            {
                fprintf(stderr, "Invalid input for side3.\n");
                break;
            }
            printf("Perimeter of the triangle: %.2lf\n", perimetro_triangle(side1, side2, side3));
        }
        break;
        case 'g':
        {
            double side;
            printf("Enter the side of the square: ");
            if (scanf("%lf", &side) != 1 || side < 0)
            {
                fprintf(stderr, "Invalid input for side.\n");
                break;
            }
            printf("Area of the square: %.2lf\n", area_square(side));
        }
        break;
        case 'h':
        {
            double side;
            printf("Enter the side of the square: ");
            if (scanf("%lf", &side) != 1 || side < 0)
            {
                fprintf(stderr, "Invalid input for side.\n");
                break;
            }
            printf("Perimeter of the square: %.2lf\n", perimetro_square(side));
        }
        break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 'i');
    return 0;
}