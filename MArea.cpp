/*
 *  MArea.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */


#include "MArea.h"

//Constructor

MArea::MArea()
{

}

//Set's y Get's correspondientes

void MArea::setNombreArea(string n)
{
	nombreArea = n;
}

string MArea::getNombreArea()
{
	return nombreArea;
}

//Métodos usuales de vector

void MArea::setVecLibros(int i, MLibro lib)
{
	vecLibros[i] = lib;
}

MLibro MArea::getVecLibros(int i)
{
	return vecLibros[i];
}

void MArea::incluirLibro(MLibro lib)
{
	vecLibros.push_back(lib);
}

int MArea::cantLibros()
{
	return vecLibros.size();
}

int MArea::buscarLibro(string cod)
{
	for(int i=0; i<cantLibros(); i++)
	{
		if(cod == vecLibros[i].getCodigo())
			return i;
	}

	return -1;
}

void MArea::eliminarArea()
{
	vecLibros.clear();
}

//Métodos de cálculo

void MArea::generarListadoLibros(vector<string> &codigo, vector<string> &titulo, vector<float> &precio)
{
	//Ciclo que crea una lista con los códigos, títulos y precios de libros
	for(int i = 0; i<cantLibros(); i++)
	{
		codigo.push_back(vecLibros[i].getCodigo());
		titulo.push_back(vecLibros[i].getTitulo());
		precio.push_back(vecLibros[i].getPrecio());
	}
}


