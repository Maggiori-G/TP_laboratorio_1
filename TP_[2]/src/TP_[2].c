/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Gianni
 Version     :
 Copyright   : Your copyright notice
 Description : TP Numero 2
 ============================================================================
 */
#include "ArrayEmployees.h"

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int contadorId;
	int contadorIngresos=0;
	int idBorrar;
	int metodoOrdenamiento;
	float salarioTotal;
	float promedioSalarios;
	int salariosMayorAlPromedio;
	Employee empleado;
	Employee listaEmpleados[1000];
	contadorId=0;
	InitEmployees(listaEmpleados, 1000);

	do
	{
		printf("\t\t==========================================\n");
		printf("\t\tSELECCIONE UNA DE LAS SIGUIENTES OPCIONES:\n");
		printf("\t\t==========================================\n");
		printf("\n\n1-ALTA EMPLEADO\n2-MODIFICAR EMPLEADO\n3-BAJA EMPLEADO\n4-INFORMAR LISTA DE EMPLEADOS\n5-SALIR\n\n");


		switch(opcion)
		{
			case 1:
				empleado=CargarUnEmpleado();
				contadorId++;
				AddEmployee(listaEmpleados, 1000, contadorId, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
				contadorIngresos++;
			break;
			case 2:
				if(contadorIngresos>0)
				{
					PrintEmployees(listaEmpleados, 1000);
					ModifiedEmployee(listaEmpleados, 1000);
				}
				else
				{
					printf("Aun no se ingreso ningun empleado!\n");
				}

			break;
			case 3:
				if(contadorIngresos>0)
				{
					PrintEmployees(listaEmpleados, 1000);
					idBorrar=PedirEntero("Seleccione el ID que desea eliminar: ", "Error\n");
					RemoveEmployee(listaEmpleados, 1000, idBorrar);
					contadorIngresos--;
				}
				else
				{
					printf("Aun no se ingreso ningun empleado!\n");
				}
			break;
			case 4:
				if(contadorIngresos>0)
				{
					metodoOrdenamiento=PedirEnteroValidado("Ingrese el metodo en el que quiere ordenar. 0 para descendente o 1 para ascendente: \n", "Error\n", 0, 1);
					SortEmployees(listaEmpleados, 1000, metodoOrdenamiento);
					PrintEmployees(listaEmpleados, 1000);
					salarioTotal=CalcularSalarioEmployee(listaEmpleados, 1000);
					promedioSalarios=PromedioSalario(salarioTotal, contadorIngresos);
					salariosMayorAlPromedio=SalarioMayorAlPromedio(listaEmpleados, 1000, promedioSalarios);
					printf("\nEl salario total de todos los empleados es: %25.2f\nEl salario promedio es: %45.2f\nLa cantidad de personas que superan el salario promedio es: %3i\n",salarioTotal,promedioSalarios,salariosMayorAlPromedio);
				}
				else
				{
					printf("Aun no se ingreso ningun empleado!\n");
				}
			break;
		}
		opcion=PedirOpcionValidada("\nQue accion desea realizar?\n");
	}while(opcion!=5);
	printf("Muchas gracias por utilizar mi programa!");
	return EXIT_SUCCESS;
}
