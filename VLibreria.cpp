/*
 *  VLibreria.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#include "VLibreria.h"

//Constructor

VLibreria::VLibreria()
{

}

//Encabezado personalizado

void VLibreria::encabezado(string enc)
{

	//La variable ficticia "enc" permite mostrar un mensaje personalizado

	Limpiar();

	ImprimirLineasBlanco(1);

	ImprimirMensaje("\n==============================================================");
	ImprimirMensaje("\n            Librería ''Tecnología a su Alcance''              ");
	ImprimirMensaje("\n ------- -------- -------- -------- -------- -------- ------- ");
	ImprimirString ("\n - - - - - > ", enc);
	ImprimirMensaje("\n==============================================================");

	ImprimirLineasBlanco(1);

}

//Subtítulo personalizado

void VLibreria::subTitulo(string sub)
{

	//La variable ficticia "sub" permite mostrar un mensaje que cumplirá la función de subtítulo

	ImprimirLineasBlanco(1);

	ImprimirMensaje("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	ImprimirString ("\n = = > ", sub);
	ImprimirMensaje("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

	ImprimirLineasBlanco(1);

}

//Mensaje de error

void VLibreria::error(string msjError)
{

	//La variable ficticia "msjError" permite mostrar un mensaje especificando el error

	ImprimirLineasBlanco(1);

	ImprimirMensaje("\n ------- -------- -------- -------- -------- -------- ------- ");
	ImprimirMensaje("\n   ERROR!");
	ImprimirString ("\n ", msjError);
	ImprimirMensaje("\n ------- -------- -------- -------- -------- -------- ------- ");

	ImprimirLineasBlanco(2);

	Pausa();

	return;

}

//Listado de Áreas

void VLibreria::listadoAreas(vector<string> nombreArea)
{

	//Variable local que le asigna un número específico a cada área

	int numArea = 1;

	//Texto que indicará lo que mostrará el listado

	ImprimirLineasBlanco(1);

	ImprimirStringJustificado("Tipo de Área", 15);
	ImprimirStringJustificado("Descripción del Área", 45);

	ImprimirLineasBlanco(1);

	//Ciclo que da origen al listado de las Áreas disponibles en la Librería

	for(unsigned int i = 0; i<nombreArea.size(); i++)
	{
		ImprimirNroJustificado(numArea, 10);
		ImprimirStringJustificado(nombreArea[i], 40);
		ImprimirLineasBlanco(1);
		numArea++;
	}

	ImprimirLineasBlanco(1);

}

//Reporte de la librería

void VLibreria::reporteLibreria(vector<string> nombreAreas, vector<float> montoAreas, float montoTotal)
{

	//Texto que indicará lo que mostrará el listado

	ImprimirStringJustificado("Descripción del Área", 10);
	ImprimirStringJustificado("Monto total ingresado por Libros", 30);

	ImprimirLineasBlanco(1);

	//Ciclo que da origen al listado

	for(unsigned int i = 0; i<nombreAreas.size(); i++)
	{
		ImprimirStringJustificado(nombreAreas[i], 10);
		ImprimirNroDecimalJustificado(montoAreas[i], 30);
		ImprimirLineasBlanco(1);
	}

	//Reporte del monto total ingresado a la Librería

	ImprimirNroDecimal("\nMonto Total Ingresado por los Libros: ", montoTotal);

	ImprimirLineasBlanco(2);

	Pausa();

}
