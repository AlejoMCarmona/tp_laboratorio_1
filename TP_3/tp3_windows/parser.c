#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char idStr[100];
	char nombreStr[128];
	char horasTrabajadasStr[100];
	char sueldoStr[100];
	int r;
	Employee* employee;
	retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
	    while(!feof(pFile)) {
	    	r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
	    	if (r != 4) {
	    		retorno = -1;
	    		break;
	    	}
			employee = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
			if (employee == NULL) {
				retorno = -1;
				break;
			}
			retorno = ll_add(pArrayListEmployee, employee);
			if (retorno != 0) {
				employee_delete(employee);
				retorno = -1;
				break;
			}
	    }
	}

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	int r;
	Employee* employee;
	retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL) {
	    while(!feof(pFile)) {
	    	employee = employee_new();
	    	if (employee == NULL) {
	    		retorno = -1;
	    		break;
	    	}
	    	r = fread(employee, sizeof(Employee), 1, pFile);
	    	if (r != 1) {
	    		if (feof(pFile)) {
	    			retorno = 0;
	    		} else {
		    		retorno = -1;
	    		}
	    		break;
	    	}
	    	retorno = ll_add(pArrayListEmployee, employee);
	    	if (retorno != 0) {
	    		employee_delete(employee);
	    		break;
	    	}
	    }
	}

    return retorno;
}

int parser_LastIDFromText() {
	int id;
	char idChar[10];
	id = -1;

	FILE *fIdMax;
	fIdMax = fopen("idMaximo.txt", "r");
	if (fIdMax != NULL) {
		strcpy(idChar, fgets(idChar, 10, fIdMax));
		if (idChar != NULL) {
			id = atoi(idChar);
		}
		fclose(fIdMax);
	}

	return id;

}
