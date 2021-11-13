/*
 * input.h
 *
 *  Created on: 10 nov. 2021
 *      Author: tanii
 */

#ifndef INPUT_H_
#define INPUT_H_


int PedirEntero(char mensaje[]);
float PedirFlotante(char mensaje[], char mensajeError[]);
int PedirTexto(char cadena[], char mensaje[], int tam);
int ValidarCadenaNombres(char cadena[]);
int Pedir(char cadena[], char mensaje[],int tam);
int PedirOpcion(char mensaje[], int min, int max);
void ImprimirOpciones();
#endif /* INPUT_H_ */
