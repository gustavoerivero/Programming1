/*
 *  main.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
 */

#include "Controlador.h"

int main()
{
	//Definici�n de clases

	VLibreria v;
	Controlador c;

	//Definici�n de variables
	int opc;

	//Ciclo del men�
	do
	{

		v.encabezado("MEN� DE OPCIONES");

		//Opciones v�lidas para el programa
		opc = v.LeerValidarNro("\n(1) Cargar Datos."
							   "\n(2) Procesar Ventas."
							   "\n(3) Reporte Estad�stico"
							   "\n(4) Finalizar."
							   "\n Ingrese una opci�n: ", 1, 4);

		//Definici�n de la opci�n escogida por el usuario
		switch(opc)
		{

			case 1:
			{
				c.cargaDatos();
				break;
			}

			case 2:
			{
				c.procesarVenta();
				break;
			}

			case 3:
			{
				c.reporteEstadistico();
				break;
			}

		}

	}
	while(opc != 4);


	//Finalizaci�n del programa
	return 0;
}


