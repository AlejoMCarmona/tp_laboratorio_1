#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>

/// \fn float IngresarFlotante(char[])
/// \brief Pide un numero flotante y lo retorna
/// \param mensaje El mensaje que se le va a mostrar al usuario al pedir el numero
/// \return El numero flotante ingresado
float IngresarFlotante(char mensaje[]);

/// \fn int IngresarEntero(char[])
/// \brief Pide un entero y lo retorna
/// \param mensaje El mensaje que se le va a mostrar al usuario al pedir el numero entero
/// \return El numero entero ingresado
int IngresarEntero(char mensaje[]);

#endif /* INPUT_H_ */
