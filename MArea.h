/*
 *  MArea.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
 */


#ifndef MAREA_H_
#define MAREA_H_
#include "MLibro.h"
#include <vector>

class MArea
{

private:

	//Definici�n de atributos
	string nombreArea;
	vector<MLibro> vecLibros;

public:

	//Constructor
	MArea();

	//Set's y Get's correspondientes
	void setNombreArea(string n);
	string getNombreArea();

	//M�todos com�nes del vector
	void setVecLibros(int i, MLibro lib);
	MLibro getVecLibros(int i);
	void incluirLibro(MLibro lib);
	int cantLibros();
	int buscarLibro(string cod);
	void eliminarArea();

	//M�todos de c�lculo
	void generarListadoLibros(vector<string> &codigo, vector<string> &titulo, vector<float> &precio);

};

#endif /* MAREA_H_ */
