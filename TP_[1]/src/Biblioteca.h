/*
 * Biblioteca.h
 *
 *  Created on: 23 sep. 2021
 *      Author: tanii
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int Validador(char numero[]);
double PedirOperando(char mensaje[]);

double Suma(double primerNumero, double segundoNumero);
double Resta(double primerNumero, double segundoNumero);
double Multiplicacion(double primerNumero, double segundoNumero);
double Division(double primerNumero, double segundoNumero);
int Factorial(double a,double*pResultado);
int PedirOpcionValidada(char mensaje[]);



#endif /* BIBLIOTECA_H_ */
