#include "ArrayEmployees.h"

int InitEmployees (Employee list[], int len) {
	int retorno;
	retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

int BuscarPrimerPosicionLibre(Employee list[], int len){
	int indice;
	indice = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == EMPTY) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int CrearEmpleado(char name[], char lastName[], float* salary, int* sector) {
	Employee employeeAux;
	int retorno;
	retorno = 0;
	if (name != NULL && lastName != NULL && salary != NULL && sector != NULL) {
		retorno = IngresarCadenaSoloLetrasConIntentos(employeeAux.name, 51, "Ingrese el nombre del empleado ", "ERROR. Reingrese el nombre del empleado ", 5);
		if (retorno == 1) {
			strlwr(employeeAux.name);
			retorno = IngresarCadenaSoloLetrasConIntentos(employeeAux.lastName, 51, "Ingrese el apellido del empleado ", "ERROR. Reingrese el apellido del empleado ", 5);
			if (retorno == 1) {
				strlwr(employeeAux.lastName);
				retorno = IngresarFlotanteEntreRangosConIntentos(&employeeAux.salary, "Ingrese el salario del empleado ", "ERROR. Reingrese el salario del empleado ", 0, FLT_MAX, 5);
				if (retorno == 1) {
					retorno = IngresarEnteroEntreRangosConIntentos(&employeeAux.sector, "Ingrese el sector del empleado (1-10) ", "ERROR. Reingrese el sector del empleado (1-10) ", 1, 10, 5);
					if (retorno == 1) {
						strncpy(name, employeeAux.name, 51);
						strncpy(lastName, employeeAux.lastName, 51);
						*salary = employeeAux.salary;
						*sector = employeeAux.sector;
					}
				}
			}
		}
	}
	return retorno;
}

int addEmployes(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector) {
	int retorno;
	int indice;
	retorno = -1;

	if (list != NULL && name != NULL && lastName != NULL && len > 0) {
		indice = BuscarPrimerPosicionLibre(list, len);
		if (indice != -1) {
			retorno = CargarUnEmpleado(list, len, indice, id, name, lastName, salary, sector);
		}
	}
	return retorno;
}

int CargarUnEmpleado(Employee list[], int len, int indice, int id, char name[], char lastName[], float salary, int sector) {
	int retorno;
	retorno = -1;
	if (list != NULL && name != NULL && lastName != NULL && len > 0) {
		strncpy(list[indice].name, name, 51);
		strncpy(list[indice].lastName, lastName, 51);
		list[indice].salary = salary;
		list[indice].sector = sector;
		list[indice].isEmpty = FULL;
		list[indice].id = id + 1;
		retorno = 0;
	}
	return retorno;
}

int PrintEmployees(Employee list[], int len) {
	int flagImpresion;
	flagImpresion = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL) {
				if (flagImpresion == -1) {
					printf("ID\tNombre\t\tApellido\tSalario\t\tSector\n");
				}
				MostrarEmpleado(list[i]);
				flagImpresion = 1;
			}
		}
	}
	return flagImpresion;
}

void MostrarEmpleado(Employee employee) {
	printf("%d %8s %16s %20f %8d\n", employee.id,employee.name,
			employee.lastName, employee.salary, employee.sector);
}

