#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED
#include "Employee.h"
#include "parser.h"

/// \fn int controller_loadFromText(char*, LinkedList*)
/// \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
/// \param path Ruta hacia el archivo de texto
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudieron cargar los empleados desde el archivo correctamente - (-1) si hubo un error
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_loadFromBinary(char*, LinkedList*)
/// \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
/// \param path Ruta hacia el archivo binario
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudieron cargar los empleados desde el archivo correctamente - (-1) si hubo un error
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_addEmployee(LinkedList*)
/// \brief Permite realizar el alta de un empleado
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudo dar de alta un empleado - (-1) si hubo un error
int controller_addEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_editEmployee(LinkedList*)
/// \brief Permite editar un empleado
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudo editar un empleado - (-1) si hubo un error - (-2) si se cancelo la operacion
int controller_editEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_removeEmployee(LinkedList*)
/// \brief Permite remover un empleado
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudo remover un empleado - (-1) si hubo un error - (-2) si se cancelo la operacion
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_ListEmployee(LinkedList*)
/// \brief Lista todos los empleados de la lista
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudo listar a los empleados correctamente - (-1) si hubo un error
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_sortEmployee(LinkedList*)
/// \brief Ordena los empleados de la lista bajo un criterio
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudo ordenar la lista de empleados - (-1) si hubo un error
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_saveAsText(char*, LinkedList*)
/// \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
/// \param path Ruta del archivo donde se van a almacenar los empleados como texto
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudo almacenar la lista de empleados - (-1) si hubo un error
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_saveAsBinary(char*, LinkedList*)
/// \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
/// \param path Ruta del archivo donde se van a almacenar los empleados en modo binario
/// \param pArrayListEmployee Puntero a la lista enlazada
/// \return Retorna 0 si se pudo almacenar la lista de empleados - (-1) si hubo un error
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

#endif // controller_H_INCLUDED
