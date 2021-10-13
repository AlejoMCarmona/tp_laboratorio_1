#include "Informes.h"
#include "ArrayEmployees.h"

int MostrarMenu(int* opcion) {
	int validacion;

	printf("|||||||||||||||||||||||||||||||\n||||||NOMINA DE EMPLEADOS||||||\n|||||||||||||||||||||||||||||||\n"
		   "1. ALTAS\n"
		   "2. MODIFICAR\n"
		   "3. BAJA\n"
		   "4. INFORMAR\n"
		   "  1. Listado de los empleados ordenados alfabeticamente por apellido y sector.\n"
		   "  2. Total y promedio de los salarios, junto con la cantidad de empleados que superan el salario promedio.\n"
		   "0. SALIR\n\n");
	validacion = IngresarEntero(opcion, "Elija una opcion: ");

	return validacion;
}

int MostrarSubmenu(int* opcion) {
	int retorno;

	printf( "1. Listado de los empleados ordenados alfabeticamente por apellido y sector.\n"
			"2. Total y promedio de los salarios, junto con la cantidad de empleados que superan el salario promedio.\n\n");
	retorno = IngresarEntero(opcion, "Elija una opcion: ");

	return retorno;
}

void HacerAlta(Employee list[], int len, int* contadorID) {
	int retornoFuncion;
	int id;
	Employee nuevoEmpleado;
	id = *contadorID;

	retornoFuncion = CrearEmpleado(nuevoEmpleado.name, nuevoEmpleado.lastName, &nuevoEmpleado.salary, &nuevoEmpleado.sector);
	if (retornoFuncion == 1) {
		retornoFuncion = addEmployes(list, len, id, nuevoEmpleado.name, nuevoEmpleado.lastName, nuevoEmpleado.salary, nuevoEmpleado.sector);
		printf("------------------------------\n");
		if (retornoFuncion == 0) {
			printf("Empleado agregado con éxito.\n");
			*contadorID = *contadorID + 1;
		} else {
			printf("¡¡ERROR!! No se pudo agregar el empleado creado a la nomina.\n");
		}
	} else {
		printf("------------------------------\n");
		printf("¡¡ERROR!! No se pudo crear el empleado para ser agregado a la nomina.\n");
	}
}

void HacerBaja(Employee list[], int len) {
	int retornoFuncion;
	int id;
	PrintEmployees(list, len);

	retornoFuncion = IngresarEnteroConIntentos(&id, "Ingrese el ID del empleado a eliminar ", "ERROR. Reingrese el ID del empleado a eliminar ", 5);
	if (retornoFuncion == 1) {
		retornoFuncion = RemoveEmployee(list, len, id);
		if (retornoFuncion == 0) {
			printf("Empleado eliminado con exito.\n");
		} else {
			printf("¡¡ERROR!! Hubo un problema al intentar remover el empleado de la nómina.\n");
		}
	} else {
		printf("¡¡ERROR!! No se pudo ingresar correctamente el ID del empleado a eliminar.\n");
	}
}

void HacerModificacion(Employee list[], int len) {
	int retornoFuncion;
	int indice;
	int id;
	int opcion;
	PrintEmployees(list, len);

	retornoFuncion = IngresarEnteroConIntentos(&id, "Ingrese el ID del empleado a modificar ", "ERROR. Reingrese el ID del empleado a modificar ", 5);
	if (retornoFuncion == 1) {
		indice = FindEmployeeById(list, len, id);
		if (indice != -1) {
			MostrarCamposEmpleadoParaModificar(list[indice]);
			retornoFuncion = IngresarEnteroConIntentos(&opcion, "Elija una opción ", "¡¡ERROR!! Ingrese solo números enteros ", 5);
			if (retornoFuncion == 1) {
				retornoFuncion = ModificarEmpleado(list, len, indice, opcion);
				if (retornoFuncion == 1) {
					printf("\nModificacion realizada con éxito.\n");
				} else {
					printf("\n¡¡ERROR!! Hubo un problema a la hora de modificar el empleado.\n");
				}
			} else {
				printf("\n¡¡ERROR!! No se pudo elegir la opcion correcta.\n");
			}
		} else {
			printf("\n¡¡ERROR!! No existe actualmente ese empleado cargado en la nomina.\n");
		}
	} else {
		printf("\n¡¡ERROR!! No se pudo ingresar el ID correctamente.\n");
	}
}

void MostrarCamposEmpleadoParaModificar(Employee employee) {
	printf("ID\tNombre\t\tApellido\tSalario\t\tSector\n");
	MostrarEmpleado(employee);
	printf("\nEmpleado encontrado ¿Qué desea modificar?\n"
		   "1. Nombre\n"
		   "2. Apellido\n"
		   "3. Salario\n"
		   "4. Sector\n\n");
}

void OrdenarEmpleadosPorApellidoSector(Employee list[], int len) {
	int retornoFuncion;
	int opcion;

	printf("Elija el tipo de ordenamiento: \n"
		   "0. Descendente\n"
		   "1. Ascendente.\n\n");
	retornoFuncion = IngresarEntero(&opcion, "Elija la opcion: ");
	if (retornoFuncion == 1) {
		retornoFuncion = SortEmployees(list, len, opcion);
		if (retornoFuncion == 0) {
			printf("Ordenamiento realizado con éxito.\n");
			PrintEmployees(list, len);
		} else {
			printf("¡¡ERROR!! Hubo un problema al realizar el ordenamiento.\n");
		}
	} else {
		printf("¡¡ERROR!! No se pudo ingresar la opcion correcta de ordenamiento.\n");
	}
}

void MostrarDatosSalariales(Employee list[], int len) {
	int retornoFuncion;
	int cantEmpleadosSuperanSalarioPromedio;
	float salarioAcumulado;
	float salarioPromedio;

	retornoFuncion = CalcularSalariosEmpleados(list, len, &salarioAcumulado, &salarioPromedio);
	if (retornoFuncion == 1) {
		cantEmpleadosSuperanSalarioPromedio = ContarCantEmpleadosQueSuperanSalarioPromedio(list, len, salarioPromedio);
		printf("Total de salarios actual: %f\n"
			   "Promedio de los salarios: %f\n"
			   "Cantidad de empleados que superan el salario promedio: %d\n\n",
			   salarioAcumulado,
			   salarioPromedio,
			   cantEmpleadosSuperanSalarioPromedio);
	} else {
		printf("¡¡ERROR!! No se pudo mostrar el total de salarios actual, ni el promedio de los mismos, ni tampoco la cantidad de empleados que superan el salario promedio.\n\n");
	}
}
