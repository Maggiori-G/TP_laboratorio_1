#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int retorno=0;
	char id[100];
	char nombre[128];
	char horas[100];
	char sueldo[100];
	if(pFile!=NULL&&pArrayListEmployee!=NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
		while(!feof(pFile)){
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
			auxEmployee=employee_newParametros(id, nombre, horas, sueldo);
			ll_add(pArrayListEmployee, auxEmployee);
			retorno=1;
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	Employee* auxEmployee=NULL;
	if(pFile!=NULL&&pArrayListEmployee!=NULL){
		while(!feof(pFile)){
			auxEmployee=employee_new();
			fread(auxEmployee, sizeof(Employee), 1,pFile);
			ll_add(pArrayListEmployee, auxEmployee);
			retorno=1;
		}
	}
    return retorno;
}
