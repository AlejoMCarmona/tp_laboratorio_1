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
	int retorno;
	retorno = 0;
	if (y != 0) {
		*div = x / y;
		retorno = 1;
	}
	return retorno;
}

int CalcularFactorial(float num, int* factorial) {
	int retorno;
	int auxFactorial;
	auxFactorial = 1;

	retorno = ValidarFactorial(num);
	if (retorno == 1) {
		while (num > 0) {
			auxFactorial *= num;
			num--;
		}
		*factorial = auxFactorial;
	}
	return retorno;
}
