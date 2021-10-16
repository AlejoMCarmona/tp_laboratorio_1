/*
 ============================================================================
 Name        : TP_2.c
 Author      : Alejo Martin Carmona.
 Version     : V1
 Copyright   : Your copyright notice
 Description : Fecha de entrega limite: 16/10/21
 ============================================================================
 */

#include "Menu.h"
#define T 1000

int main(void) {
	setbuf(stdout, NULL);
	int contadorID;
	int opcion;
	int opcionSub;
	int retornoFuncion;
	Employee listaEmpleados[T];
	InitEmployees(listaEmpleados, T);
	contadorID = 0;

	do {
		retornoFuncion = MostrarMenu(&opcion);
		printf("------------------------------\n");
		if (retornoFuncion == 1) {
			switch (opcion) {
				case 1:
					retornoFuncion = HacerAlta(listaEmpleados, T, &contadorID);
					if (retornoFuncion == 1) {
						printf("Alta realizada con éxito.\n");
					} else {
						printf("¡¡ERROR!! No se pudo realizar el alta.\n");
					}
				break;
				case 2:
					retornoFuncion = HacerModificacion(listaEmpleados, T);
					if (retornoFuncion == 1) {
						printf("Modificacion realizada con éxito.\n");
					} else {
						if (retornoFuncion == -1) {
							printf("¡¡ERROR!! No se pudo encontrar el empleado en la lista.\n");
						} else {
							if (retornoFuncion == -2) {
								printf("¡¡ERROR!! No hay empleados en la lista.\n");
							} else {
								printf("¡¡ERROR!! No se pudo realizar la modificación.\n");
							}
						}
					}
				break;
				case 3:
					retornoFuncion = HacerBaja(listaEmpleados, T);
					if (retornoFuncion == 1) {
						printf("Baja realizada con éxito.\n");
					} else {
						if (retornoFuncion == -2) {
							printf("¡¡ERROR!! No hay empleados en la lista.\n");
						} else {
							if (retornoFuncion == -1) {
								printf("¡¡ERROR!! No se pudo encontrar el empleado en la lista.\n");
							} else {
								printf("¡¡ERROR!! No se pudo realizar la baja.\n");
							}
						}
					}
				break;
				case 4:
					retornoFuncion = MostrarSubmenu(listaEmpleados, T, &opcionSub);
					if (retornoFuncion == 1) {
						if (opcionSub == 1) {
							retornoFuncion = OrdenarEmpleadosPorApellidoSector(listaEmpleados, T);
							if (retornoFuncion != 1) {
								printf("¡¡ERROR!! El ordenamiento no pudo realizarse con éxito.\n");
							}
						} else {
							if (opcionSub == 2) {
								retornoFuncion = ImprimirDatosSalariales(listaEmpleados, T);
								if (retornoFuncion != 1) {
									printf("¡¡ERROR!! No se pudieron calcular los datos salariales de los empleados.\n");
								}
							} else {
								printf("ERROR. Ingrese una de las opciones disponibles.\n");
							}
						}
					} else {
						if (retornoFuncion == -2) {
							printf("¡¡ERROR!! No hay empleados en la lista.\n");
						} else {
							printf("¡¡ERROR!! Hubo un error en la selección de la opción.\n");
						}

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
	} while (opcion != 0);

	return EXIT_SUCCESS;
}
