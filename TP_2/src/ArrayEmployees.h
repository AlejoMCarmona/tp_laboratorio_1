#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define EMPTY 0
#define FULL 1
#include "Input.h"
#include <Float.h>

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

/// \fn int InitEmployees(Employee[], int)
/// \brief Para indicar que todas las posiciones del array estan vacias, esta funcion pone la bandera (isEmpty) en TRUE en todas las posiciones
/// del array.
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \return Retorna (-1) si hubo un error (Tamanio invalido o puntero nulo) - (0) si Ok
int InitEmployees (Employee list[], int len);

/// \fn int BuscarPrimerEspacioLibre(Employee[], int)
/// \brief Busca el primer espacio libre en el array de empleados y devuelve su indice o -1 en caso de que no haya espacios libres
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \return -1 si no encontro un espacio libre en el array o 0 si lo encontró
int BuscarPrimerPosicionLibre(Employee list[], int len);

/// \fn int CrearEmpleado(char[], char[], float*, int*)
/// \brief Le pide al usuario que ingrese los datos de un nuevo empleado, validando que se ingresen de manera correcta y pasandolos como
/// parametros por referencia.
/// \param name Puntero a la cadena donde se almacena el nombre del empleado.
/// \param lastName Puntero a la cadena donde se almacena el apellido del empleado.
/// \param salary Puntero al float donde se almacena el salario del empleado.
/// \param sector Puntero al integer donde se almacena el sector del empleado.
/// \return 1 si se pudo crear de manera correcta, o 0 si no lo hizo
int CrearEmpleado(char name[], char lastName[], float* salary, int* sector);

/// \fn int addEmployes(Employee[], int, int, char[], char[], float, int)
/// \brief Agrega una lista de empleados existente, los valores recibidos como parametros
/// en la primera posicion vacia
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \param id Ultimo ID asignado a un empleado
/// \param name Puntero a la cadena donde se almacena el nombre del nuevo empleado
/// \param lastName Puntero a la cadena donde se almacena el apellido del nuevo empleado
/// \param salary Salario a ser asignado al nuevo empleado
/// \param sector Sector a ser asignado al nuevo empleado
/// \return Retorna (-1) si el hubo un error (Tamanio invalido o puntero nulo o no hay
/// espacio libre) - (0) si Ok
int addEmployes(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);

/// \fn int CargarUnEmpleado(Employee[], int, int, int, char[], char[], float, int)
/// \brief Carga un empleado en el array de empleados, con los datos pasados como parametros
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \param indice Indice donde se va a almacenar el empleado
/// \param id Ultimo ID asignado a un empleado
/// \param name Puntero a la cadena donde se almacena el nombre del nuevo empleado
/// \param lastName Puntero a la cadena donde se almacena el apellido del nuevo empleado
/// \param salary Salario a ser asignado al nuevo empleado
/// \param sector Sector a ser asignado al nuevo empleado
/// \return -1 si hubo un error y no se pudo cargar el empleado, o 0 si se pudo
int CargarUnEmpleado(Employee list[], int len, int indice, int id, char name[], char lastName[], float salary, int sector);

