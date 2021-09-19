#include "Input.h"

float IngresarFlotante(char mensaje[]) {
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);
	return numeroIngresado;
}

int IngresarEntero(char mensaje[]) {
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);
	return numeroIngresado;
}
