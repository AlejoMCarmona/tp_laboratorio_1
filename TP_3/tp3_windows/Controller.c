#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	char confirmacion;
	FILE* pArchive;
	retorno = -1;

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = 0;
		if (ll_isEmpty(pArrayListEmployee) == 0) {
			retorno = PedirConfirmacionConIntentos(&confirmacion, "ALERTA: Ya hay una lista creada con empleados. ¿Desea sobreescribirla? ", "ERROR. ALERTA: Ya hay una lista creada con empleados. ¿Desea sobreescribirla? ", 5);
			if (retorno == 1 && confirmacion == 's') {
				ll_clear(pArrayListEmployee);
				retorno = 0;
			} else {
				retorno = -1;
			}
		}

		if (retorno == 0) {
			pArchive = fopen(path, "r");
			if (pArchive != NULL) {
				retorno = parser_EmployeeFromText(pArchive, pArrayListEmployee);
				if (retorno == -1 && ll_isEmpty(pArrayListEmployee) == 0) {
					ll_clear(pArrayListEmployee);
				}
			} else {
				printf("No se ha encontrado el archivo. ");
			}
		    fclose(pArchive);
		}

	}

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	char confirmacion;
	FILE* pArchive;
	retorno = -1;

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = 0;
		if (ll_isEmpty(pArrayListEmployee) == 0) {
			retorno = PedirConfirmacionConIntentos(&confirmacion, "ALERTA: Ya hay una lista creada con empleados. ¿Desea sobreescribirla? ", "ERROR. ALERTA: Ya hay una lista creada con empleados. ¿Desea sobreescribirla? ", 5);
			if (retorno == 1 && confirmacion == 's') {
				ll_clear(pArrayListEmployee);
				retorno = 0;
			} else {
				retorno = -1;
			}
		}

		if (retorno == 0) {
			pArchive = fopen(path, "rb");
			if (pArchive != NULL) {
				retorno = parser_EmployeeFromBinary(pArchive, pArrayListEmployee);
				if (retorno == -1 && ll_isEmpty(pArrayListEmployee) == 0) {
					ll_clear(pArrayListEmployee);
				}
			} else {
				printf("No se ha encontrado el archivo. ");
			}
		    fclose(pArchive);
		}

	}

    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int lastId;
	Employee* employeeAux;
	retorno = -1;

	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		lastId = parser_LastIDFromText(); ;
		if (lastId != -1) {
			employeeAux = employee_EnterNewEmployeeData(lastId);
			if (employeeAux != NULL) {
				retorno = ll_add(pArrayListEmployee, employeeAux);
				if (retorno == 0) {
					employee_addLastIDEmployeeToFile(lastId);
				} else {
					employee_delete(employeeAux);
				}
			}
		}
	} else {
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	Employee* employee;
	Employee* employeeAux;
	retorno = -1;

	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		retorno = IngresarEntero(&id, "Ingrese el ID del empleado a modificar: ");
		if (retorno == 1) {
			employee = employee_findEmployeeById(pArrayListEmployee, id);
			if (employee != NULL) {
				printf("----Empleado a modificar----\n");
				employee_showEmployee(employee);
				employeeAux = employee_copyEmployeeToEmployeeAux(employee);
				if (employeeAux != NULL) {
					retorno = employee_editEmployee(pArrayListEmployee, employee, employeeAux);
					if (retorno == -1 || retorno == -2) {
						employee_delete(employeeAux);
						if (retorno == -1) {
							printf("No se pudo modificar el empleado correctamente. ");
						}
					}
				} else {
					retorno = -1;
				}
			} else {
				printf("Empleado a modificar no encontrado. ");
				retorno = -1;
			}
		} else {
			retorno = -1;
		}
	} else {
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int index;
	int id;
	Employee* employee;
	retorno = -1;

	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		retorno = IngresarEntero(&id, "Ingrese el ID del empleado a remover: ");
		if (retorno == 1) {
			employee = employee_findEmployeeById(pArrayListEmployee, id);
			if (employee != NULL) {
				index = ll_indexOf(pArrayListEmployee, employee);
				retorno = employee_removeEmployee(pArrayListEmployee, employee, index);
			} else {
				printf("Empleado a remover no encontrado. ");
				retorno = -1;
			}
		} else {
			retorno = -1;
		}
	} else {
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = -1;

	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		retorno = employee_listEmployees(pArrayListEmployee);
	} else {
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int opc;
	int order;
	retorno = -1;

	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		printf("¿Qué tipo de ordenamiento desea realizar?\n1- Ordenar por nombre\n2- Ordenar por ID\n");
		retorno = IngresarEnteroEntreRangosConIntentos(&opc, "Ingrese el criterio de ordenamiento: ", "ERROR. Ingrese el criterio de ordenamiento: ", 1, 2, 5);
		if (retorno == 1) {
			printf("\n¿Bajo qué tipo de orden desea el ordenamiento?\n1- Ascendente\n0- Descendente\n");
			retorno = IngresarEnteroEntreRangosConIntentos(&order, "Ingrese un orden: ", "ERROR. Ingrese un orden: ", 0, 1, 5);
			if (retorno == 1) {
				if (opc == 1) {
					retorno = ll_sort(pArrayListEmployee, employee_CompareByName, order);
				} else {
					retorno = ll_sort(pArrayListEmployee, employee_CompareById, order);
				}
			} else {
				retorno = -1;
			}
		} else {
			retorno = -1;
		}
	} else {
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArch;
	retorno = -1;

	if (pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		pArch = fopen(path, "w");
		if (pArch != NULL) {
			retorno = employee_addEmployeesToTextFile(pArch, pArrayListEmployee);
			fclose(pArch);
		}
	} else {
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE *pArch;
	retorno = -1;

	if (pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		pArch = fopen(path, "wb");
		if (pArch != NULL) {
			retorno = employee_addEmployeesToBinaryFile(pArch, pArrayListEmployee);
			fclose(pArch);
		}
	} else {
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}
