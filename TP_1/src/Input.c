#include "Input.h"

float IngresarFlotante(char mensaje[]) {
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);
	return numeroIngresado;
}

char IngresarCaracter(char mensaje[]) {
	char caracter;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &caracter);
	return caracter;
}
