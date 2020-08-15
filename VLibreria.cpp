/*
 *  VLibreria.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
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
	ImprimirMensaje("\n            Librer�a ''Tecnolog�a a su Alcance''              ");
	ImprimirMensaje("\n ------- -------- -------- -------- -------- -------- ------- ");
	ImprimirString ("\n - - - - - > ", enc);
	ImprimirMensaje("\n==============================================================");

	ImprimirLineasBlanco(1);

}

//Subt�tulo personalizado

void VLibreria::subTitulo(string sub)
{

	//La variable ficticia "sub" permite mostrar un mensaje que cumplir� la funci�n de subt�tulo

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

//Listado de �reas

void VLibreria::listadoAreas(vector<string> nombreArea)
{

	//Variable local que le asigna un n�mero espec�fico a cada �rea

	int numArea = 1;

	//Texto que indicar� lo que mostrar� el listado

	ImprimirLineasBlanco(1);

	ImprimirStringJustificado("Tipo de �rea", 15);
	ImprimirStringJustificado("Descripci�n del �rea", 45);

	ImprimirLineasBlanco(1);

	//Ciclo que da origen al listado de las �reas disponibles en la Librer�a

	for(unsigned int i = 0; i<nombreArea.size(); i++)
	{
		ImprimirNroJustificado(numArea, 10);
		ImprimirStringJustificado(nombreArea[i], 40);
		ImprimirLineasBlanco(1);
		numArea++;
	}

	ImprimirLineasBlanco(1);

}

//Reporte de la librer�a

void VLibreria::reporteLibreria(vector<string> nombreAreas, vector<float> montoAreas, float montoTotal)
{

	//Texto que indicar� lo que mostrar� el listado

	ImprimirStringJustificado("Descripci�n del �rea", 10);
	ImprimirStringJustificado("Monto total ingresado por Libros", 30);

	ImprimirLineasBlanco(1);

	//Ciclo que da origen al listado

	for(unsigned int i = 0; i<nombreAreas.size(); i++)
	{
		ImprimirStringJustificado(nombreAreas[i], 10);
		ImprimirNroDecimalJustificado(montoAreas[i], 30);
		ImprimirLineasBlanco(1);
	}

	//Reporte del monto total ingresado a la Librer�a

	ImprimirNroDecimal("\nMonto Total Ingresado por los Libros: ", montoTotal);

	ImprimirLineasBlanco(2);

	Pausa();

}
