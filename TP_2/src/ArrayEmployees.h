#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define EMPTY 1
#define FULL 0
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
/// \param len Tamaño del array
/// \return Retorna (-1) si hubo un error (Tamaño invalido o puntero nulo) - (0) si Ok
int InitEmployees (Employee list[], int len);

/// \fn int BuscarPrimeraEspacioLibre(Employee[], int)
/// \brief Busca el primer espacio libre en el array de empleados y devuelve su indice o -1 en caso de que no haya espacios libres
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \return -1 si no encontro un espacio libre en el array o 0 si lo encontró
int BuscarPrimeraPosicionLibre(Employee list[], int len);

/// \fn int HacerAlta(Employee[], int, int*)
/// \brief Permite hacer el alta de un empleado, agregando sus datos individuales para luego agregarlo a la lista.
/// \param list Puntero al array de empleados.
/// \param len El largo de la lista donde se almacenan los empleados.
/// \param contadorID Puntero a entero que almacena el contador que se utiliza para crear los ID de los nuevos empleados.
/// \return Retorna 1 si pudo hacer el alta correctamente - (-1) si no hay espacio libre en la lista de empleados - 0 si el puntero
/// es nulo, o el tamaño invalido.
int HacerAlta(Employee list[], int len, int* contadorID);

/// \fn int CrearEmpleado(Employee*, int)
/// \brief Crea un empleado pidiendo al usuario que ingrese sus datos
/// \param employee Puntero a empleado
/// \param id Contador que contiene el ultimo id asignado a un empleado
/// \return Retorna 1 en caso de haber creado el empleado correctamente - 0 en caso de puntero nulo
int CrearEmpleado(Employee* employee, int id);

/// \fn int addEmployes(Employee[], int, int, char[], char[], float, int)
/// \brief Agrega a una lista de empleados existente los valores recibidos como parametros
/// en la primera posicion vacia
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \param id Ultimo ID asignado a un empleado
/// \param name Puntero a la cadena donde se almacena el nombre del nuevo empleado
/// \param lastName Puntero a la cadena donde se almacena el apellido del nuevo empleado
/// \param salary Salario a ser asignado al nuevo empleado
/// \param sector Sector a ser asignado al nuevo empleado
/// \return Retorna (-1) si hubo un error (Tamaño invalido o puntero nulo o no hay
/// espacio libre) - (0) si se pudo agregar el empleado a la lista
int addEmployes(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);

/// \fn void HacerModificacion(Employee[], int)
/// \brief Permite modificar un empleado. Se imprime la lista de empleados y se le pide al usuario que ingrese el ID del
/// empleado a modificar, luego se da a elegir si quiere modificar el nombre, apellido, salario o sector del mismo.
/// \param list Puntero al array de empleados.
/// \param len Tamaño del array de empleados.
int HacerModificacion(Employee list[], int len);

/// \fn int ModificarEmpleado(Employee[], int, int, int)
/// \brief Modifica el campo enviado por parámetro, del empleado elegido previamente. Se le pide al usuario que ingrese
/// el nuevo valor para el mismo.
/// \param len Tamaño del array
/// \param indice El indice donde se encuentra el empleado a modificar
/// \param opcion La opcion elegida que indica el campo a ser modificado
/// \return Retorna 0 si el puntero es nulo, si el tamaño o el puntero son invalidos, o si la opcion es incorrecta - 1
/// si pudo modificarse correctamente.
int ModificarEmpleado(Employee list[], int len, int indice, int opcion);

/// \fn void MostrarCamposEmpleadoParaModificar(Employee)
/// \brief Muestra al empleado seleccionado para modificar y los campos disponibles para hacerlo
/// \param employee El empleado a ser modificado
void MostrarCamposEmpleadoParaModificar(Employee employee);

/// \fn void HacerBaja(Employee[], int)
/// \brief Permite dar de baja un empleado del array, imprimiendo los empleados para luego ingresar el ID del mismo.
/// \param list Puntero al array de empleados.
/// \param len Tamaño del array de empleados.
int HacerBaja(Employee list[], int len);

/// \fn int RemoveEmployee(Employee[], int, int)
/// \brief Remueve un empleado por ID (Colocando su bandera isEmpty en EMPTY).
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \param id El ID del empleado a remover
/// \return Retorna (-1) si hubo un error (Tamaño invalido o puntero nulo o no se encontró a un empleado con ese ID)
///  - (0) si Ok
int RemoveEmployee(Employee list[], int len, int id);

/// \fn int PrintEmployees(Employee[], int)
/// \brief Imprime el contenido del array de empleados.
/// \param list Puntero al array de empleados
/// \param len Tamaño del array de empleados.
/// \return Retorna (-1) si hubo un error (Tamaño invalido o puntero nulo o no se encontraron empleados para mostrar)
/// - (0) si Ok
int PrintEmployees(Employee list[], int len);

