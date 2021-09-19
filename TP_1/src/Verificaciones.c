#include "Verificaciones.h"

int VerificarSigno(int num) {
	int resultado;
	resultado = 0;
	if (num > 0) {
		resultado = 1;
	} else {
		if (num < 0) {
			resultado = -1;
		}
	}
	return resultado;
}

int VerificarFactorial(float num){
	int resultado;
	int auxNum;
	resultado = 1,
	auxNum = num; //casteo implicito de flotante a entero.
	if (VerificarSigno(num) == -1 || auxNum - num != 0 || num > 12) {
		resultado = 0;
	}
	return resultado;
}
