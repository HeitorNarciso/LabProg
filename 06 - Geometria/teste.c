#include <stdio.h>
#include <locale.h>
#include "geometria.h"

int main()
{
    if (setlocale(LC_ALL, "pt_PT.UTF-8") == NULL) {
        setlocale(LC_ALL, "Portuguese_Portugal.1252");
    }

    char option;
    do
    {
        printf("Bem-vindo ao calculador de geometria!\n");
        printf("Escolha a operação:\n");
        printf("a) Calcular área do círculo\n");
        printf("b) Calcular perímetro do círculo\n");
        printf("c) Calcular área do retângulo\n");
        printf("d) Calcular perímetro do retângulo\n");
        printf("e) Calcular área do triângulo\n");
        printf("f) Calcular perímetro do triângulo\n");
        printf("g) Calcular área do quadrado\n");
        printf("h) Calcular perímetro do quadrado\n");
        printf("i) Sair\n");
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
            printf("Informe o raio do círculo: ");
            if (scanf("%lf", &radius) != 1 || radius < 0)
            {
                fprintf(stderr, "Entrada inválida para o raio.\n");
                break;
            }
            printf("Área do círculo (r=%.2f): %.2f\n", radius, area_circle(radius));
        }
        break;
        case 'b':
        {
            double radius;
            printf("Informe o raio do círculo: ");
            if (scanf("%lf", &radius) != 1 || radius < 0)
            {
                fprintf(stderr, "Entrada inválida para o raio.\n");
                break;
            }
            printf("Perímetro do círculo (r=%.2f): %.2f\n", radius, perimetro_circle(radius));
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

            printf("Área do retângulo (%.2f x %.2f): %.2f\n", length, width, area_rectangle(length, width));
        }
        break;
        case 'd':
        {
            double length, width;
            printf("Informe o comprimento do retângulo: ");
            if (scanf("%lf", &length) != 1 || length < 0)
            {
                fprintf(stderr, "Entrada inválida para o comprimento.\n");
                break;
            }
            printf("Informe a largura do retângulo: ");
            if (scanf("%lf", &width) != 1 || width < 0)
            {
                fprintf(stderr, "Entrada inválida para a largura.\n");
                break;
            }
            printf("Perímetro do retângulo (%.2f x %.2f): %.2f\n", length, width, perimetro_rectangle(length, width));
        }
        break;
        case 'e':
        {
            double base, height;
            printf("Informe a base do triângulo: ");
            if (scanf("%lf", &base) != 1 || base < 0)
            {
                fprintf(stderr, "Entrada inválida para a base.\n");
                break;
            }
            printf("Informe a altura do triângulo: ");
            if (scanf("%lf", &height) != 1 || height < 0)
            {
                fprintf(stderr, "Entrada inválida para a altura.\n");
                break;
            }
            printf("Área do triângulo (b=%.2f, h=%.2f): %.2f\n", base, height, area_triangle(base, height));
        }
        break;
        case 'f':
        {
            double lado1, lado2, lado3;
            printf("Informe o primeiro lado do triângulo: ");
            if (scanf("%lf", &lado1) != 1 || lado1 < 0)
            {
                fprintf(stderr, "Entrada inválida para o lado 1.\n");
                break;
            }
            printf("Informe o segundo lado do triângulo: ");
            if (scanf("%lf", &lado2) != 1 || lado2 < 0)
            {
                fprintf(stderr, "Entrada inválida para o lado 2.\n");
                break;
            }
            printf("Informe o terceiro lado do triângulo: ");
            if (scanf("%lf", &lado3) != 1 || lado3 < 0)
            {
                fprintf(stderr, "Entrada inválida para o lado 3.\n");
                break;
            }
            printf("Perímetro do triângulo: %.2f\n", perimetro_triangle(lado1, lado2, lado3));
        }
        break;
        case 'g':
        {
            double lado;
            printf("Informe o lado do quadrado: ");
            if (scanf("%lf", &lado) != 1 || lado < 0)
            {
                fprintf(stderr, "Entrada inválida para o lado.\n");
                break;
            }
            printf("Área do quadrado (l=%.2f): %.2f\n", lado, area_square(lado));
        }
        break;
        case 'h':
        {
            double lado;
            printf("Informe o lado do quadrado: ");
            if (scanf("%lf", &lado) != 1 || lado < 0)
            {
                fprintf(stderr, "Entrada inválida para o lado.\n");
                break;
            }
            printf("Perímetro do quadrado (l=%.2f): %.2f\n", lado, perimetro_square(lado));
        }
        break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 'i');
    return 0;
}