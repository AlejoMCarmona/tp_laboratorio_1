#ifndef VISUAL_H_
#define VISUAL_H_
#include "Input.h"

/// \fn int MostrarResultados(float, float, float, float, float, float, int, int, int, int, int, int)
/// \brief Intenta mostrar los resultados de la calculadora, devolviendo si pudo mostrarlos o no
/// \param x Primer operando
/// \param y Segundo operando
/// \param flagX Indica con un 1 si se ingreso el primer operando y con un 0 si no se hizo
/// \param flagY Indica con un 1 si se ingreso el segundo operando y con un 0 si no se hizo
/// \param suma Suma de los numeros
/// \param resta Resta de los numeros
/// \param multiplicacion Multiplicacion de los numeros
/// \param division Division de los numeros
/// \param flagDiv Indica con un 1 si se pudo realizar la division de los numeros y con un 0 si no se pudo
/// \param factorialX Factorial del primer operando
/// \param factorialY Factorial del segundo operando
/// \param flagFactX Indica con un 1 si se pudo realizar el factorial del primer operando y con un 0 si no se pudo
/// \param flagFactY Indica con un 1 si se pudo realizar el factorial del segundo operando y con un 0 si no se pudo
/// \param flagOp Indica con un 1 si se realizaron las operaciones para poder mostrar los resultados y con un 0 si aun no se hicieron
/// \return 1 si se pudieron mostrar los resultados, y 0 si no se pudo
void MostrarResultados(float x, float y, int* flagX, int* flagY, float suma, float resta, float multiplicacion, float division, int flagDiv, int factorialX, int factorialY, int flagFactX, int flagFactY, int* flagOp);

/// \fn int MostrarMenu(float, float, int*, int*)
/// \brief Muestra el menu de la calculadora y devuelve la opcion ingresada por el usuario
/// \param x El primer operando
/// \param y El segundo operando
/// \param flagX Indica con un 1 si se ingreso el primer operando y con un 0 si aun no se ingreso
/// \param flagY Indica con un 1 si se ingreso el segundo operando y con un 0 si aun no se ingreso
/// \return La opción ingresada por el usuario
int MostrarMenu(float x, float y, int flagX, int flagY);

#endif /* VISUAL_H_ */
