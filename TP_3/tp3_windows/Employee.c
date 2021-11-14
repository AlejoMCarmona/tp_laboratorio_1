#include "Employee.h"

Employee* employee_new() {
	Employee* employee;
	employee = (Employee*) malloc(sizeof(Employee));
	return employee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr) {
	Employee* employee;
	int retorno;
	int id;
	int horas;
	int sueldo;
	employee = NULL;

	if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL) {
		employee = employee_new();
		if (employee != NULL) {
			id = atoi(idStr);
			horas = atoi(horasTrabajadasStr);
			sueldo = atoi(sueldoStr);

			retorno = employee_setEmployee(employee, id, nombreStr, horas, sueldo);
			if (retorno == 0){
				 employee_delete(employee);
				 employee = NULL;
			}
		}
	}

	return employee;
}

void employee_delete(Employee* employee){
	if (employee != NULL) {
		free(employee);
	}
}

//setters:
int employee_setId(Employee* this,int id) {
	int retorno;
	retorno = 0;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre) {
	int retorno;
	retorno = 0;

	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno;
	retorno = 0;

	if (this != NULL && horasTrabajadas > 0) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo) {
	int retorno;
	retorno = 0;

	if (this != NULL && sueldo > 0) {
		this->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}


int employee_setEmployee(Employee* employee, int id, char* nombreStr, int horasTrabajadas, int sueldo) {
	int retorno;
	retorno = 0;

	if (employee != NULL && nombreStr != NULL) {
		retorno = employee_setId(employee, id);
		if (retorno == 1) {
			retorno = employee_setNombre(employee, nombreStr);
			if (retorno == 1) {
				retorno = employee_setHorasTrabajadas(employee, horasTrabajadas);
				if (retorno == 1) {
					retorno = employee_setSueldo(employee, sueldo);
				}
			}
		}
	}

	return retorno;
}

Employee* employee_EnterNewEmployeeData(int id) {
	int retorno;
	Employee* employee;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	employee = NULL;

	retorno = IngresarCadenaSoloLetrasConIntentos(nombre, sizeof(nombre), "Ingrese el nombre del empleado: ", "ERROR. Ingrese el nombre del empleado: ", 5);
	if (retorno == 1) {
		retorno = IngresarEnteroEntreRangosConIntentos(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas: ", "ERROR. Ingrese la cantidad de horas trabajadas (mayor a 0): ", 1, INT_MAX, 5);
		if (retorno == 1) {
			retorno = IngresarEnteroEntreRangosConIntentos(&sueldo, "Ingrese el sueldo del trabajador (entero): ","ERROR. Ingrese el sueldo del trabajador (entero y mayor que 0): ", 1, INT_MAX, 5);
			if (retorno == 1) {
				employee = employee_new();
				if (employee != NULL) {
					id++;
					retorno = employee_setEmployee(employee, id, nombre, horasTrabajadas, sueldo);
					if (retorno == 0) {
						employee_delete(employee);
						employee = NULL;
					}
				}
			}
		}
	}

	return employee;
}

int employee_editEmployee(LinkedList* pArrayListEmployee, Employee* employee, Employee* employeeAux) {
	int retorno;
	int opc;
	char nuevoNombre[128];
	int auxInt;
	char confirmacion;
	retorno = -1;

	if (pArrayListEmployee != NULL && employee != NULL && employeeAux != NULL) {
		opc = employee_ChooseModifyOptions();

		switch(opc) {
		case 1:
			retorno = IngresarCadenaSoloLetrasConIntentos(nuevoNombre, sizeof(nuevoNombre), "Ingrese el nuevo nombre del empleado: ", "ERROR. Ingrese el nuevo nombre del empleado: ", 5);
			if (retorno == 1) {
				employee_setNombre(employeeAux, nuevoNombre);
			}
			break;
		case 2:
			retorno = IngresarEnteroEntreRangosConIntentos(&auxInt, "Ingrese la nueva cantidad de horas trabajadas: ", "ERROR. Ingrese la nueva cantidad de horas trabajadas (mayor que 0): ", 0, INT_MAX, 5);
			if (retorno == 1) {
				retorno = employee_setHorasTrabajadas(employeeAux, auxInt);
			}
			break;
		case 3:
			retorno = IngresarEnteroEntreRangosConIntentos(&auxInt, "Ingrese el nuevo sueldo del trabajador (entero): ","ERROR. Ingrese el nuevo sueldo del trabajador (entero y mayor que cero): ", 1, INT_MAX, 5);
			if (retorno == 1) {
				retorno = employee_setSueldo(employeeAux, auxInt);
			}
			break;
		}

		if (retorno == 1) {
			retorno = PedirConfirmacionConIntentos(&confirmacion, "¿Seguro que desea realizar esta modificacion?", "ERROR. ¿Seguro que desea realizar esta modificacion?", 5);
			if (retorno == 1 && confirmacion == 's') {
				auxInt = ll_indexOf(pArrayListEmployee, employee);
				retorno = ll_set(pArrayListEmployee, auxInt, employeeAux);
			} else {
				if (confirmacion == 'n') {
					retorno = -2;
				} else {
					retorno = -1;
				}
			}
		} else {
			retorno = -1;
		}
	}

	return retorno;
}

int employee_ChooseModifyOptions() {
	int retorno;
	int opcion;

	printf("¿Qué desea modificar?\n1- Nombre\n2- Horas trabajadas\n3- Sueldo\n");
	retorno = IngresarEnteroEntreRangosConIntentos(&opcion, "Ingrese la modificacion a realizar: ", "ERROR. Ingrese la modificación a realizar: ", 1, 3, 5);
	if (retorno == 0) {
		opcion = 0;
	}

	return opcion;
}

int employee_removeEmployee(LinkedList* pArrayListEmployee, Employee* employee, int index) {
	int retorno;
	char confirmacion;
	retorno = -1;

	if (pArrayListEmployee != NULL && employee != NULL) {
		printf("--Empleado a remover--\n");
		printf("ID-Nombre-HorasTrabajadas-Sueldo\n");
		employee_showEmployee(employee);
		retorno = PedirConfirmacionConIntentos(&confirmacion, "¿Seguro que desea eliminar este empleado?", "ERROR. ¿Seguro que desea eliminar este empleado?", 5);
		if (retorno == 1 && confirmacion == 's') {
			retorno = ll_remove(pArrayListEmployee, index);
		} else {
			if (confirmacion == 'n') {
				retorno = -2;
			} else {
				retorno = -1;
			}
		}
	}

	return retorno;
}

Employee* employee_copyEmployeeToEmployeeAux(Employee* employee) {
	char nombre[128];
	int id;
	int horasTrabajadas;
	int sueldo;
	Employee* employeeAux;
	employeeAux = NULL;

	if (employee != NULL) {
		employeeAux = employee_new();
		if (employeeAux != NULL) {
			employee_getId(employee, &id);
			employee_getNombre(employee, nombre);
			employee_getHorasTrabajadas(employee, &horasTrabajadas);
			employee_getSueldo(employee, &sueldo);

			employee_setId(employeeAux, id);
			employee_setNombre(employeeAux, nombre);
			employee_setHorasTrabajadas(employeeAux, horasTrabajadas);
			employee_setSueldo(employeeAux, sueldo);
		}
	}

	return employeeAux;
}

//getters:
int employee_getId(Employee* this,int* id) {
	int retorno;
	retorno = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int employee_getNombre(Employee* this, char* nombre) {
	int retorno;
	retorno = 0;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horas) {
	int retorno;
	retorno = 0;

	if (this != NULL && horas != NULL) {
		*horas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo) {
	int retorno;
	retorno = 0;

	if (this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}

//funciones agregadas:
int employee_showEmployee(Employee* employee) {
	int retorno;
	int id;
	int sueldo;
	int horas;
	char nombre[128];
	retorno = -1;

	if (employee != NULL) {
		employee_getId(employee, &id);
		employee_getNombre(employee, nombre);
		employee_getHorasTrabajadas(employee, &horas);
		employee_getSueldo(employee, &sueldo);
		printf("%d--%s------%d----------%d\n", id, nombre, horas, sueldo);
		retorno = 0;
	}

	return retorno;
}

int employee_getLastId(LinkedList* this, int* id) {
	int retorno;
	int len;
	int i;
	int idMax;
	int idAux;
	int flagFirst;
	Employee* employee;
	flagFirst = 1;
	retorno = 0;

	if (this != NULL && id != NULL) {
		len = ll_len(this);
		for (i = 0; i < len; i++) {
			employee = (Employee*) ll_get(this, i);
			if (employee == NULL) {
				break;
			}
			employee_getId(employee, &idAux);
			if (flagFirst == 1 || idAux > idMax) {
				idMax = idAux;
				flagFirst = 0;
			}
		}
		if (i == len) {
			*id = idMax;
			retorno = 1;
		}
	}

	return retorno;
}

Employee* employee_findEmployeeById(LinkedList* this, int id) {
	int len;
	int idAux;
	int i;
	Employee* employee;
	employee = NULL;

	if (this != NULL) {
		len = ll_len(this);
		for (i = 0; i < len; i++) {
			employee = (Employee*) ll_get(this, i);
			if (employee != NULL) {
				employee_getId(employee, &idAux);
				if (idAux == id) {
					break;
				}
			}
		}
		if (i == len) {
			employee = NULL;
		}
	}

	return employee;
}

int employee_addEmployeesToTextFile(FILE* pArch, LinkedList* pArrayListEmployee){
	int retorno;
	int i;
	int id;
	char nombre[128];
	int sueldo;
	int horas;
	int len;
	Employee* employee;
	retorno = -1;

	if (pArch != NULL && pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		fprintf(pArch, "id,nombre,horasTrabajadas,sueldo\n");
		for (i = 0; i < len; i++) {
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			if (employee == NULL) {
				break;
			}
			employee_getId(employee, &id);
			employee_getNombre(employee, nombre);
			employee_getHorasTrabajadas(employee, &horas);
			employee_getSueldo(employee, &sueldo);
			fprintf(pArch, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
		}
		if (i == len) {
			retorno = 0;
		} else {
			retorno = -1;
		}
	}

	return retorno;
}

int employee_addEmployeesToBinaryFile(FILE* pArch, LinkedList* pArrayListEmployee){
	int retorno;
	int len;
	int i;
	Employee* employee;
	retorno = -1;

	if (pArch != NULL && pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		for (i = 0; i < len; i++) {
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			if (employee == NULL) {
				break;
			}
			fwrite(employee, sizeof(Employee), 1, pArch);
		}
		if (i == len) {
			retorno = 0;
		} else {
			retorno = -1;
		}
	}

	return retorno;
}

int employee_listEmployees(LinkedList* pArrayListEmployee) {
	int retorno;
	int i;
	int len;
	Employee* employeeAux;
	retorno = -1;

	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		printf("ID-Nombre-HorasTrabajadas-Sueldo\n\n");
		for (i = 0; i < len; i++) {
			employeeAux = (Employee*) ll_get(pArrayListEmployee, i);
			if (employeeAux == NULL) {
				break;
			}
			employee_showEmployee(employeeAux);
		}
		if (i == len) {
			retorno = 0;
		}
	}

	return retorno;
}

int employee_addLastIDEmployeeToFile(int id) {
	int retorno;
	retorno = 0;
	id++;

	FILE *fIdMax;
	fIdMax = fopen("idMaximo.txt", "w");
	retorno = fprintf(fIdMax, "%d", id);
	fclose(fIdMax);

	return retorno;
}

int employee_CompareByName(void* e1, void* e2) {
	int retorno;
	Employee* unEmpleado;
	Employee* otroEmpleado;
	char nombreE1[128];
	char nombreE2[128];
	retorno = -2;

	if (e1 != NULL && e2 != NULL) {
		unEmpleado = (Employee*) e1;
		otroEmpleado = (Employee*) e2;

		employee_getNombre(unEmpleado, nombreE1);
		employee_getNombre(otroEmpleado, nombreE2);

		retorno = strcmp(nombreE1, nombreE2);
	}

	return retorno;
}

int employee_CompareById(void* e1, void* e2) {
	int retorno;
	int idE1;
	int idE2;
	Employee* unEmpleado;
	Employee* otroEmpleado;
	unEmpleado = (Employee*) e1;
	otroEmpleado = (Employee*) e2;
	retorno = -2;

	if (e1 != NULL && e2 != NULL) {
		unEmpleado = (Employee*) e1;
		otroEmpleado = (Employee*) e2;

		employee_getId(unEmpleado, &idE1);
		employee_getId(otroEmpleado, &idE2);

		if (idE1 > idE2) {
			retorno = 1;
		} else {
			if (idE1 < idE2) {
				retorno = -1;
			}
		}
	}

	return retorno;
}
