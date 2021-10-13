/*
 ============================================================================
 Name        : TP_2.c
 Author      : Alejo Martin Carmona.
 Version     :
 Copyright   : Your copyright notice
 Description : Fecha de entrega limite: 16/10/21
 ============================================================================
 */

#include "Informes.h"
#define T 1000

int main(void) {
	setbuf(stdout, NULL);
	int contadorID;
	int opcion;
	int opcionSub;
	int retornoFuncion;																																			//6       ac               dc          1600.000000        2
	Employee listaEmpleados[T] = {{1, "aa", "bb", 1600, 2, FULL},
								  {2, "cc", "dd", 1200, 2, FULL},
								  {3, "aa", "cc", 1300, 5, FULL},
								  {4, "kk", "aa", 1000, 5, FULL},
								  {5, "cc", "bb", 1600, 1, FULL},
								  {6, "ac", "dc", 1600, 2, FULL},
								  {7, "dd", "ee", 2100, 2, FULL},
								  {8, "kk", "jj", 1200, 2, FULL}};
	//InitEmployees(listaEmpleados, T);
	//contadorID = 0;
	contadorID = 8;
	do {
		retornoFuncion = MostrarMenu(&opcion);
		printf("------------------------------\n");
		if (retornoFuncion == 1) {
			switch (opcion) {
				case 1: //alta
					HacerAlta(listaEmpleados, T, &contadorID);
				break;
				case 2: //baja
					if (ContarEmpleados(listaEmpleados, T) > 0) {
						HacerModificacion(listaEmpleados, T);
					} else {
						printf("Debe cargar al menos un empleado primero.\n");
					}
				break;
				case 3: //modificacion
					if (ContarEmpleados(listaEmpleados, T) > 0) {
						HacerBaja(listaEmpleados, T);
					} else {
						printf("Debe cargar al menos un empleado primero.\n");
					}
				break;
				case 4: // informar
					if (ContarEmpleados(listaEmpleados, T) > 0) {
						retornoFuncion = MostrarSubmenu(&opcionSub);
						if (retornoFuncion == 1) {
							if (opcionSub == 1) {
								OrdenarEmpleadosPorApellidoSector(listaEmpleados, T);
							} else {
								if (opcionSub == 2) {
									MostrarDatosSalariales(listaEmpleados, T);
								}
							}
						} else {
							printf("Ingrese solo una de las opciones disponibles.\n");
						}
					} else {
						printf("Debe cargar al menos un empleado primero.\n");
					}
				break;
				case 0:
						printf("¡¡Gracias por utilizar el programa!!\n");
				break;
				default:
					printf("Ingrese solo una de las opciones disponibles.\n");
				break;
			}
		} else {
			printf("¡¡ERROR!! Ingrese solo numeros enteros.\n");
		}
		printf("------------------------------\n");
		//
	} while (opcion != 0);

	return EXIT_SUCCESS;
}
