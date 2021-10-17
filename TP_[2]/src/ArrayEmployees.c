<<<<<<< HEAD
/*
 * ArrayEmployees.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Gianni, Maggiori
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "funciones empleado.h"
#include "ArrayEmployees.h"

int InitEmployees(Employee* list, int len)
{
	int retorno=-1;
	if(list!=NULL||(len>0&&len<1000))
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
Employee CargarUnEmpleado()
{
	Employee unEmpleado;
	PedirCadena(unEmpleado.name, "Ingrese el nombre: ", "Error, Reingrese el nombre: ");
	PedirCadena(unEmpleado.lastName, "Ingrese el apellido: ","Error, Reingrese el apellido: ");
	unEmpleado.salary=PedirFlotante("Ingrese el salario: ", "Error\n");
	unEmpleado.sector=PedirEntero("Ingrese el sector del empleado: ", "Error\n");
	return unEmpleado;
}
int AddEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==1)
		{
			list[i].id=id;
			list[i].salary=salary;
			list[i].sector=sector;
			strcpy(list[i].lastName,lastName);
			strcpy(list[i].name,name);
			list[i].isEmpty=0;
			break;
		}
		retorno=0;
	}
	return retorno;
}
int FindEmployeeById(Employee* list, int len,int id)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
	{
		if(id==list[i].id)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}
int ModifiedEmployee(Employee* list, int len)
{
	int retorno=0;
	int posicion;
	int buscadorDeId;
	int campoAModificar;

	buscadorDeId=PedirEntero("\nSeleccione el ID que quiere modificar: \n", "\nError, ID incorrecto o inexistente. Reingrese\n");
	posicion=FindEmployeeById(list, len, buscadorDeId);
	do
	{
		campoAModificar=PedirEnteroValidado("\n1-Modificar nombre.\n2-Modificar apellido.\n3-Modificar salario\n4-Modificar sector.\n5-Dejar de modificar\n\nIndique que campo desea modificar: ", "ERROR,\n1- Modificar nombre.\n2-Modificar apellido.\n3-Modificar salario\n4-Modificar sector.\nIndique que campo desea modificar: ",1,5);
		switch(campoAModificar)
		{
			case 1:
				PedirCadena(list[posicion].name, "Ingrese el nombre a modificar: ", "Error, Reingrese el nombre: ");
			break;
			case 2:
				PedirCadena(list[posicion].lastName, "Ingrese el apellido a modificar: ", "Error, Reingrese el apellido: ");
			break;
			case 3:
				list[posicion].salary=PedirFlotante("Ingrese el salario para modificar: ", "Error\n");
			break;
			case 4:
				list[posicion].sector=PedirEntero("Ingrese el sector que desea modificar: ", "Error\n");
			break;
			case 5:
			break;
		}
		retorno=1;
	}while(campoAModificar!=5);
	return retorno;
}
int PrintEmployee(Employee unEmpleado)
{
	int retorno=0;
	printf("%i\t%-25s %-25s %-10.2f %-2i \n",unEmpleado.id, unEmpleado.name,unEmpleado.lastName,unEmpleado.salary,unEmpleado.sector);
	return retorno;
}
int PrintEmployees(Employee* list, int len)
{
	int retorno=1;
	printf("\nID\tNOMBRE\t\t\t  APELLIDO\t\t    SALARIO    SECTOR\n");
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			PrintEmployee(list[i]);
		}
	}
	return retorno;
}
int RemoveEmployee(Employee* list, int len, int id)
{
	int retorno=0;
	for(int i=0;i<len;i++)
	{
		if(list[i].id==id&&list[i].isEmpty==0)
		{
			list[i].isEmpty=1;
			retorno=1;
			break;
		}
	}
	return retorno;
}
int SortEmployees(Employee* list, int len, int order)
{
	int retorno=0;
	Employee aux;
	if(order==0)
	{
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if(strcmp(list[i].lastName,list[j].lastName)<0)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else
				{
					if(strcmp(list[i].lastName,list[j].lastName)==0&&list[i].sector<list[j].sector)
					{
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}
	}
	else
	{
		if(order==1)
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmp(list[i].lastName,list[j].lastName)>0)
					{
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
					else
					{
						if(strcmp(list[i].lastName,list[j].lastName)==0&&list[i].sector>list[j].sector)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
					}
				}
			}
		}
	}
	return retorno;
}
float CalcularSalarioEmployee(Employee* list, int len)
{
	float acumuladorSalario=0;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			acumuladorSalario+=list[i].salary;
		}
	}
	return acumuladorSalario;
}
float PromedioSalario(float salarioTotal, int contador)
{
	float promedio;
	promedio=salarioTotal/contador;
	return promedio;
}
int SalarioMayorAlPromedio(Employee* list, int len, float promedio)
{
	int contador=0;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==0&&list[i].salary>promedio)
		{
			contador++;
		}
	}
	return contador;
}












=======
/*
 * ArrayEmployees.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Gianni, Maggiori
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "funciones empleado.h"
#include "ArrayEmployees.h"

int InitEmployees(Employee* list, int len)
{
	int retorno=-1;
	if(list!=NULL||(len>0&&len<1000))
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
Employee CargarUnEmpleado()
{
	Employee unEmpleado;
	PedirCadena(unEmpleado.name, "Ingrese el nombre: ", "Error, Reingrese el nombre: ");
	PedirCadena(unEmpleado.lastName, "Ingrese el apellido: ","Error, Reingrese el apellido: ");
	unEmpleado.salary=PedirFlotante("Ingrese el salario: ", "Error\n");
	unEmpleado.sector=PedirEntero("Ingrese el sector del empleado: ", "Error\n");
	return unEmpleado;
}
int AddEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==1)
		{
			list[i].id=id;
			list[i].salary=salary;
			list[i].sector=sector;
			strcpy(list[i].lastName,lastName);
			strcpy(list[i].name,name);
			list[i].isEmpty=0;
			break;
		}
		retorno=0;
	}
	return retorno;
}
int FindEmployeeById(Employee* list, int len,int id)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
	{
		if(id==list[i].id)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}
int ModifiedEmployee(Employee* list, int len)
{
	int retorno=0;
	int posicion;
	int buscadorDeId;
	int campoAModificar;

	buscadorDeId=PedirEntero("\nSeleccione el ID que quiere modificar: \n", "\nError, ID incorrecto o inexistente. Reingrese\n");
	posicion=FindEmployeeById(list, len, buscadorDeId);
	do
	{
		campoAModificar=PedirEnteroValidado("\n1-Modificar nombre.\n2-Modificar apellido.\n3-Modificar salario\n4-Modificar sector.\n5-Dejar de modificar\n\nIndique que campo desea modificar: ", "ERROR,\n1- Modificar nombre.\n2-Modificar apellido.\n3-Modificar salario\n4-Modificar sector.\nIndique que campo desea modificar: ",1,5);
		switch(campoAModificar)
		{
			case 1:
				PedirCadena(list[posicion].name, "Ingrese el nombre a modificar: ", "Error, Reingrese el nombre: ");
			break;
			case 2:
				PedirCadena(list[posicion].lastName, "Ingrese el apellido a modificar: ", "Error, Reingrese el apellido: ");
			break;
			case 3:
				list[posicion].salary=PedirFlotante("Ingrese el salario para modificar: ", "Error\n");
			break;
			case 4:
				list[posicion].sector=PedirEntero("Ingrese el sector que desea modificar: ", "Error\n");
			break;
			case 5:
			break;
		}
		retorno=1;
	}while(campoAModificar!=5);
	return retorno;
}
int PrintEmployee(Employee unEmpleado)
{
	int retorno=0;
	printf("%i\t%-25s %-25s %-10.2f %-2i \n",unEmpleado.id, unEmpleado.name,unEmpleado.lastName,unEmpleado.salary,unEmpleado.sector);
	return retorno;
}
int PrintEmployees(Employee* list, int len)
{
	int retorno=1;
	printf("\nID\tNOMBRE\t\t\t  APELLIDO\t\t    SALARIO    SECTOR\n");
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			PrintEmployee(list[i]);
		}
	}
	return retorno;
}
int RemoveEmployee(Employee* list, int len, int id)
{
	int retorno=0;
	for(int i=0;i<len;i++)
	{
		if(list[i].id==id&&list[i].isEmpty==0)
		{
			list[i].isEmpty=1;
			retorno=1;
			break;
		}
	}
	return retorno;
}
int SortEmployees(Employee* list, int len, int order)
{
	int retorno=0;
	Employee aux;
	if(order==0)
	{
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if(strcmp(list[i].lastName,list[j].lastName)<0)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else
				{
					if(strcmp(list[i].lastName,list[j].lastName)==0&&list[i].sector<list[j].sector)
					{
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}
	}
	else
	{
		if(order==1)
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmp(list[i].lastName,list[j].lastName)>0)
					{
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
					else
					{
						if(strcmp(list[i].lastName,list[j].lastName)==0&&list[i].sector>list[j].sector)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
					}
				}
			}
		}
	}
	return retorno;
}
float CalcularSalarioEmployee(Employee* list, int len)
{
	float acumuladorSalario=0;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			acumuladorSalario+=list[i].salary;
		}
	}
	return acumuladorSalario;
}
float PromedioSalario(float salarioTotal, int contador)
{
	float promedio;
	promedio=salarioTotal/contador;
	return promedio;
}
int SalarioMayorAlPromedio(Employee* list, int len, float promedio)
{
	int contador=0;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==0&&list[i].salary>promedio)
		{
			contador++;
		}
	}
	return contador;
}












>>>>>>> a01338866c8aaa707771eb270d064d573b4a71b6
