/*
 *  main.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#include "Controlador.h"

int main()
{
	//Definición de clases

	VLibreria v;
	Controlador c;

	//Definición de variables
	int opc;

	//Ciclo del menú
	do
	{

		v.encabezado("MENÚ DE OPCIONES");

		//Opciones válidas para el programa
		opc = v.LeerValidarNro("\n(1) Cargar Datos."
							   "\n(2) Procesar Ventas."
							   "\n(3) Reporte Estadístico"
							   "\n(4) Finalizar."
							   "\n Ingrese una opción: ", 1, 4);

		//Definición de la opción escogida por el usuario
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


	//Finalización del programa
	return 0;
}


