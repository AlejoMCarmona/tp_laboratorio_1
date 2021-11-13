#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "Input.h"
#include "LinkedList.h"
#include <limits.h>

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/// \fn Employee employee_new*()
/// \brief Crea espacio en memoria dinamica para dar de alta un nuevo empleado
/// \return Retorna un puntero a empleado en memoria dinamica - NULL si no se pudo crear espacio en memoria
Employee* employee_new();

/// \fn Employee employee_newParametros*(char*, char*, char*, char*)
/// \brief Crea un nuevo empleado en memoria dinamica. Se utiliza para parsear los datos que se obtienen del archivo de texto para ser
/// almacenados en la lista enlazada como empleados
/// \param idStr ID del empleado, almacenado como cadena de caracteres
/// \param nombreStr Nombre del empleado
/// \param horasTrabajadasStr Las horas trabajadas por el empleado, almacenado como cadena de caracteres
/// \param sueldoStr El sueldo del empleado, almacenado como cadena de caracteres
/// \return Retorna un puntero a empleado en memoria dinamica - NULL si no se pudo crear espacio en memoria
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/// \fn void employee_delete(Employee*)
/// \brief Elimina un empleado, liberando el espacio en memoria donde este se encontraba almacenado
/// \param employee Puntero hacia el empleado a eliminar
void employee_delete(Employee* employee);

//getters y setters:
/// \fn int employee_setId(Employee*, int)
/// \brief Setea el ID de un empleado
/// \param this Puntero a empleado al que se le va a colocar ese ID
/// \param id ID a setear
/// \return Retorna 1 si pudo setear correctamente el ID - 0 si no pudo (puntero nulo o ID menor a cero)
int employee_setId(Employee* this,int id);

/// \fn int employee_getId(Employee*, int*)
/// \brief Obtiene el ID de un empleado
/// \param this Puntero a empleado del que se obtiene el ID
/// \param id Puntero a un entero donde se va a almacenar el ID obtenido
/// \return Retorna 1 si pudo obtener el ID - 0 si no pudo (puntero nulo)
int employee_getId(Employee* this,int* id);

/// \fn int employee_setNombre(Employee*, char*)
/// \brief Setea el nombre de un empleado
/// \param this Puntero a empleado donde se va a almacenar el nombre
/// \param nombre Cadena de caracteres que representa el nombre a ser almacenado
/// \return Retorna 1 si pudo setear correctamente el nombre - 0 si no pudo (puntero nulo)
int employee_setNombre(Employee* this,char* nombre);

/// \fn int employee_getNombre(Employee*, char*)
/// \brief Obtiene el nombre de un empleado
/// \param this Puntero a empleado del que se obtiene el nombre
/// \param nombre Cadena de caracteres donde se va a almacenar el nombre obtenido
/// \return Retorna 1 si pudo obtener el nombre - 0 si no pudo (puntero nulo)
int employee_getNombre(Employee* this,char* nombre);

/// \fn int employee_setHorasTrabajadas(Employee*, int)
/// \brief Setea las horas trabajadas de un empleado
/// \param this Puntero a empleado donde se van a almacenar las horas trabajadas
/// \param horasTrabajadas Las horas trabajadas por el empleado
/// \return Retorna 1 si pudo setear correctamente las horas trabajadas - 0 si no pudo (puntero nulo u horas trabajadas menor o igual a 0)
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// \fn int employee_getHorasTrabajadas(Employee*, int*)
/// \brief Obtiene las horas trabajadas de un empleado
/// \param this Puntero a empleado del que se obtienen las horas trabajadas
/// \param nombre Puntero a entero donde se van a almacenar la cantidad de horas trabajadas
/// \return Retorna 1 si pudo obtener las horas trabajadas - 0 si no pudo (puntero nulo)
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// \fn int employee_setSueldo(Employee*, int)
/// \brief Setea el sueldo de un empleado
/// \param this Puntero a empleado donde se va a almacenar el sueldo
/// \param sueldo El sueldo del empleado
/// \return Retorna 1 si pudo setear correctamente el sueldo - 0 si no pudo (puntero nulo o sueldo menor o igual a 0)
int employee_setSueldo(Employee* this,int sueldo);

/// \fn int employee_getSueldo(Employee*, int*)
/// \brief Obtiene el sueldo de un empleado
/// \param this Puntero a empleado del que se obtiene el sueldo
/// \param nombre Puntero a entero donde se va a almacenar el sueldo
/// \return Retorna 1 si pudo obtener el sueldo - 0 si no pudo (puntero nulo)
int employee_getSueldo(Employee* this,int* sueldo);

//funciones para ordenar:
/// \fn int employee_CompareByName(void*, void*)
/// \brief Compara el nombre de dos empleados
/// \param e1 Puntero al primer empleado a comparar
/// \param e2 Puntero al segundo empleado a comparar
/// \return Retorna 0 si los nombres de los empleados son iguales - (1) si el nombre del primer empleado es mayor que el del segundo -
/// (-1) si el nombre del segundo empleado es mayor que el del primero - (-2) si hubo un error
int employee_CompareByName(void* e1, void* e2);

/// \fn int employee_CompareById(void*, void*)
/// \brief Compara el ID de dos empleados
/// \param e1 Puntero al primer empleado a comparar
/// \param e2 Puntero al segundo empleado a comparar
/// \return Retorna 0 si los ID de los empleados son iguales - (1) si el ID del primer empleado es mayor que el del segundo -
/// (-1) si el ID del segundo empleado es mayor que el del primero - (-2) si hubo un error
int employee_CompareById(void* e1, void* e2);

