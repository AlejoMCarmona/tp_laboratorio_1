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

int BuscarPrimeraPosicionLibre(Employee list[], int len){
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

int HacerAlta(Employee list[], int len, int* contadorID) {
	int retorno;
	int id;
	Employee nuevoEmpleado;
	id = *contadorID;
	retorno = 0;

	if (list != NULL && len > 0 && contadorID != NULL) {
		retorno = CrearEmpleado(&nuevoEmpleado, id);
		printf("------------------------------\n");
		if (retorno == 1) {
			retorno = addEmployes(list, len, nuevoEmpleado.id, nuevoEmpleado.name, nuevoEmpleado.lastName, nuevoEmpleado.salary, nuevoEmpleado.sector);
			if (retorno == 0) {
				*contadorID = *contadorID + 1;
				retorno = 1;
			}
		}
	}
	return retorno;
}

int CrearEmpleado(Employee* employee, int id) {
	int retorno;
	retorno = 0;
	if (employee != NULL) {
		retorno = IngresarCadenaSoloLetrasConIntentos(employee->name, 51, "Ingrese el nombre del empleado: ", "ERROR. Reingrese el nombre del empleado: ", 5);
		if (retorno == 1) {
			retorno = IngresarCadenaSoloLetrasConIntentos(employee->lastName, 51, "Ingrese el apellido del empleado: ", "ERROR. Reingrese el apellido del empleado: ", 5);
			if (retorno == 1) {
				retorno = IngresarFlotanteEntreRangosConIntentos(&(employee->salary), "Ingrese el salario del empleado: ", "ERROR. Reingrese el salario del empleado: ", 1, FLT_MAX, 5);
				if (retorno == 1) {
					retorno = IngresarEnteroEntreRangosConIntentos(&(employee->sector), "Ingrese el sector del empleado (1-10): ", "ERROR. Reingrese el sector del empleado (1-10): ", 1, 10, 5);
					if (retorno == 1) {
						employee->id = id + 1;
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
		indice = BuscarPrimeraPosicionLibre(list, len);
		if (indice != -1) {
			strncpy(list[indice].name, name, 51);
			strncpy(list[indice].lastName, lastName, 51);
			list[indice].salary = salary;
			list[indice].sector = sector;
			list[indice].isEmpty = FULL;
			list[indice].id = id;
			retorno = 0;
		}
	}

	return retorno;
}

int HacerModificacion(Employee list[], int len) {
	int retorno;
	int indice;
	int id;
	int opcion;
	retorno = 0;

	if (list != NULL && len > 0) {
		ContarEmpleados(list, len, &retorno);
		if (retorno > 0) {
			PrintEmployees(list, len);
			retorno = IngresarEnteroConIntentos(&id, "Ingrese el ID del empleado a modificar ", "ERROR. Reingrese el ID del empleado a modificar ", 5);
			if (retorno == 1) {
				indice = FindEmployeeById(list, len, id);
				if (indice != -1) {
					MostrarCamposEmpleadoParaModificar(list[indice]);
					retorno = IngresarEnteroEntreRangosConIntentos(&opcion, "Elija una opción ", "¡¡ERROR!! Elija una opcion válida: ", 1, 4, 5);
					if (retorno == 1) {
						retorno = ModificarEmpleado(list, len, indice, opcion);
					}
				} else {
					retorno = -1;
				}
			}
		} else {
			retorno = -2;
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

	if (list != NULL && len > 0 && indice >= 0 && indice < len) {
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
				retorno = IngresarFlotanteEntreRangosConIntentos(&auxiliarFlotante, "Ingrese el salario del empleado ", "ERROR. Reingrese el salario del empleado ", 1, FLT_MAX, 5);
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

void MostrarCamposEmpleadoParaModificar(Employee employee) {
	printf("ID\tNombre\t\tApellido\tSalario\t\tSector\n");
	MostrarEmpleado(employee);
	printf("\nEmpleado encontrado ¿Qué desea modificar?\n"
		   "1. Nombre\n"
		   "2. Apellido\n"
		   "3. Salario\n"
		   "4. Sector\n\n");
}


int HacerBaja(Employee list[], int len) {
	int retorno;
	int id;
	retorno = 0;

	if (list != NULL && len > 0) {
		ContarEmpleados(list, len, &retorno);
		if (retorno > 0) {
			PrintEmployees(list, len);
			retorno = IngresarEnteroConIntentos(&id, "Ingrese el ID del empleado a eliminar ", "ERROR. Reingrese el ID del empleado a eliminar ", 5);
			if (retorno == 1) {
				retorno = RemoveEmployee(list, len, id);
				if (retorno == 0) {
					retorno = 1;
				}
			}
		} else {
			retorno = -2;
		}
	}
	return retorno;
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

int ContarEmpleados(Employee list[], int len, int* cantidadEmpleados) {
	int contadorEmpleados;
	int retorno;
	contadorEmpleados = 0;
	retorno = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL) {
				contadorEmpleados++;
			}
		}
		*cantidadEmpleados = contadorEmpleados;
		retorno = 1;
	}
	return retorno;
}

int OrdenarEmpleadosPorApellidoSector(Employee list[], int len) {
	int retorno;
	int opcion;
	retorno = -1;

	if (list != NULL && len > 0) {
		printf("Elija el tipo de ordenamiento: \n0. Descendente\n1. Ascendente.\n\n");
		retorno = IngresarEnteroEntreRangosConIntentos(&opcion, "Elija la opcion: ", "ERROR. Elija una opción válida: ", 0, 1, 5);
		if (retorno == 1) {
			retorno = SortEmployees(list, len, opcion);
			if (retorno == 0) {
				printf("Ordenamiento realizado con éxito.\n");
				PrintEmployees(list, len);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int SortEmployees(Employee list[], int len, int order) {
	int retorno;
	retorno = -1;
	if (list != NULL && len > 0) {
		if (order == 1) {
			retorno = SortEmployeesAscendingOrder(list, len);
		} else {
			if (order == 0) {
				retorno = SortEmployeesDescendingOrder(list, len);
			}
		}
	}
	return retorno;
}

int SortEmployeesAscendingOrder(Employee list[], int len) {
	int retorno;
	Employee employeeAux;
	retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (stricmp(list[i].lastName, list[j].lastName) > 0) {
					employeeAux = list[i];
					list[i] = list[j];
					list[j] = employeeAux;
				}
				if (stricmp(list[i].lastName, list[j].lastName) == 0) {
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

int SortEmployeesDescendingOrder(Employee list[], int len) {
	int retorno;
	Employee employeeAux;
	retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (stricmp(list[i].lastName, list[j].lastName) < 0) {
					employeeAux = list[i];
					list[i] = list[j];
					list[j] = employeeAux;
				}
				if (stricmp(list[i].lastName, list[j].lastName) == 0) {
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
		ContarEmpleados(list, len, &cantidadEmpleados);
		if (cantidadEmpleados > 0) {
			AcumularSalario(list, len, salarioAcumulado);
			*salarioPromedio = *salarioAcumulado / cantidadEmpleados;
			retorno = 1;
		}
	}
	return retorno;
}

int AcumularSalario(Employee list[], int len, float* salarioAcumulado) {
	int retorno;
	float salarioAux;
	retorno = 0;
	salarioAux = 0;
	if (list != NULL && len > 0 && salarioAcumulado != NULL) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL) {
				salarioAux += list[i].salary;
			}
		}
		*salarioAcumulado = salarioAux;
		retorno = 1;
	}
	return retorno;
}

int ContarCantEmpleadosQueSuperanSalarioPromedio(Employee list[], int len, float salarioPromedio, int* cantidadEmpleados) {
	int cantidad;
	int retorno;
	cantidad = 0;
	retorno = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL && list[i].salary > salarioPromedio) {
				cantidad++;
			}
		}
		*cantidadEmpleados = cantidad;
		retorno = 1;
	}
	return retorno;
}


int ImprimirDatosSalariales(Employee list[], int len) {
	int retorno;
	int cantEmpleadosSuperanSalarioPromedio;
	float salarioAcumulado;
	float salarioPromedio;
	retorno = 0;

	if (list != NULL && len > 0) {
		retorno = CalcularSalariosEmpleados(list, len, &salarioAcumulado, &salarioPromedio);
		if (retorno == 1) {
			ContarCantEmpleadosQueSuperanSalarioPromedio(list, len, salarioPromedio, &cantEmpleadosSuperanSalarioPromedio);
			printf("Total de salarios actual: %f\nPromedio de los salarios: %f\nCantidad de empleados que superan el salario promedio: %d\n\n",
					salarioAcumulado, salarioPromedio, cantEmpleadosSuperanSalarioPromedio);
		}
	}

	return retorno;
}
