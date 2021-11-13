/*
 * input.c
 *
 *  Created on: 10 nov. 2021
 *      Author: tanii
 */
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
int PedirOpcion(char mensaje[], int min, int max){
	int opcion;
	printf(mensaje);
	fflush(stdin);
	scanf("%i",&opcion);
	while(opcion<min||opcion>max){
		printf("ERROR\n");
		printf(mensaje);
		fflush(stdin);
		scanf("%i",&opcion);
	}
	return opcion;
}
void ImprimirOpciones(){
	printf("\t\t\t===========================\n");
	printf("\t\t\tADMINISTRACION DE EMPLEADOS\n");
	printf("\t\t\t===========================\n");
	printf("=====\n");
	printf("MENU:\n");
	printf("=====\n");
	printf("\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
	printf("\n2-Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
	printf("\n3-Alta de empleado");
	printf("\n4-Modificar datos de empleado");
	printf("\n5-Baja de empleado");
	printf("\n6-Listar empleados");
	printf("\n7-Ordenar empleados");
	printf("\n8-Guardar los datos de los empleados en el archivo data.csv (modo texto)");
	printf("\n9-Guardar los datos de los empleados en el archivo data.csv (modo binario)");
	printf("\n10-SALIR\n\n");
}
int PedirEntero(char mensaje[])
{
	char numero[1000];
	int entero;
	int largo;
	int resultado;
	int i;
	do
	{
		printf(mensaje);
		fflush(stdin);
		gets(numero);
		largo=strlen(numero);
		for(i=0;i<largo;i++)
		{
			if((i==0&&numero[i]=='-')||(isdigit(numero[i])==1))
			{
				resultado=1;
			}
			else
			{
				resultado=0;
				printf("\nERROR\n");
				break;
			}
		}
	}while(resultado==0);
	entero=atoi(numero);
	return entero;
}
float PedirFlotante(char mensaje[], char mensajeError[])
{
	char numero[10000];
	int largo;
	int contadorDePuntos=0;
	float flotante;
	int resultado;
	int i;
	do
	{
		printf(mensaje);
		fflush(stdin);
		gets(numero);
		largo=strlen(numero);
		for(i=0;i<largo;i++)
		{
			if((isdigit(numero[i])==1)||(i==0&&numero[i]=='-')||(i!=0&&numero[i]=='.'))
			{
				resultado=1;
				if(numero[i]=='.')
				{
					contadorDePuntos++;
					if(contadorDePuntos>1)
					{
						resultado=0;
						break;
					}
				}
			}
			else
			{
				resultado=0;
				printf(mensajeError);
				break;
			}
		}
	}while(resultado==0);
	flotante=atof(numero);
	return flotante;
}
int Pedir(char cadena[], char mensaje[],int tam)
{
	printf(mensaje);
	fflush(stdin);
	fgets(cadena,tam,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}
int ValidarCadenaNombres(char cadena[])
{
	int retorno=1;
	int largo;
	largo=strlen(cadena);
	for(int i=0;i<largo;i++)
	{
		if((i==0&&cadena[i]==32))
		{
			retorno=0;
			break;
		}
	}
	if(retorno==1)
	{
		strlwr(cadena);
	}
	return retorno;
}
int PedirTexto(char cadena[], char mensaje[], int tam)
{
	int retorno=-1;
	do
	{
		Pedir(cadena, mensaje, tam);
		if(ValidarCadenaNombres(cadena)==1)
		{
			retorno=1;
		}
		else
		{
			printf("\nERROR\n");
		}
	}while(retorno==-1);
	return retorno;
}
