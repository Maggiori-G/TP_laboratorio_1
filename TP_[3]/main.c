//Alumno: Maggiori, Gianni
//Division: 1C
//Turno Mañana
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
#define ARCHIVO_BIN "data.bin"
#define ARCHIVO_TXT "data.csv"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).*
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado*
     4. Modificar datos de empleado*
     5. Baja de empleado
     6. Listar empleados*
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int controlador;
    LinkedList* listaEmpleados=ll_newLinkedList();
    do{
    	ImprimirOpciones();
    	option=PedirOpcion("\nSeleccione una opcion: ", 1, 10);
        switch(option)
        {
            case 1:
            	if(controller_loadFromText(ARCHIVO_TXT, listaEmpleados)){
            		printf("Archivo cargado con exito...");
            	}
            	else{
            		printf("No se pudo cargar el archivo...");
            	}
            break;
            case 2:
            	if(controller_loadFromBinary(ARCHIVO_BIN, listaEmpleados)){
            		printf("Archivo cargado con exito...");
            	}
            	else{
            		printf("No se pudo cargar el archivo...");
            	}
            break;
            case 3:
            	controlador=controller_addEmployee(listaEmpleados);
            	if(controlador==1){
            		printf("Empleado agregado con exito...");
            	}
            	else{
            		printf("No se puede añadir un empleado...");
            	}
            break;
            case 4:
            	controlador=controller_editEmployee(listaEmpleados);
            	if(controlador==1){
					printf("Empleado modificado con exito...");
				}
				else{
					printf("No logro modificar un empleado...");
				}
            break;
            case 5:
            	controlador=controller_removeEmployee(listaEmpleados);
            	if(controlador==1){
            		printf("Empleado eliminado con exito...");
            	}
            	else{
            		printf("No se ha logrado eliminar al empleado...");
            	}
            break;
            case 6:
            	if(listaEmpleados!=NULL){
            		controller_ListEmployee(listaEmpleados);
            	}
            	else{
            		printf("No se logro imprimir, lista de empelados no existente...");
            	}
            break;
            case 7:
            	if(listaEmpleados!=NULL){
            		controller_sortEmployee(listaEmpleados);
            	}
            	else{
            		printf("No es posible ordenar los empleados, lista inexistente...");
            	}
            break;
            case 8:
            	if(controller_saveAsText(ARCHIVO_TXT,listaEmpleados)){
            		printf("Archivo guardado con exito...");
            	}
            	else{
            		printf("No se pudo guardar el archivo en modo texto...");
            	}
            break;
            case 9:
            	if(controller_saveAsBinary(ARCHIVO_BIN, listaEmpleados)){
            		printf("Archivo guardado con exito...");
            	}
            	else{
            		printf("No se pudo guardar el archivo en modo binario...");
            	}
            break;
        }
    }while(option!=10);
    return 0;
}









