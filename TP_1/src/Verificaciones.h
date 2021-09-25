#ifndef VERIFICACIONES_H_
#define VERIFICACIONES_H_
#include <float.h>

/// \fn int VerificarSigno(int)
/// \brief Verifica el signo de un numero
/// \param num El numero a verificar
/// \return 1 si es positivo, 0 si es cero, y -1 si es negativo
int VerificarSigno(int num);

/// \fn int ValidarFactorial(float)
/// \brief Valida si se puede hacer el factorial de un numero
/// \param num El numero a validar
/// \return 1 si se puede hacer el factorial del numero, y 0 si no se puede
int ValidarFactorial(float num);

#endif /* VERIFICACIONES_H_ */
