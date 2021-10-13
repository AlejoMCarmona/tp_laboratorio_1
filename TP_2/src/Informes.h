#ifndef INFORMES_H_
#define INFORMES_H_
#include "ArrayEmployees.h"

/// \fn int MostrarMenu(int*)
/// \brief Muestra al usuario el menu de opciones para que elija una opcion, y el pide que ingrese la misma.
/// \param opcion Puntero a la opcion elegida por el usuario
/// \return 1 si se ingreso un tipo de dato valido (entero) y 0 si no.
int MostrarMenu(int* opcion);

/// \fn int MostrarSubmenu(int*)
/// \brief Muestra al usuario el menu de la cuarta opcion para que elija una opcion, y el pide que ingrese la misma.
/// \param opcion Puntero a la opcion elegida por el usuario
/// \return 1 si se ingreso un tipo de dato valido (entero) y 0 si no.
int MostrarSubmenu(int* opcion);

/// \fn void HacerAlta(Employee[], int, int*)
/// \brief Invoca a todas las funciones relacionadas con el alta de un empleado, e imprime los resultados por pantalla,
/// indicando si hubo un error o si pudo realizarse con exito.
/// \param list La lista donde se almacenan los empleados.
/// \param len El largo de la lista donde se almacenan los empleados.
/// \param contadorID Puntero al contador que se utiliza para crear los ID de los nuevos empleados.
void HacerAlta(Employee list[], int len, int* contadorID);

/// \fn void HacerBaja(Employee[], int)
/// \brief Invoca a todas las funciones relacionadas con la baja de un empleado, e imprime los resultados por pantalla,
/// indicando si hubo un error o si pudo realizarse con exito.
/// \param list La lista donde se almacenan los empleados.
/// \param len El largo de la lista donde se almacenan los empleados.
void HacerBaja(Employee list[], int len);

/// \fn void HacerModificacion(Employee[], int)
/// \brief Invoca a todas las funciones relacionadas con la modificacion de un empleado, preguntandole al usuario que
/// dato desea modificar. Imprime los resultados por pantalla, indicando si hubo un error o si pudo realizarse con exito.
/// \param list La lista donde se almacenan los empleados.
/// \param len El largo de la lista donde se almacenan los empleados.
void HacerModificacion(Employee list[], int len);

/// \fn void OrdenarEmpleadosPorApellidoSector(Employee[], int)
/// \brief Invoca a las funciones relacionados con el ordenamiento de la lista de empleados, preguntandole al usuario si desea ordenar
/// de manera ascendente o descendente, e imprimiendo los resultados por pantalla, indicando si hubo un error o si pudo realizarse con exito.
/// \param list La lista donde se almacenan los empleados.
/// \param len El largo de la lista donde se almacenan los empleados.
void OrdenarEmpleadosPorApellidoSector(Employee list[], int len);

/// \fn void MostrarDatosSalariales(Employee[], int)
/// \brief Invoca a las funciones relacionados con mostrar el total del salario de los empleados, su promedio y cuantos de ellos superan al
/// promedio. Imprimiendo los resultados por pantalla, y también indicando si hubo un error o si pudo realizarse con exito.
/// \param list
/// \param len
void MostrarDatosSalariales(Employee list[], int len);

#endif /* INFORMES_H_ */
