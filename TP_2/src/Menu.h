#ifndef MENU_H_
#define MENU_H_
#include "ArrayEmployees.h"

/// \fn int MostrarMenu(int*)
/// \brief Muestra al usuario el menu de opciones para que elija una opcion, y le pide que ingrese la misma.
/// \param opcion Puntero a entero donde se almacena la opcion elegida por el usuario
/// \return 1 si se ingreso un tipo de dato valido (entero) y 0 si no.
int MostrarMenu(int* opcion);

/// \fn int MostrarSubmenu(Employee[], int, int*)
/// \brief Muestra al usuario el menu de la cuarta opcion para que elija una opcion, y le pide que ingrese la misma.
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \param opcion Puntero a entero donde se almacena la opcion elegida por el usuario
/// \return Retorna 1 si se ingreso un tipo de dato valido (entero) - (-2) si no hay empleados cargados en la lista - (0) por
/// puntero nulo, o tamaño invalido.
int MostrarSubmenu(Employee list[], int len, int* opcion);

#endif /* MENU_H_ */


