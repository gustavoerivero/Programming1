/*
 *  VArea.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#include "VArea.h"

//Constructor

VArea::VArea()
{

}

//Listado de Libros

void VArea::listadoLibros(vector<string> codigoLibro, vector<string> nombreLibro, vector<float> precioLibro)
{

	//Texto que indicará lo que mostrará el listado

	ImprimirLineasBlanco(1);

	ImprimirStringJustificado("Código", 15);
	ImprimirStringJustificado("Título", 35);
	ImprimirStringJustificado("Precio", 35);

	ImprimirLineasBlanco(1);

	//Ciclo que da origen al listado de libros existentes en el Área

	for(unsigned int i = 0; i<codigoLibro.size(); i++)
	{
		ImprimirStringJustificado(codigoLibro[i], 10);
		ImprimirStringJustificado(nombreLibro[i], 30);
		ImprimirNroDecimalJustificado(precioLibro[i], 30);
		ImprimirLineasBlanco(1);
	}

	ImprimirLineasBlanco(1);

}
