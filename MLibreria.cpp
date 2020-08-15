/*
 *  MLibreria.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#include "MLibreria.h"

//Constructor

MLibreria::MLibreria()
{
	//Ciclo para crear vector de monto vendido por área
	for(int i=0; i<8; i++)
		vecMontoAreas.push_back(0);
}

//Métodos del vector Areas

void MLibreria::setVecAreas(int i, MArea area)
{
	vecAreas[i] = area;
}

MArea MLibreria::getVecAreas(int i)
{
	return vecAreas[i];
}

void MLibreria::incluirArea(MArea area)
{
	vecAreas.push_back(area);
}

int MLibreria::cantAreas()
{
	return vecAreas.size();
}

//Métodos del vector MontoAreas

void MLibreria::setVecMontoAreas(int pos, float monto)
{
	vecMontoAreas[pos-1] = monto;
}

float MLibreria::getVecMontoAreas(int pos)
{
	return vecMontoAreas[pos-1];
}

void MLibreria::incluirMontoArea(float monto)
{
	vecMontoAreas.push_back(monto);
}

int MLibreria::cantMontoAreas()
{
	return vecMontoAreas.size();
}

//Método que permite actualizar el monto vendido de cada área

void MLibreria::actualizarMontoArea(int pos, float monto)
{
	vecMontoAreas[pos-1] += monto;
}

//Inclusión de Libro en área específica
void MLibreria::inclusionLibro(int posArea, MLibro lib)
{
	for(int i = 0; i<cantAreas(); i++)
	{
		if(posArea - 1 == i)
			vecAreas[i].incluirLibro(lib);
	}
}

//Métodos de cálculo

float MLibreria::montoTotalVendido()
{

	//Declaración de variable local e iniciación en '0'
	float acum = 0;

	//Ciclo para acumular el monto total vendido por la Librería
	for(int i = 0; i<cantAreas(); i++)
		acum += vecMontoAreas[i];

	//Retorno del monto total vendido por la librería
	return acum;
}

void MLibreria::generarAreas(vector<string> &nombreArea)
{

	//Ciclo que crea una lista con los nombres de áreas existentes
	for(int i = 0; i<cantAreas(); i++)
		nombreArea.push_back(vecAreas[i].getNombreArea());

}

void MLibreria::generarMontosTotales(vector <float> &montoArea)
{

	//Ciclo que crea una lista con los montos vendidos de cada área
	for(int i = 0; i<cantAreas(); i++)
		montoArea.push_back(vecMontoAreas[i]);
}