//funciones agregadas:
/// \fn int employee_showEmployee(Employee*)
/// \brief Muestra los datos de un empleado
/// \param employee Puntero al empleado a mostrar
/// \return Retorna 0 si pudo mostrarlo correctamente - (-1) si hubo un error (puntero nulo)
int employee_showEmployee(Employee* employee);

/// \fn int employee_setEmployee(Employee*, int, char*, int, int)
/// \brief Asigna todos los datos a un empleado
/// \param employee Puntero al empleado en el que se van a almacenar los datos
/// \param id ID del empleado
/// \param nombreStr Nombre del empleado
/// \param horasTrabajadas Horas trabajadas del empleado
/// \param sueldo Sueldo del empleado
/// \return Retorna 1 si se pudieron almacenar todos los datos correctamente - 0 si hubo un error
int employee_setEmployee(Employee* employee, int id, char* nombreStr, int horasTrabajadas, int sueldo);

/// \fn Employee employee_EnterNewEmployeeData*(int)
/// \brief Se le permite al usuario la carga de los datos de un nuevo empleado, reservando espacio en memoria dinamica
/// para hacerlo
/// \param id ID del último empleado ingresado
/// \return Retorna un puntero al empleado creado en memoria dinamica si se pudieron ingresar bien los datos del msimo - NULL
/// si no se pudieron ingresar correctamente los datos
Employee* employee_EnterNewEmployeeData(int id);

/// \fn Employee employee_findEmployeeById*(LinkedList*, int)
/// \brief Buscar un empleado por ID y lo retorna si es que lo encuentra
/// \param this Puntero a la lista enlazada
/// \param id ID del empleado a buscar
/// \return Retorna un puntero al empleado si es que lo encuentra - NULL si hubo un error (empleado no encontrado o puntero nulo)
Employee* employee_findEmployeeById(LinkedList* this, int id);

/// \fn int employee_addEmployeesToTextFile(FILE*, LinkedList*)
/// \brief Almacena la lista de empleados en un archivo de texto
/// \param pArch Archivo donde se van a almacenar los empleados como texto
/// \param pArrayListEmployee Puntero a la lista enlazada de empleados
/// \return Retorna 0 si pudo almacenar la lista de manera correcta - (-1) si no pudo hacerlo debido a un error
int employee_addEmployeesToTextFile(FILE* pArch, LinkedList* pArrayListEmployee);

/// \fn int employee_addEmployeesToBinaryFile(FILE*, LinkedList*)
/// \brief Almacena la lista de empleados en un archivo binario
/// \param pArch Archivo donde se van a almacenar los empleados como texto
/// \param pArrayListEmployee Puntero a la lista enlazada de empleados
/// \return Retorna 0 si pudo almacenar la lista de manera correcta - (-1) si no pudo hacerlo debido a un error
int employee_addEmployeesToBinaryFile(FILE* pArch, LinkedList* pArrayListEmployee);

/// \fn int employee_listEmployees(LinkedList*)
/// \brief Muestra la lista de empleados
/// \param pArrayListEmployee Puntero a la lista de empleados
/// \return Retorna 0 si se pudieron listar los empleados en su totalidad - (-1) si hubo algun error
int employee_listEmployees(LinkedList* pArrayListEmployee);

/// \fn int employee_addLastIDEmployeeToFile(int)
/// \brief Almacena el ultimo ID ingresado para un empleado en un archivo de texto
/// \param id Anteultimo ID creado. Por lo que se aumenta en uno antes de ser almacenado en el archivo para persistir el último
/// \return Retorna un numero negativo si no se pudo almacenar el ID correctamente, o el numero de bytes que fueron almacenados
/// en el archivo
int employee_addLastIDEmployeeToFile(int id);

/// \fn int employee_ChooseModifyOptions()
/// \brief Muestra las opciones disponibles para modificar un empleado, y se le pide al usuario que elija una opcion
/// \return Retorna 0 si no se pudo elegir una opcion correctamente, o la opcion elegida por el usuario
int employee_ChooseModifyOptions();

/// \fn int employee_editEmployee(LinkedList*, Employee*, Employee*)
/// \brief Permite editar un empleado de la lista, elegiendo el campo donde hacerlo
/// \param pArrayListEmployee Puntero a la lista de empleados
/// \param employee Puntero al empleado a modificar
/// \param employeeAux Puntero al empleado auxiliar que se va a utilizar para modificar
/// \return Retorna 0 si pudo editarse correctamente - (-1) si no se pudo editar el empleado correctamente -
/// (-2) si se canceló la operación
int employee_editEmployee(LinkedList* pArrayListEmployee, Employee* employee, Employee* employeeAux);

/// \fn int employee_removeEmployee(LinkedList*, Employee*, int)
/// \brief Remueve un empleado de la lista enlazada
/// \param pArrayListEmployee Puntero a la lista de empleados
/// \param employee Puntero al empleado a remover
/// \param index Indice de la lista enlazada en el que se encuentra el empleado a remover
/// \return Retorna 0 si pudo removerse correctamente - (-1) si hubo un error y no pudo remover correctamente -
/// (-2) si la operación fue cancelada.
int employee_removeEmployee(LinkedList* pArrayListEmployee, Employee* employee, int index);

/// \fn Employee employee_copyEmployeeToEmployeeAux*(Employee*)
/// \brief Copia todos los datos de un empleado en otro, reservando espacio en memoria dinamica para almacenarlo
/// \param employee Puntero al empleado que se va a copiar
/// \return Retorna un puntero a la copia del empleado - NULL si hubo un error en la copia
Employee* employee_copyEmployeeToEmployeeAux(Employee* employee);

#endif // employee_H_INCLUDED
