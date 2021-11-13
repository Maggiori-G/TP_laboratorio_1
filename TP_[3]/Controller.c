#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include "Controller.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	FILE* file;
	if(pArrayListEmployee!=NULL){
		file=fopen(path,"r");
		if(file!=NULL){
			parser_EmployeeFromText(file, pArrayListEmployee);
			retorno=1;
		}
	}
	fclose(file);
	return retorno;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	FILE* file;
	if(pArrayListEmployee!=NULL){
		file=fopen(path, "rb");
		if(file!=NULL){
			parser_EmployeeFromBinary(file, pArrayListEmployee);
			retorno=1;
		}
	}
	fclose(file);
	int tam;
	tam=ll_len(pArrayListEmployee);
	ll_remove(pArrayListEmployee, tam-1);
    return retorno;
}
int controller_ultimoID(LinkedList* lista){
	int id=0;
	int tam;
	int bandera=0;
	Employee* auxEmployee;
	if(lista!=NULL){
		tam=ll_len(lista);
		for(int i=0;i<tam;i++){
			auxEmployee=(Employee*)ll_get(lista, i);
			if(bandera==0||id<auxEmployee->id){
				id=auxEmployee->id;
				bandera=1;
			}
		}
	}
	return id;
}
int controller_generarProximoID(LinkedList* lista){
	int id=0;
	if(lista!=NULL){
		id=controller_ultimoID(lista);
		id++;
	}
	return id;
}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)//aca va el malloc y las llamadas a las funciones employee
{
	int retorno=0;
	Employee* auxEmpleado;
	char idEmpleado[150];
	int proximoID;
	char nombreEmpleado[150];
	char horasTrabajadasEmpleado[150];
	char sueldoEmpleado[150];

	if(pArrayListEmployee!=NULL){
		proximoID=controller_generarProximoID(pArrayListEmployee);
		sprintf(idEmpleado,"%i", proximoID);
		PedirTexto(nombreEmpleado, "Ingrese el nombre del empleado: ", 150);
		PedirTexto(horasTrabajadasEmpleado, "Ingrese las horas trabajadas por el empleado: ", 150);
		PedirTexto(sueldoEmpleado, "Ingrese el sueldo del empleado: ", 150);
		auxEmpleado=employee_newParametros(idEmpleado, nombreEmpleado, horasTrabajadasEmpleado, sueldoEmpleado);
		ll_add(pArrayListEmployee, auxEmpleado);
		retorno=1;
	}
    return retorno;
}
int EncontrarEmployeePorId(LinkedList* pArrayListEmployee, int buscadorId){
	int tam;
	int retorno=-1;
	Employee* auxEmployee=NULL;
	if(pArrayListEmployee!=NULL){
		tam=ll_len(pArrayListEmployee);
		for(int i=0;i<tam;i++){
			auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
			if(auxEmployee->id==buscadorId){
				retorno=ll_indexOf(pArrayListEmployee, auxEmployee);
			}
		}
	}
	return retorno;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int buscadorId;
	int opcion;
	int index;
	Employee* auxEmployee=NULL;
	int retorno=0;
	if(pArrayListEmployee!=NULL){

		controller_ListEmployee(pArrayListEmployee);
		buscadorId=PedirOpcion("\nIngrese el ID del empleado que desea modificar: ", 1, 9999);
		index=EncontrarEmployeePorId(pArrayListEmployee, buscadorId);
		if(index!=-1){
			auxEmployee=(Employee*)ll_get(pArrayListEmployee, index);
			do{
				printf("\nMODIFICACIONES:\n");
				printf("\n\n1-Modificar nombre\n2-Modificar horas trabajadas\n3-Modificar sueldo\n4-Finalizar modificaciones\n");
				opcion=PedirOpcion("\nIngrese la opcion que desee: ", 1, 4);
				switch(opcion){
				case 1:
					PedirTexto(auxEmployee->nombre, "\nIngrese nuevo nombre del empleado: ", 128);
					break;
				case 2:
					auxEmployee->horasTrabajadas=PedirEntero("\nIngrese la cantidad de horas trabajadas a modificar: ");
					break;
				case 3:
					auxEmployee->sueldo=PedirEntero("\nIngrese el nuevo sueldo del empleado: ");
					break;
				}
			}while(opcion!=4);
			retorno=1;
		}
		else{
			printf("\n\nNo se encontro el empleado, intente nuevamente!");
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int retorno=0;
    int index;
    int buscadorId;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL){
    	//tam=ll_len(pArrayListEmployee);
    	controller_ListEmployee(pArrayListEmployee);
    	buscadorId=PedirOpcion("\nIngrese el ID del empleado que desea eliminar: ", 1, 9999);
    	index=EncontrarEmployeePorId(pArrayListEmployee, buscadorId);
    	if(index!=-1){
    		auxEmployee=(Employee*)ll_get(pArrayListEmployee, index);
    		ll_remove(pArrayListEmployee, index);
    		employee_delete(auxEmployee);
    		retorno=1;
    	}
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int tam;
	int id;
	char nombre[128];
	int horas;
	int sueldo;
	Employee* auxEmpleado;
	if(pArrayListEmployee!=NULL){
		tam=ll_len(pArrayListEmployee);
		printf("\nID\tNOMBRE\t\t\tHORAS TRABAJADAS\tSUELDO\n\n");
		for(int i=0;i<tam;i++){
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &id);
			employee_getNombre(auxEmpleado, nombre);
			employee_getHorasTrabajadas(auxEmpleado, &horas);
			employee_getSueldo(auxEmpleado, &sueldo);
			printf("%-8i%-24s%-23i %i\n",id,nombre,horas,sueldo);
			retorno=1;
		}
	}

    return retorno;;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int opcion;
	int opcionOrdenamiento;
	if(pArrayListEmployee!=NULL){
		system("cls");
		do{
			printf("\n\nBienvenido al menu de ordenamiento\nSeleccione una de las siguientes opciones para elegir el tipo de ordenamiento que desea realizar\n\n");
			opcion=PedirOpcion("\n1-Ordenar por ID\n2-Ordenar por nombre\n3-Ordenar por cantidad de horas trabajadas\n4-Ordenar por sueldo\n5-Salir\n", 1, 5);
			if(opcion!=5){
				opcionOrdenamiento=PedirOpcion("\nSeleccione un orden de ordenamiento. 0 para descendente o 1 para ascendente\n", 0, 1);
			}
			switch(opcion){
			case 1:
				ll_sort(pArrayListEmployee, OrdenamientoPorId, opcionOrdenamiento);
			break;
			case 2:
				ll_sort(pArrayListEmployee, OrdenamientoPorNombre, opcionOrdenamiento);
			break;
			case 3:
				ll_sort(pArrayListEmployee, OrdenamientoPorHoras, opcionOrdenamiento);
			break;
			case 4:
				ll_sort(pArrayListEmployee, OrdenamientoPorSueldo, opcionOrdenamiento);
			break;
			}
		}while(opcion!=5);
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int tam=0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	FILE* file;
	Employee* auxEmpleado=NULL;
	tam=ll_len(pArrayListEmployee);
	file=fopen(path,"w");
	if(path!=NULL&&pArrayListEmployee!=NULL){
		if(file!=NULL){
			fprintf(file,"Id,Nombre,HorasTrabajadas,Salario\n");
			for(int i=0;i<tam;i++){
				auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(auxEmpleado, &id);
				employee_getNombre(auxEmpleado,nombre);
				employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
				employee_getSueldo(auxEmpleado, &sueldo);
				fprintf(file,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
				retorno=1;
			}
		}
	}
	fclose(file);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int tam;
	FILE* file;
	Employee* auxEmployee=NULL;
	if(path!=NULL&&pArrayListEmployee!=NULL){
		file=fopen(path,"wb");
		tam=ll_len(pArrayListEmployee);
		for(int i=0;i<tam;i++){
			auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
			fwrite(auxEmployee,sizeof(Employee),1,file);
			retorno=1;
		}
	}
	fclose(file);
    return retorno;
}

