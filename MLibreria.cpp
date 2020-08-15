/*
 *  MLibreria.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
 */

#include "MLibreria.h"

//Constructor

MLibreria::MLibreria()
{
	//Ciclo para crear vector de monto vendido por �rea
	for(int i=0; i<8; i++)
		vecMontoAreas.push_back(0);
}

//M�todos del vector Areas

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

//M�todos del vector MontoAreas

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

//M�todo que permite actualizar el monto vendido de cada �rea

void MLibreria::actualizarMontoArea(int pos, float monto)
{
	vecMontoAreas[pos-1] += monto;
}

//Inclusi�n de Libro en �rea espec�fica
void MLibreria::inclusionLibro(int posArea, MLibro lib)
{
	for(int i = 0; i<cantAreas(); i++)
	{
		if(posArea - 1 == i)
			vecAreas[i].incluirLibro(lib);
	}
}

//M�todos de c�lculo

float MLibreria::montoTotalVendido()
{

	//Declaraci�n de variable local e iniciaci�n en '0'
	float acum = 0;

	//Ciclo para acumular el monto total vendido por la Librer�a
	for(int i = 0; i<cantAreas(); i++)
		acum += vecMontoAreas[i];

	//Retorno del monto total vendido por la librer�a
	return acum;
}

void MLibreria::generarAreas(vector<string> &nombreArea)
{

	//Ciclo que crea una lista con los nombres de �reas existentes
	for(int i = 0; i<cantAreas(); i++)
		nombreArea.push_back(vecAreas[i].getNombreArea());

}

void MLibreria::generarMontosTotales(vector <float> &montoArea)
{

	//Ciclo que crea una lista con los montos vendidos de cada �rea
	for(int i = 0; i<cantAreas(); i++)
		montoArea.push_back(vecMontoAreas[i]);
}