/// \fn void MostrarEmpleado(Employee)
/// \brief Muestra un empleado del array
/// \param employee Empleado a mostrar
void MostrarEmpleado(Employee employee);

/// \fn int FindEmployeeById(Employee[], int, int)
/// \brief Busca un empleado por ID y retorna el indice de su posicion en el array.
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \param id El ID del empleado a buscar
/// \return Retorna (-1) si hubo un error (Tamaño invalido o puntero nulo o no se encontro a un empleado con ese ID)
/// - (0) si Ok
int FindEmployeeById(Employee list[], int len, int id);

/// \fn int ContarEmpleados(Employee[], int, int*)
/// \brief Cuenta la cantidad de empleados activos en la nomina (bandera isEmpty en FULL)
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \param cantidadEmpleados Puntero a entero donde se almacena la cantidad de empleados
/// \return Retorna la cantidad de empleados actuales - (-1) si hubo un error (puntero nulo o tamaño inválido)
int ContarEmpleados(Employee list[], int len, int* cantidadEmpleados);

/// \fn void OrdenarEmpleadosPorApellidoSector(Employee[], int)
/// \brief Le pregunta al usuario si desea ordenar el array de empleados de manera ascendente o descendente, para luego realizar el ordenamiento elegido e
/// imprimir los resultados por pantalla, en caso de realizarse con exito.
/// \param list Puntero al array de empleados.
/// \param len Tamaño del array.
int OrdenarEmpleadosPorApellidoSector(Employee list[], int len);

/// \fn int SortEmployees(Employee[], int, int)
/// \brief Ordena a los elementos del array de empleados, el argumento "order" indica si el ordenamiento es ascendente o ascendente.
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \param order 1 indica "ascendente" - 0 indica "descendente"
/// \return Retorna (-1) si el puntero es nulo o si el tamaño es invalido - 0 si pudo realizarse el ordenamiento
int SortEmployees (Employee list[], int len, int order);

/// \fn int SortEmployeesAscendingOrder(Employee[], int)
/// \brief Ordena de manera ascendente el array de empleados
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \return Retorna (-1) si el puntero es nulo o si el tamaño es invalido - 0 si pudo realizarse el ordenamiento.
int SortEmployeesAscendingOrder(Employee list[], int len);

/// \fn int SortEmployeesDescendingOrder(Employee[], int)
/// \brief Ordena de manera descendente el array de empleados
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \return Retorna (-1) si el puntero es nulo o si el tamaño es invalido - 0 si pudo realizarse el ordenamiento.
int SortEmployeesDescendingOrder(Employee list[], int len);

/// \fn int CalcularSalariosEmpleados(Employee[], int, float*, float*)
/// \brief Calcula el salario acumulado de todos los empleados de la empresa, y también el promedio de salario entre
/// todos ellos.
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \param salarioAcumulado Puntero a flotante que almacena el salario acumulado de todos los empleados
/// \param salarioPromedio Puntero a flotante que almacena e el salario promedio entre todos los empleados
/// \return Retorna 1 si pudo realizar la operacion con exito - 0 si hubo un error (puntero nulo o tamaño invalido)
int CalcularSalariosEmpleados(Employee list[], int len, float* salarioAcumulado, float* salarioPromedio);

/// \fn int AcumularSalario(Employee[], int, float*)
/// \brief Acumula el salario de todos los empleados activos de la nomina (bandera isEmpty en FULL)
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \return Retorna 1 si pudo acumularse el salario correctamente - 0 si hubo un error (puntero nulo o tamaño invalido)
int AcumularSalario(Employee list[], int len, float* salarioAcumulado);

/// \fn int ContarCantEmpleadosQueSuperanSalarioPromedio(Employee[], int, float)
/// \brief Cuenta la cantidad de empleados que superan el salario promedio
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \param salarioPromedio Salario promedio de toda la nomina
/// \param cantidadEmpleados Puntero a entero que almacena la cantidad de empleados
/// \return Retorna 1 pudo contar los empleados con éxito - 0 si hubo un error (puntero nulo o tamaño invalido)
int ContarCantEmpleadosQueSuperanSalarioPromedio(Employee list[], int len, float salarioPromedio, int* cantidadEmpleados);

/// \fn int ImprimirDatosSalariales(Employee[], int)
/// \brief Calcula los datos salariales de los empleados (salario acumulado y salario promedio), y luego calcula cuantos
/// empleados superan ese salario promedio para finalmente, imprimir todos los datos.
/// \param list Puntero al array de empleados
/// \param len Tamaño del array
/// \return Retorna 1 si pudo calcular e imprimir los datos correctamente - 0 si no hubo un error (puntero nulo o tamaño inválido)
int ImprimirDatosSalariales(Employee list[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
