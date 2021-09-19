#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>

/// \fn float IngresarFlotante(char[])
/// \brief Pide un numero flotante y lo retorna
/// \param mensaje El mensaje que se va a mostrar al pedir el numero
/// \return El numero ingresado
float IngresarFlotante(char mensaje[]);

/// \fn int IngresarEntero(char[])
/// \brief Pide un entero y lo retorna
/// \param mensaje El mensaje que se va a mostrar al pedir el numero entero
/// \return El entero ingresado
int IngresarEntero(char mensaje[]);

#endif /* INPUT_H_ */
