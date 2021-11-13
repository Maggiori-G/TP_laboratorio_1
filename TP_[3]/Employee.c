#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "Employee.h"
#include "input.h"


Employee* employee_new(){
	Employee* unEmpleado;
	unEmpleado=(Employee*)calloc(1,sizeof(Employee));
	return unEmpleado;
}
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){
	Employee* unEmpleado;
	unEmpleado=employee_new();
	if(idStr!=NULL&&nombreStr!=NULL&&horasTrabajadasStr!=NULL&&sueldoStr!=NULL){
		if(unEmpleado!=NULL){
			employee_setId(unEmpleado,atoi(idStr));
			employee_setNombre(unEmpleado,nombreStr);
			employee_setHorasTrabajadas(unEmpleado,atoi(horasTrabajadasStr));
			employee_setSueldo(unEmpleado,atoi(sueldoStr));
		}
	}
	return unEmpleado;
}
int employee_setId(Employee* this, int id){
	int retorno=0;
	if(this!=NULL){
		this->id=id;
		retorno=1;
	}
	return retorno;
}
int employee_getId(Employee* this, int* id){
	int retorno=0;
	if(this!=NULL&&id!=NULL){
		*id=this->id;
	}
	return retorno;
}
int employee_setNombre(Employee* this, char* nombre){
	int retorno=0;
	if(this!=NULL&&nombre!=NULL){
		strcpy(this->nombre,nombre);
		retorno=1;
	}
	return retorno;
}
int employee_getNombre(Employee* this, char* nombre){
	int retorno=0;
	if(this!=NULL&&nombre!= NULL){
		strcpy(nombre,this->nombre);
		retorno=1;
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
	int retorno=0;
	if(this!=NULL){
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
	int retorno=0;
	if(this!=NULL&&horasTrabajadas!=NULL){
		*horasTrabajadas=this->horasTrabajadas;
	}
	return retorno;
}
int employee_setSueldo(Employee* this, int sueldo){
	int retorno=0;
	if(this!=NULL){
		this->sueldo=sueldo;
		retorno=1;
	}
	return retorno;
}
int employee_getSueldo(Employee* this, int* sueldo){
	int retorno=0;
	if(this!=NULL&&sueldo!=NULL){
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}
void employee_delete(Employee* this){
	if(this!=NULL){
		free(this);
	}
}
int OrdenamientoPorId(void* pPrimerEmpleado, void* pSegundoEmpleado){
	int retorno=-1;
	int primerID;
	int segundoID;
	Employee* PrimerEmpleado;
	Employee* SegundoEmpleado;
	PrimerEmpleado=(Employee*)pPrimerEmpleado;
	SegundoEmpleado=(Employee*)pSegundoEmpleado;
	employee_getId(PrimerEmpleado, &primerID);
	employee_getId(SegundoEmpleado, &segundoID);
	if(primerID>segundoID){
		retorno=1;
	}
	else{
		if(primerID==segundoID){
			retorno=0;
		}
	}
	return retorno;
}
int OrdenamientoPorNombre(void* pPrimerEmpleado, void* pSegundoEmpleado){
	int retorno;
	char NombrePrimerEmpleado[128];
	char NombreSegundoEmpleado[128];
	Employee* PrimerEmpleado;
	Employee* SegundoEmpleado;
	PrimerEmpleado=(Employee*)pPrimerEmpleado;
	SegundoEmpleado=(Employee*)pSegundoEmpleado;
	employee_getNombre(PrimerEmpleado, NombrePrimerEmpleado);
	employee_getNombre(SegundoEmpleado, NombreSegundoEmpleado);
	retorno=strcmp(NombrePrimerEmpleado,NombreSegundoEmpleado);
	return retorno;
}
int OrdenamientoPorHoras(void* pPrimerEmpleado, void* pSegundoEmpleado){
	int retorno=-1;
	int horasPrimerEmpleado;
	int horasSegundoEmpleado;
	Employee* PrimerEmpleado;
	Employee* SegundoEmpleado;
	PrimerEmpleado=(Employee*)pPrimerEmpleado;
	SegundoEmpleado=(Employee*)pSegundoEmpleado;
	employee_getHorasTrabajadas(PrimerEmpleado, &horasPrimerEmpleado);
	employee_getHorasTrabajadas(SegundoEmpleado, &horasSegundoEmpleado);
	if(horasPrimerEmpleado>horasSegundoEmpleado){
		retorno=0;
	}
	else{
		if(horasPrimerEmpleado==horasSegundoEmpleado){
			retorno=1;
		}
	}
	return retorno;
}
int OrdenamientoPorSueldo(void* pPrimerEmpleado, void* pSegundoEmpleado){
	int retorno=-1;
	int sueldoPrimerEmpleado;
	int sueldoSegundoEmpleado;
	Employee* PrimerEmpleado;
	Employee* SegundoEmpleado;
	PrimerEmpleado=(Employee*)pPrimerEmpleado;
	SegundoEmpleado=(Employee*)pSegundoEmpleado;
	employee_getSueldo(PrimerEmpleado, &sueldoPrimerEmpleado);
	employee_getSueldo(SegundoEmpleado, &sueldoSegundoEmpleado);
	if(sueldoSegundoEmpleado>sueldoPrimerEmpleado){
		retorno=0;
	}
	else{
		if(sueldoSegundoEmpleado==sueldoPrimerEmpleado){
			retorno=1;
		}
	}
	return retorno;
}





























