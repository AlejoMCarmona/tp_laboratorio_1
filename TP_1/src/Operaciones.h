#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include "Verificaciones.h"
#include <stdio.h>

/// \fn float Sumar(float, float)
/// \brief Suma dos numeros y devuelve el resultado
/// \param x Primer numero a sumar
/// \param y Segundo numero a sumar
/// \return El resultado de la suma
float Sumar(float x, float y);

/// \fn float Restar(float, float)
/// \brief Resta dos numeros y devuelve el resultado
/// \param x Primer numero a restar
/// \param y Segundo numero a restar
/// \return El resultado de la resta
float Restar(float x, float y);

/// \fn float Multiplicar(float, float)
/// \brief Multiplica dos numeros enteros y devuelve el resultado
/// \param x Primer numero a multiplicar
/// \param y Segundo numero a multiplicar
/// \return El resultado de la multiplicacion
float Multiplicar(float x, float y);

/// \fn int Dividir(float, float, float*)
/// \brief Intenta dividir dos numeros y devuelve si se pudo hacer la division o no
/// \param x Primer numero a dividir
/// \param y Segundo numero a dividir
/// \param division El resultado de la division de los numeros
/// \return 1 si se pudo dividir y 0 si no se pudo dividir
int Dividir(float x, float y, float* division);

/// \fn int CalcularFactorial(int, int*)
/// \brief Intenta realizar el factorial de un numero y devuelve si se pudo hacer el factorial o no
/// \param num El numero cuyo factorial se va a hacer
/// \param factorial El resultado del factorial
/// \return 1 si se pudo realizar el factorial y 0 si no se pudo
int CalcularFactorial(float num, int *factorial);

#endif /* OPERACIONES_H_ */
