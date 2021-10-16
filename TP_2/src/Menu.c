#include "ArrayEmployees.h"
#include "Menu.h"

int MostrarMenu(int* opcion) {
	int retorno;

	printf("|||||||||||||||||||||||||||||||\n||||||NOMINA DE EMPLEADOS||||||\n|||||||||||||||||||||||||||||||\n"
		   "1. ALTAS\n"
		   "2. MODIFICAR\n"
		   "3. BAJA\n"
		   "4. INFORMAR\n"
		   "  1. Listado de los empleados ordenados alfabeticamente por apellido y sector.\n"
		   "  2. Total y promedio de los salarios, junto con la cantidad de empleados que superan el salario promedio.\n"
		   "0. SALIR\n\n");
	retorno = IngresarEntero(opcion, "Elija una opcion: ");

	return retorno;
}

int MostrarSubmenu(Employee list[], int len, int* opcion) {
	int retorno;
	retorno = 0;

	if (opcion != NULL && list != NULL && len > 0) {
		ContarEmpleados(list, len, &retorno);
		if (retorno > 0) {
			printf( "1. Listado de los empleados ordenados alfabeticamente por apellido y sector.\n"
					"2. Total y promedio de los salarios, junto con la cantidad de empleados que superan el salario promedio.\n\n");
			retorno = IngresarEnteroEntreRangosConIntentos(opcion, "Elija una opcion: ", "ERROR. Elija una opción válida: ", 1, 2, 5);
		} else {
			retorno = -2;
		}
	}

	return retorno;
}
