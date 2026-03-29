#ifndef GEOMETRIA_H
#define GEOMETRIA_H

/**
 * @file geometria.h
 * @brief Biblioteca de funções de geometria (interface).
 *
 * Este header define funções para cálculos de área e perímetros de
 * formas geométricas básicas.
 */

/**
 * @brief Calcula a área de um círculo.
 * @param radius Raio do círculo (>= 0).
 * @return Área do círculo.
 */
double area_circle(double radius);

/**
 * @brief Calcula o perímetro de um círculo.
 * @param radius Raio do círculo (>= 0).
 * @return Perímetro do círculo.
 */
double perimetro_circle(double radius);

/**
 * @brief Calcula a área de um retângulo.
 */
double area_rectangle(double length, double width);

/**
 * @brief Calcula o perímetro de um retângulo.
 */
double perimetro_rectangle(double length, double width);

/**
 * @brief Calcula a área de um triângulo.
 */
double area_triangle(double base, double height);

/**
 * @brief Calcula o perímetro de um triângulo.
 */
double perimetro_triangle(double side1, double side2, double side3);

/**
 * @brief Calcula a área de um quadrado.
 */
double area_square(double side);

/**
 * @brief Calcula o perímetro de um quadrado.
 */
double perimetro_square(double side);

#endif /* GEOMETRIA_H */