int FindEmployeeById(Employee list[], int len, int id) {
	int indice;
	indice = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL && list[i].id == id) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int RemoveEmployee(Employee list[], int len, int id) {
	int retorno;
	int index;
	retorno = -1;
	if (list != NULL && len > 0) {
		index = FindEmployeeById(list, len, id);
		if (index != -1){
			list[index].isEmpty = EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

int ModificarEmpleado(Employee list[], int len, int indice, int opcion) {
	int retorno;
	char auxiliarCadena[51];
	int auxiliarEntero;
	float auxiliarFlotante;
	retorno = 0;

	if (list != NULL) {
		switch(opcion) {
			case 1:
				retorno = IngresarCadenaSoloLetrasConIntentos(auxiliarCadena, 51, "Ingrese el nombre del empleado ", "ERROR. Reingrese el nombre del empleado ", 5);
				if (retorno == 1) {
					strncpy(list[indice].name, auxiliarCadena, 51);
				}
			break;
			case 2:
				retorno = IngresarCadenaSoloLetrasConIntentos(auxiliarCadena, 51, "Ingrese el apellido del empleado ", "ERROR. Reingrese el apellido del empleado ", 5);
				if (retorno == 1) {
					strncpy(list[indice].lastName, auxiliarCadena, 51);
				}
			break;
			case 3:
				retorno = IngresarFlotanteEntreRangosConIntentos(&auxiliarFlotante, "Ingrese el salario del empleado ", "ERROR. Reingrese el salario del empleado ", 0, FLT_MAX, 5);
				if (retorno == 1) {
					list[indice].salary = auxiliarFlotante;
				}
			break;
			case 4:
				retorno = IngresarEnteroEntreRangosConIntentos(&auxiliarEntero, "Ingrese el sector del empleado (1-10) ", "ERROR. Reingrese el sector del empleado (1-10) ", 1, 10, 5);
				if (retorno == 1) {
					list[indice].sector = auxiliarEntero;
				}
			break;
		}
	}
	return retorno;
}

int ContarEmpleados(Employee list[], int len) {
	int contadorEmpleados;
	contadorEmpleados = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL) {
				contadorEmpleados++;
			}
		}
	}
	return contadorEmpleados;
}

int SortEmployees(Employee list[], int len, int order) {
	int retornoOrdenamiento;
	retornoOrdenamiento = -1;
	if (list != NULL && len > 0) {
		if (order == 1) {
			retornoOrdenamiento = SortEmployeesUp(list, len);
		} else {
			if (order == 0) {
				retornoOrdenamiento = SortEmployeesDown(list, len);
			}
		}
	}
	return retornoOrdenamiento;
}

int SortEmployeesUp(Employee list[], int len) {
	int retorno;
	Employee employeeAux;
	retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (strcmp(list[i].lastName, list[j].lastName) > 0) {
					employeeAux = list[i];
					list[i] = list[j];
					list[j] = employeeAux;
				}
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {
					if (list[i].sector > list[j].sector) {
						employeeAux = list[i];
						list[i] = list[j];
						list[j] = employeeAux;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int SortEmployeesDown(Employee list[], int len) {
	int retorno;
	Employee employeeAux;
	retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (strcmp(list[i].lastName, list[j].lastName) < 0) {
					employeeAux = list[i];
					list[i] = list[j];
					list[j] = employeeAux;
				}
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {
					if (list[i].sector < list[j].sector) {
						employeeAux = list[i];
						list[i] = list[j];
						list[j] = employeeAux;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int CalcularSalariosEmpleados(Employee list[], int len, float* salarioAcumulado, float* salarioPromedio) {
	int retorno;
	int cantidadEmpleados;
	retorno = 0;
	if (list != NULL && len > 0 && salarioAcumulado != NULL && salarioPromedio != NULL) {
		cantidadEmpleados = ContarEmpleados(list, len);
		if (cantidadEmpleados > 0) {
			*salarioAcumulado = AcumularSalario(list, len);
			*salarioPromedio = *salarioAcumulado / cantidadEmpleados;
			retorno = 1;
		}
	}
	return retorno;
}

float AcumularSalario(Employee list[], int len) {
	int salarioAcumulado;
	salarioAcumulado = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL) {
				salarioAcumulado += list[i].salary;
			}
		}
	}
	return salarioAcumulado;
}

int ContarCantEmpleadosQueSuperanSalarioPromedio(Employee list[], int len, float salarioPromedio) {
	int cantidad;
	cantidad = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL && list[i].salary > salarioPromedio) {
				cantidad++;
			}
		}
	}
	return cantidad;
}
