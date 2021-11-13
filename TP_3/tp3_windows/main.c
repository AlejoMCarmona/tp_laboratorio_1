#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    int option;
    int retorno;

    LinkedList* listaEmpleados = ll_newLinkedList();

	printf("||||||||||||||||||||||||||||||||||||||||\n"
			"||||||||||NÓMINA DE EMPLEADOS|||||||||||\n"
			"||||||||||||||||||||||||||||||||||||||||\n"
			"|||||||Alejo Martin Carmona / 1-E|||||||\n"
			"||||||||||||||||||||||||||||||||||||||||\n\n");

    do{
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    		   "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
    		   "3. Alta de empleado\n"
    		   "4. Modificar datos de empleado\n"
    		   "5. Baja de empleado\n"
    		   "6. Listar empleados\n"
    		   "7. Ordenar empleados\n"
    		   "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    		   "9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n"
    		   "10. Salir\n\n");

    	retorno = IngresarEntero(&option, "Ingrese una opción: ");
        printf("--------------------------------------------------\n");

        if (retorno == 1) {
            switch(option) {
                case 1:
                    retorno = controller_loadFromText("data.csv", listaEmpleados);
                    if (retorno == 0) {
                    	printf("Archivo de texto cargado con éxito.\n");
                    } else {
                    	printf("¡ERROR!\n");
                    }
                    break;
                case 2:
                	retorno = controller_loadFromBinary("data.bin", listaEmpleados);
                    if (retorno == 0) {
                    	printf("Archivo binario cargado con éxito.\n");
                    } else {
                    	printf("¡ERROR!\n");
                    }
                	break;
                case 3:
                	retorno = controller_addEmployee(listaEmpleados);
                    if (retorno == 0) {
                    	printf("Éxito al agregar un nuevo empleado en la lista.\n");
                    } else {
                    	printf("¡ERROR!\n");
                    }
                	break;
                case 4:
                	retorno = controller_editEmployee(listaEmpleados);
                    if (retorno == 0) {
                    	printf("Éxito al editar el empleado.\n");
                    } else {
                    	if (retorno == -1) {
                        	printf("¡ERROR!\n");
                    	} else {
                    		printf("Operacion cancelada.\n");
                    	}
                    }
                	break;
                case 5:
                	retorno = controller_removeEmployee(listaEmpleados);
                    if (retorno == 0) {
                    	printf("Éxito al remover empleado.\n");
                    } else {
                    	if (retorno == -1) {
                        	printf("¡ERROR!\n");
                    	} else {
                    		printf("Operacion cancelada.\n");
                    	}
                    }
                	break;
                case 6:
                	retorno = controller_ListEmployee(listaEmpleados);
                    if (retorno != 0) {
                    	printf("¡ERROR!\n");
                    }
                	break;
                case 7:
                	retorno = controller_sortEmployee(listaEmpleados);
                    if (retorno == 0) {
                    	printf("Éxito en el ordenamiento.\n");
                    } else {
                    	printf("¡ERROR!\n");
                    }
                	break;
                case 8:
                	retorno = controller_saveAsText("data.csv", listaEmpleados);
                    if (retorno == 0) {
                    	printf("Lista guardada con éxito en archivo de texto.\n");
                    } else {
                    	printf("¡ERROR!\n");
                    }
                	break;
                case 9:
                	retorno = controller_saveAsBinary("data.bin", listaEmpleados);
                    if (retorno == 0) {
                    	printf("Lista guardada con éxito en archivo binario.\n");
                    } else {
                    	printf("¡ERROR!\n");
                    }
                	break;
                case 10:
                	printf("¡Gracias por utilizar el programa!\n");
                	ll_deleteLinkedList(listaEmpleados);
                	break;
                default:
                	printf("Elija una opcion válida.\n");
                	break;
            }
        } else {
        	printf("ERROR. Solo números enteros.\n");
        }

        printf("--------------------------------------------------\n");
    }while(option != 10);

    return 0;
}