/// \fn int PrintEmployees(Employee[], int)
/// \brief Imprime el contenido del array de empleados.
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \return Retorna (-1) si hubo un error (Tamanio invalido o puntero nulo o no se
/// encontraron empleados para mostrar) - (0) si Ok
int PrintEmployees(Employee list[], int len);

/// \fn void MostrarEmpleado(Employee[], int) --CAMBIAR!
/// \brief Muestra un empleado del array
/// \param list Puntero al array de empleados
/// \param indice Indice del empleado a mostrar en el array
void MostrarEmpleado(Employee employee);

/// \fn void MostrarCamposEmpleadoParaModificar(Employee)
/// \brief Muestra al empleado seleccionado para modificar y los campos disponibles para hacerlo
/// \param employee El empleado a ser modificado
void MostrarCamposEmpleadoParaModificar(Employee employee);

/// \fn int FindEmployeeById(Employee[], int, int)
/// \brief Busca un empleado por ID y retorna el indice de su posicion en el array.
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \param id El ID del empleado a buscar
/// \return Retorna (-1) si hubo un error (Tamanio invalido o puntero nulo o no se
/// encontro a un empleado con ese ID) - (0) si Ok
int FindEmployeeById(Employee list[], int len, int id);

/// \fn int RemoveEmployee(Employee[], int, int)
/// \brief Remueve un empleado por ID (Colocando su bandera isEmpty en EMPTY).
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \param id El ID del empleado a remover
/// \return Retorna (-1) si el hubo un error (Tamanio invalido o puntero nulo o no se
/// encontro a un empleado con ese ID) - (0) si Ok
int RemoveEmployee(Employee list[], int len, int id);

/// \fn int ModificarEmpleado(Employee[], int, int, int)
/// \brief Modifica un empleado por ID, recibiendo como parametro la opcion elegida para modificar.
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \param indice El indice donde se encuentra el empleado a modificar
/// \param opcion La opcion elegida que indica el campo a ser modificado
/// \return Retorna 0 si el puntero es nulo o el tamanio es invalido o la opcion es incorrecta, y 1
/// pudo modificarse.
int ModificarEmpleado(Employee list[], int len, int indice, int opcion);

/// \fn int ContarEmpleados(Employee[], int)
/// \brief Cuenta la cantidad de empleados activos en la nomina (bandera isEmpty en FULL)
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \return La cantidad de empleados actuales
int ContarEmpleados(Employee list[], int len);

/// \fn int SortEmployees(Employee[], int, int)
/// \brief Ordena a los elementos del array de empleados, el argumento "order"
/// indica si el ordenamiento es ascendente o ascendente.
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \param order 1 indica "ascendente" - 0 indica "descendente"
/// \return Retorna (-1) si el puntero es nulo o si el tamanio es invalido y 0 si pudo realizarse el ordenamiento
int SortEmployees (Employee list[], int len, int order);

/// \fn int SortEmployeesUp(Employee[], int)
/// \brief Ordena de manera ascendente el array de empleados
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \return Retorna (-1) si el puntero es nulo o si el tamanio es invalido y 0 si pudo realizarse el ordenamiento.
int SortEmployeesUp(Employee list[], int len);

/// \fn int SortEmployeesDown(Employee[], int)
/// \brief Ordena de manera descendente el array de empleados
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \return Retorna (-1) si el puntero es nulo o si el tamanio es invalido y 0 si pudo realizarse el ordenamiento.
int SortEmployeesDown(Employee list[], int len);

/// \fn int CalcularSalariosEmpleados(Employee[], int, float*, float*)
/// \brief Calcula lo relacionado con los salarios de los empleados de la empresa (salario acumulado total, promedio del
/// salario, y cantidad de empleado que cobran mas que el promedio)
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \param salarioAcumulado Salario acumulado de todos los empleados
/// \param salarioPromedio Salario promedio de toda la nomina
/// \return 1 si pudo realizarse toda la operacion con exito, 0 si no se pudo
int CalcularSalariosEmpleados(Employee list[], int len, float* salarioAcumulado, float* salarioPromedio);

/// \fn float AcumularSalario(Employee[], int)
/// \brief Acumula el salario de todos los empleados activos de la nomina
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \return 1 si pudo acumularse el salario correctamente, 0 si no se pudo
float AcumularSalario(Employee list[], int len);

/// \fn int ContarCantEmpleadosQueSuperanSalarioPromedio(Employee[], int, float)
/// \brief Cuenta la cantidad de empleados que superan el salario promedio
/// \param list Puntero al array de empleados
/// \param len Tamanio del array
/// \param salarioPromedio Salario promedio de toda la nomina
/// \return La cantidad de empleados que superan el salario promedio
int ContarCantEmpleadosQueSuperanSalarioPromedio(Employee list[], int len, float salarioPromedio);

#endif /* ARRAYEMPLOYEES_H_ */
