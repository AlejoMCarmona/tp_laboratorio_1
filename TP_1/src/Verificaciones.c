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

int ValidarFactorial(float num){
	int retorno;
	int auxNum;
	retorno = 1,
	auxNum = num; //casteo implicito de flotante a entero.
	if (VerificarSigno(num) == -1 || auxNum - num != 0 || num > 12) {
		retorno = 0;
	}
	return retorno;
}
