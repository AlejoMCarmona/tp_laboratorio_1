#include "Operaciones.h"

float Sumar(float x, float y) {
	float resultado;
	resultado = x + y;
	return resultado;
}

float Restar(float x, float y) {
	float resultado;
	resultado = x - y;
	return resultado;
}

float Multiplicar(float x, float y) {
	float resultado;
	resultado = x * y;
	return resultado;
}

int Dividir(float x, float y, float* div) {
	int resultado;
	resultado = 0;
	if (y != 0) {
		*div = x / y;
		resultado = 1;
	}
	return resultado;
}

int CalcularFactorial(float num, int* factorial) {
	int flagFactorial;
	int auxFactorial;
	auxFactorial = 1;

	flagFactorial = VerificarFactorial(num);
	if (flagFactorial == 1) {
		while (num > 0) {
			auxFactorial *= num;
			num--;
		}
		*factorial = auxFactorial;
	}
	return flagFactorial;
}

void RealizarOperaciones(float x, float y, int flagX, int flagY, float* suma, float* resta, float* multiplicacion, float* division, int* flagDiv, int* factorialX, int* factorialY, int* flagFactX, int* flagFactY, int* flagOp) {
	if (flagX && flagY) {
		*suma = Sumar(x, y);
		*resta = Restar(x, y);
		*flagDiv = Dividir(x, y, division);
		*multiplicacion = Multiplicar(x, y);
		*flagFactX = CalcularFactorial(x, factorialX);
		*flagFactY = CalcularFactorial(y, factorialY);
		*flagOp = 1;
		printf("¡Calculos realizados con exito!\n");
	} else {
		printf("¡ERROR! Primero debes ingresar los dos operandos para poder realizar las operaciones.\n");
	}
}
