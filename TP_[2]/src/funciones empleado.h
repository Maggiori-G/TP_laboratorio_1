/*
 * 	funciones empleado.h
 *
 *	Created on: 10 oct. 2021
 *  Author: Gianni, Maggiori
 */

#ifndef FUNCIONES_EMPLEADO_H_
#define FUNCIONES_EMPLEADO_H_

int PedirOpcionValidada(char mensaje[]);
int PedirEntero(char mensaje[],char mensajeError[]);
float PedirFlotante(char mensaje[],char mensajeError[]);
int PedirCadena(char cadena[], char mensaje[],char mensajeError[]);
int PedirEnteroValidado(char mensaje[],char mensajeError[],int min, int max);


#endif /* FUNCIONES_EMPLEADO_H_ */
