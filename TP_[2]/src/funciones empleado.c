/*
 * funciones empleado.c
 * Author: Gianni, Maggiori.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
int PedirOpcionValidada(char mensaje[])
{
	int i;
	int opcion;
	int bandera=0;
	char auxOpcion[25];
	printf("%s",mensaje);
	while(bandera==0)
	{
		bandera=1;
		scanf("%s",auxOpcion);
		for(i=0;auxOpcion[i]!='\0';i++)
		{
			if(auxOpcion[i]<'1'||auxOpcion[i]>'5'||strlen(auxOpcion)>1||strlen(auxOpcion)<1)
			{
				bandera=0;
				printf("ERROR. Opción incorrecta, reingrese.");
				break;
			}
		}
	}
	opcion=atoi(auxOpcion);
	return opcion;
}
int PedirEntero(char mensaje[], char mensajeError[])
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
				printf(mensajeError);
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
int PedirCadena(char cadena[], char mensaje[], char mensajeError[])
{
	int retorno=0;
	int largo;
	int bandera=0;
	do
	{
		if(bandera==1)
		{
			printf(mensajeError);
		}
		else
		{
			printf(mensaje);
		}
		fflush(stdin);
		gets(cadena);
		largo=strlen(cadena);
		for(int i=0;i<largo;i++)
		{
			if(isdigit(cadena[i])==1&&cadena[i]!=32)
			{
				bandera=1;
				break;
			}
			else
			{
				bandera=0;
			}
		}
	}while(bandera==1);
	retorno=1;
	return retorno;
}
int PedirEnteroValidado(char mensaje[], char mensajeError[],int min, int max)
{
	int entero;
	printf(mensaje);
	fflush(stdin);
	scanf("%i",&entero);
	while((entero<min||entero>max))
	{
		printf(mensajeError);
		printf(mensaje);
		fflush(stdin);
		scanf("%i",&entero);
	}
	return entero;
}
