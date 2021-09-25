/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Maggiori, Gianni Div 1C
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Práctico Numero 1.

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "Biblioteca.h"

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	double primerOperando;
	double segundoOperando;
	int banderaPrimerOperando=0;
	int banderaSegundoOperando=0;
	int banderaParaCalcular=0;
	double suma;
	double resta;
	double multiplicacion;
	double division;
	double factorialPrimerOperando;
	double factorialSegundoOperando;
	int banderaPrimerFactorial=0;
	int banderaSegundoFactorial=0;
	printf("\t\t\t\t===========================================================\n");
	printf("\t\t\t\t***Bienvenidos a la Calculadora que solo hace 5 cosas!!!***\n");
	printf("\t\t\t\t===========================================================\n");
	do
	{
		if(banderaPrimerOperando==0)
		{
			printf("================================================================\n");
			printf("Opcion 1: Ingrese el primer operando: A= Aun no se ingreso. \n");
		}
		else
		{
			printf("Opcion 1: Ingrese el primer operando: A= %.2f \n",primerOperando);
		}
		if(banderaSegundoOperando==0)
		{
			printf("Opcion 2: Ingrese el segundo operando: B= Aun no se ingreso. \n");
		}
		else
		{
			printf("Opcion 2: Ingrese el segundo operando: B= %.2lf .\n",segundoOperando);
		}
		printf("Opcion 3: Realizar todas las operaciones.\n");
		printf("Opcion 4: Mostrar todos los resultados.\n");
		printf("Opcion 5: Salir.\n");
		printf("================================================================\n");

		switch(opcion)
		{
			case 1:
				primerOperando=PedirOperando("Ingrese el primer operando: \n");
				banderaPrimerOperando=1;
				banderaParaCalcular=0;
			break;
			case 2:
				segundoOperando=PedirOperando("Ingrese el segundo operando: \n");
				banderaSegundoOperando=1;
				banderaParaCalcular=0;
			break;
			case 3:
				if(banderaPrimerOperando==0||banderaSegundoOperando==0)
				{
					printf("No se puede realizar las operaciones si aun no se ingresaron los operandos.\n");
				}
				else
				{
					suma=Suma(primerOperando, segundoOperando);
					resta=Resta(primerOperando, segundoOperando);
					multiplicacion=Multiplicacion(primerOperando, segundoOperando);
					division=Division(primerOperando, segundoOperando);
					banderaPrimerFactorial=Factorial(primerOperando,&factorialPrimerOperando);
					banderaSegundoFactorial=Factorial(segundoOperando,&factorialSegundoOperando);
					banderaParaCalcular=1;
				}
			break;
			case 4:
				if(banderaParaCalcular==0)
				{
					printf("No se pueden mostrar los resultados sin hacer los calculos.\n");
				}
				else
				{
					printf("================================================================\n");
					printf("El resultado de la suma entre %.2lf y %.2lf es: %.2lf\n\n",primerOperando,segundoOperando,suma);
					printf("El resultado de la resta entre %.2lf y %.2lf es: %.2lf\n\n",primerOperando,segundoOperando,resta);
					printf("El resultado de la multiplicacion entre %.2lf y %.2lf es: %.2lf\n\n",primerOperando,segundoOperando,multiplicacion);
					if(segundoOperando==0)
					{
						printf("No se puede dividir entre 0\n\n");
					}
					else
					{
						printf("El resultado de la division entre %.2lf y %.2lf es: %.2lf\n\n",primerOperando,segundoOperando,division);
					}
					if(banderaPrimerFactorial==1)
					{
						printf("El factorial de A=%.2lf es: %.2lf\n\n",primerOperando,factorialPrimerOperando);
					}
					else
					{
						printf("No se pudo calcular el factorial del primer operando.\n\n");
					}
					if(banderaSegundoFactorial==1)
					{
						printf("El factorial de B=%.2lf es: %.2lf\n",segundoOperando,factorialSegundoOperando);
					}
					else
					{
						printf("No se pudo calcular el factorial del segundo operando.\n");
					}
					printf("================================================================\n");
					}
				break;
		}

		opcion=PedirOpcionValidada("Que accion desea realizar? ");
	}while(opcion!=5);
	printf("Gracias por utilizar la calculadora que solo realiza 5 operaciones!! Si le resulto util, deje una buena reseña!");
	return 0;
}
