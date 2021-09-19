#include "Visual.h"

int MostrarMenu(float x, float y, int flagX, int flagY) {
	int opc;

	if (flagX == 0) {
		printf("1-Ingresar 1er operando (A = x)\n");
	} else {
		printf("1-Ingresar 1er operando (A = %.2f)\n", x);
	}
	if (flagY == 0) {
		printf("2-Ingresar 2do operando (B = y)\n");
	} else {
		printf("2-Ingresar 2do operando (B = %.2f)\n", y);
	}
	printf("3-Calcular todas las operaciones\n");
	printf("4-Informar resultados\n");
	printf("5- Salir\n");
	printf("----------------------------------------\n");
	opc = IngresarCaracter("Elija una opcion: ");
	return opc;
}

void MostrarResultados(float x, float y, int* flagX, int* flagY, float suma, float resta, float multiplicacion, float division, int flagDiv, int factorialX, int factorialY, int flagFactX, int flagFactY, int* flagOp) {
	if (*flagOp) {
		printf("////////////////////RESULTADOS////////////////////\n");
		printf("El resultado de %.2f + %.2f es: %.2f\n", x, y, suma);
		printf("El resultado de %.2f - %.2f es: %.2f\n", x, y, resta);
		if (flagDiv) {
			printf("El resultado de %.2f / %.2f es: %.2f\n", x, y, division);
		} else {
			printf("No se puede realizar una division por cero.\n");
		}
		printf("El resultado de %.2f * %.2f es: %.2f\n", x, y, multiplicacion);
		if (flagFactX) {
			printf("El factorial de %.2f es: %d\n", x, factorialX);
		} else {
			if (x > 12) {
				printf("No se puede visualizar el factorial de un numero tan grande.\n");
			} else {
				printf("No se puede calcular el factorial de numeros negativos y/o decimales.\n");
			}
		}
		if (flagFactY) {
			printf("El factorial de %.2f es: %d\n", y, factorialY);
		} else {
			if (y > 12) {
				printf("No se puede visualizar el factorial de un numero tan grande.\n");
			} else {
				printf("No se puede calcular el factorial de numeros negativos y/o decimales.\n");
			}
		}
		*flagX = 0;
		*flagY = 0;
		*flagOp = 0;
	} else {
		printf("¡ERROR! Primero debes ingresar los dos operandos y posteriormente realizar los calculos para poder mostrar los resultados.\n");
	}
}
