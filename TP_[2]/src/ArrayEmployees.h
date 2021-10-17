/*
 * ArrayEmployees.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Gianni, Maggiori
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "funciones empleado.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;
int InitEmployees(Employee* list, int len);
Employee CargarUnEmpleado();
int AddEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int ModifiedEmployee(Employee* list, int len);
int FindEmployeeById(Employee* list, int len,int id);
int PrintEmployee(Employee unEmpleado);
int PrintEmployees(Employee* list, int len);
int RemoveEmployee(Employee* list, int len, int id);
int SortEmployees(Employee* list, int len, int order);
float CalcularSalarioEmployee(Employee* list, int len);
float PromedioSalario(float salarioTotal, int contador);
int SalarioMayorAlPromedio(Employee* list, int len, float promedio);
#endif /* ARRAYEMPLOYEES_H_ */
