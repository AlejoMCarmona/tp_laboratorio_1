#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>

/// \fn float IngresarFlotante(char[])
/// \brief Pide un numero flotante y lo retorna
/// \param mensaje El mensaje que se va a mostrar al pedir el numero
/// \return El numero ingresado
float IngresarFlotante(char mensaje[]);

/// \fn char IngresarCaracter(char[])
/// \brief Pide ingresar un caracter y lo devuelve
/// \param mensaje El mensaje que se le va a mostrar al usuario al pedir el caracter
/// \return El caracter ingresado
char IngresarCaracter(char mensaje[]);

#endif /* INPUT_H_ */
