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
#define TRUE 1
#define FALSE 0

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
	flagX = FALSE;
	flagY = FALSE;
	flagCalculos = FALSE;

	printf("|||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||CALCULADORA|||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||||||||||||||||||1-E|||||||||||||||||||\n|||||||Alejo Martin Carmona - 2021|||||||\n|||||||||||||||||||||||||||||||||||||||||\n");
	printf("-----------------------------------------\n");
	do {
		printf("||||||||||||||||||MENU|||||||||||||||||||\n");
		if (flagX == FALSE) {
			printf("1. Ingresar 1er operando (A=x)\n");
		} else {
			printf("1. Ingresar 1er operando (A=%.5f)\n", x);
		}
		if (flagY == FALSE) {
			printf("2. Ingresar 2do operando (B=y)\n");
		} else {
			printf("2. Ingresar 2do operando (B=%.5f)\n", y);
		}
		printf("3. Calcular todas las operaciones\n"
				" a) Calcular la suma (A+B)\n"
				" b) Calcular la resta (A-B)\n"
				" c) Calcular la division (A/B)\n"
				" d) Calcular la multiplicacion (A*B)\n"
				" e) Calcular el factorial de ambos numeros (A! y B!).\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n\n");

		opc = IngresarFlotante("Elija una opcion: ");
		printf("----------------------------------------\n");

		switch (opc) {
			case 1:
				x = IngresarFlotante("Ingrese el primer operando: ");
				flagX = TRUE;
				flagCalculos = FALSE;
			break;
			case 2:
				y = IngresarFlotante("Ingrese el segundo operando: ");
				flagY = TRUE;
				flagCalculos = FALSE;
			break;
			case 3:
				if (flagX == TRUE && flagY == TRUE) {
					suma = Sumar(x, y);
					resta = Restar(x, y);
					flagDiv = Dividir(x, y, &division);
					multiplicacion = Multiplicar(x, y);
					flagFactorialX = CalcularFactorial(x, &factorialX);
					flagFactorialY = CalcularFactorial(y, &factorialY);
					flagCalculos = TRUE;
					printf("¡Calculos realizados con exito!\n");
				} else {
					printf("¡ERROR! Debe ingresar los dos operandos para poder realizar los calculos.\n");
				}
			break;
			case 4:
				if (flagCalculos == TRUE) {
					printf("////////////////////RESULTADOS////////////////////\n");
					printf("El resultado de %.5f + %.5f es: %.5f\n", x, y, suma);
					printf("El resultado de %.5f - %.5f es: %.5f\n", x, y, resta);
					if (flagDiv == TRUE) {
						printf("El resultado de %.5f / %.5f es: %.5f\n", x, y, division);
					} else {
						printf("No es posible dividir por cero.\n");
					}
					printf("El resultado de %.5f * %.5f es: %.5f\n", x, y, multiplicacion);
					if (flagFactorialX == TRUE) {
						printf("El factorial de %.5f es: %d\n", x, factorialX);
					} else {
						printf("¡ERROR! No es posible en esta calculadora hallar el factorial de numeros muy grandes, ni de numeros decimales, ni tampoco de negativos.\n");
					}
					if (flagFactorialY == TRUE) {
						printf("El factorial de %.5f es: %d\n", y, factorialY);
					} else {
						printf("¡ERROR! No es posible en esta calculadora hallar el factorial de numeros muy grandes, ni de numeros decimales, ni tampoco de negativos.\n");
					}
					flagX = FALSE;
					flagY = FALSE;
					flagCalculos = FALSE;
				} else {
					printf("¡ERROR! Para mostrar los resultados primero se deben ingresar los dos operandos, y posteriormente realizar los calculos.\n");
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
