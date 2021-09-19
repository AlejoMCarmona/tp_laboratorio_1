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

/// \fn int Dividir(int, int)
/// \brief Intenta dividir numeros y devuelve si se pudo hacer la division o no
/// \param x Primer numero a dividir
/// \param y Segundo numero a dividir
/// \return 1 si se pudo dividir y 0 si no se pudo dividir
int Dividir(float x, float y, float* division);

/// \fn int CalcularFactorial(int, int*)
/// \brief Intenta realizar el factorial de un numero y devuelve si se pudo hacer el factorial o no
/// \param num El numero cuyo factorial se va a hacer
/// \param factorial El resultado del factorial
/// \return 1 si se pudo realizar el factorial y 0 si no se pudo
int CalcularFactorial(float num, int *factorial);

/// \fn void RealizarOperaciones(float, float, int, int, float*, float*, float*, float*, int*, int*, int*, int*, int*, int*)
/// \brief Realiza todas las operaciones de la calculadora
/// \param x Primer operando
/// \param y Segundo operando
/// \param flagX Indica con un 1 si se ingreso el primer operando y con un 0 si aun no se hizo
/// \param flagY Indica con un 1 si se ingreso el segundo operando y con un 0 si aun no se hizo
/// \param suma Suma de los numeros
/// \param resta Resta de los numeros
/// \param multiplicacion Multiplicacion de los numeros
/// \param division Division de los numeros
/// \param flagDiv Indica con un 1 si se puede realizar la division de los numeros y con un 0 si no se puede
/// \param factorialX Factorial del primer operando
/// \param factorialY Factorial del segundo operando
/// \param flagFactX Indica con un 1 si se puede realizar el factorial del primer operando y con un 0 si no se puede
/// \param flagFactY Indica con un 1 si se puede realizar el factorial del segundo operando y con un 0 si no se puede
/// \param flagOp Indica con un 1 si se pueden realizar las operaciones y con un 0 si no se puede
void RealizarOperaciones(float x, float y, int flagX, int flagY, float* suma, float* resta, float* multiplicacion, float* division, int* flagDiv, int* factorialX, int* factorialY, int* flagFactX, int* flagFactY, int* flagOp);

#endif /* OPERACIONES_H_ */
