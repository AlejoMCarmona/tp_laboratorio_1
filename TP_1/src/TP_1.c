/*
============================================================================
Nombre: Alejo Martin Carmona.
Division: 1-E.
Trabajo practico n° 1.
Fecha de entrega limite: 25/09/21.
============================================================================
*/
#include <stdlib.h>
#include "Input.h"
#include "Operaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int opc;
	float x;
	int flagX;
	float y;
	int flagY;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	int factorialX;
	int factorialY;
	int flagDiv;
	int flagFactorialX;
	int flagFactorialY;
	int flagCalculos;
	flagX = 0;
	flagY = 0;
	flagCalculos = 0;

	printf("//////////////////////////////////////////\n///////////////CALCULADORA///////////////\n////////////////////////////////////////\n");
	printf("----------------------------------------\n");
	do {
		printf("//////////////////MENU/////////////////\n");
		if (flagX == 0) {
			printf("1. Ingresar 1er operando (A = x)\n");
		} else {
			printf("1. Ingresar 1er operando (A = %.2f)\n", x);
		}
		if (flagY == 0) {
			printf("2. Ingresar 2do operando (B = y)\n");
		} else {
			printf("2. Ingresar 2do operando (B = %.2f)\n", y);
		}
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n\n");

		opc = IngresarEntero("Elija una opcion: ");
		printf("----------------------------------------\n");

		switch (opc) {
			case 1:
				x = IngresarFlotante("Ingrese el primer operando: ");
				flagX = 1;
			break;
			case 2:
				y = IngresarFlotante("Ingrese el segundo operando: ");
				flagY = 1;
			break;
			case 3:
				if (flagX && flagY) {
					suma = Sumar(x, y);
					resta = Restar(x, y);
					flagDiv = Dividir(x, y, &division);
					multiplicacion = Multiplicar(x, y);
					flagFactorialX = CalcularFactorial(x, &factorialX);
					flagFactorialY = CalcularFactorial(y, &factorialY);
					flagCalculos = 1;
					printf("¡Calculos realizados con exito!\n");
				} else {
					printf("¡ERROR! Debe ingresar los dos operandos para poder realizar los calculos.\n");
				}
			break;
			case 4:
				if (flagCalculos) {
					printf("////////////////////RESULTADOS////////////////////\n");
					printf("El resultado de %.2f + %.2f es: %.2f\n", x, y, suma);
					printf("El resultado de %.2f - %.2f es: %.2f\n", x, y, resta);
					if (flagDiv) {
						printf("El resultado de %.2f / %.2f es: %.2f\n", x, y, division);
					} else {
						printf("No es posible dividir por cero.\n");
					}
					printf("El resultado de %.2f * %.2f es: %.2f\n", x, y, multiplicacion);
					if (flagFactorialX) {
						printf("El factorial de %.2f es: %d\n", x, factorialX);
					} else {
						printf("¡ERROR! No es posible en esta calculadora hallar el factorial de numeros muy grandes, ni de numeros decimales, ni tampoco de negativos.\n");
					}
					if (flagFactorialY) {
						printf("El factorial de %.2f es: %d\n", y, factorialY);
					} else {
						printf("¡ERROR! No es posible en esta calculadora hallar el factorial de numeros muy grandes, ni de numeros decimales, ni tampoco de negativos.\n");
					}
					flagX = 0;
					flagY = 0;
					flagCalculos = 0;
				} else {
					printf("ERROR. Para mostrar los resultados primero se deben ingresar los dos operandos, y posteriormente realizar los calculos.\n");
				}
			break;
			case 5:
				printf("¡Gracias por utilizar esta calculadora!\n");
			break;
			default:
				printf("Elija una opcion valida.\n");
			break;
		}
		printf("----------------------------------------\n");
	} while (opc != 5);

	return EXIT_SUCCESS;
}
