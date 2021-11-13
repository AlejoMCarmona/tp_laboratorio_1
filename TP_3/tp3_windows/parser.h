#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Employee.h"

/// \fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
/// \param pFile Archivo donde se almacenan los empleados como texto
/// \param pArrayListEmployee Lista enlazada donde se van a almacenar los empleados
/// \return Retorna 0 si se pudo cargar la lista correctamente - (-1) si no se pudo debido a un error en el proceso de carga.
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/// \fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// \brief Parsea los datos de los empleados desde el archivo data.bin (modo binario).
/// \param pFile Archivo donde se almacenan los empleados como texto
/// \param pArrayListEmployee Lista enlazada donde se van a almacenar los empleados
/// \return Retorna 0 si se pudo cargar la lista correctamente - (-1) si no se pudo debido a un error en el proceso de carga.
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/// \fn int parser_LastIDFromText()
/// \brief Parsea el ultimo ID creado almacenado como texto en un archivo a entero para ser utilizado en la creacion de nuevos empleados
/// \return El ultimo ID almacenado en el archivo de texto - (-1) si no se pudo obtener debido a un error en el proceso (archivo no encontrado
/// o error al obtener el dato de este)
int parser_LastIDFromText();

#endif /* PARSER_H_ */
