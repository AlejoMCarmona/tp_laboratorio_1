/*
============================================================================
Nombre: Alejo Martin Carmona.
Division: 1-E.
Trabajo practico n° 1.
Fecha de entrega limite: 25/09/21.
============================================================================
*/
#include <stdlib.h>
#include "Visual.h"
#include "Operaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	float x;
	int flagX;
	float y;
	int flagY;
	float suma;
	float resta;
	float division;
	int flagDiv;
	float multiplicacion;
	int factorialX;
	int flagFactX;
	int factorialY;
	int flagFactY;
	int flagOp;
	char opc;
	flagOp = 0;
	flagY = 0;
	flagX = 0;

	printf("////////////////////////////////\n//////////CALCULADORA//////////\n//////////////////////////////\n\n");
	do {
		opc = MostrarMenu(x, y, flagX, flagY);
		printf("----------------------------------------\n");
		switch (opc) {
			case '1':
				x = IngresarFlotante("Primer operando: ");
				flagX = 1;
			break;
			case '2':
				y = IngresarFlotante("Segundo operando: ");
				flagY = 1;
			break;
			case '3':
				RealizarOperaciones(x, y, flagX, flagY, &suma, &resta, &multiplicacion, &division, &flagDiv, &factorialX, &factorialY, &flagFactX, &flagFactY, &flagOp);
			break;
			case '4':
				MostrarResultados(x, y, &flagX, &flagY, suma, resta, multiplicacion, division, flagDiv, factorialX, factorialY, flagFactX, flagFactY, &flagOp);
			break;
			case '5':
				printf("¡Gracias por utilizar esta calculadora!\n");
			break;
			default:
				printf("Elija una opcion valida.\n");
			break;
		}
		printf("----------------------------------------\n");
	} while (opc != '5');

	return EXIT_SUCCESS;
}
