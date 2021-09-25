/*
 * Biblioteca.c
 *
 *  Created on: 23 sep. 2021
 *      Author: tanii
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
/// @brief Con esta funcion le pido al usuario que ingrese un numero double, que la voy a usar para determinar los dos operandos, esta funcion tambien llama a
/// la funcion que valida que el lo que ingresa sea un numero valido.
///
/// @param Mensaje es el mensaje que quiero printear cuando la use para pedir el primer operando o segundo operando.
/// @return Es el numero ya validado que quedara como primero segundo operando.
double PedirOperando(char mensaje[])
{
	char numero[1000];
	int retorno;
	double operandoValidado;
	do
	{
		printf("%s",mensaje);
		scanf("%s",numero);
		retorno=Validador(numero);
	}while(retorno==0);
	operandoValidado=atof(numero);
	return operandoValidado;
}
///  @brief Esta funcion es la que valida que lo que el usuario ingrese en los operandos sea un numero.
/// @param operando Es lo que el usuario ingresa.
/// @return retorna 0 si no es un digito y retorna 1 si lo es.
int Validador(char operando[])
{
	int i;
	int retorno;
	for(i=0;i<strlen(operando);i++)
	{
		if(!(isdigit(operando[i])||operando[i]==45||operando[i]==46))
		{
			printf("ERROR. No es un numero, reingrese!\n");
			retorno=0;
			break;
		}
		retorno=1;
	}
	return retorno;
}
/// @brief Esta funcion suma los operandos una vez validados
///
/// @param primerNumero Es el primer operando validado que ingreso el usuario.
/// @param segundoNumero Es el segundo operando validado que ingreso el usuario.
/// @return Retorna el resultado de la suma.
double Suma(double primerNumero, double segundoNumero)
{
	double resultado;
	resultado=(double)(primerNumero)+(segundoNumero);
	return resultado;
}
/// @brief Esta funcion realiza una resta.
///
/// @param primerNumero Primer operando valido que ingreso el usuario.
/// @param segundoNumero Segundo operando valido que ingreso el usuario.
/// @return Retorna el resultado de la resta.
double Resta(double primerNumero, double segundoNumero)
{
	double resultado;
	resultado=(double)(primerNumero)-(segundoNumero);
	return resultado;
}
/// @brief Esta funcion multiplica los operandos.
///
/// @param primerNumero Es el primer operando validado que ingreso.
/// @param segundoNumero Es el segundo operando validado que ingreso el usuario.
/// @return Retorna el resultado de la multiplicacion.
double Multiplicacion(double primerNumero, double segundoNumero)
{
	double multiplicacion;
	multiplicacion=(double)(primerNumero)*(segundoNumero);
	return multiplicacion;
}
/// @brief Esta funcion divide el primer operando entre el segundo operando.
///
/// @param primerNumero Recibe el primer operando.
/// @param segundoNumero Recibe el segundo operando.
/// @return Retorna el resultado de la division.
double Division(double primerNumero, double segundoNumero)
{
	double division;
	division=(double)(primerNumero)/(segundoNumero);
	return division;
}
/// @brief Esta funcion realiza el factorial de un operando ingresado. Recibe la variable numero que es uno de los dos operandos y si puede lo pasa a entero,
/// realiza el factorial y pasa el resultado por puntero, lo condicione a menor a 171 porque el compilador rompe porque el numero es demaciado grande.
/// @param numero es el operando del cual se quiere realizar el factorial si se puede.
/// @param pResultado Es el resultado del factorial si se pudo hacer.
/// @return retorna 1 si pudo realizar el factorial o 0 si no pudo realizarlo.
int Factorial(double elNumero,double*pResultado)
{
	int i;
	int retorno;
	int auxiliar=(int)elNumero;
	if(elNumero>0&&elNumero==auxiliar&&elNumero<171)
	{
		retorno=1;
		for(i=(elNumero-1);i>1;i--)
		{
			elNumero*=i;
		}
		}
		else
		{
			retorno=0;
		}
	*pResultado=elNumero;
	return retorno;
}
/// @brief Esta funcion es la que maneja el menu de opciones, lo que hace es validar que el usuario solo pueda ingresar un numero de 1 al 5 y le tire error
/// si ingresa letras o numeros que no estan permitidos en el menu de opciones del do-while.
/// @param mensaje recibe un mensaje que muestra en pantalla donde le da la opcion.
/// @return El retorno es el numero validado entre 1 y 5 que son las opciones del menu.
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




