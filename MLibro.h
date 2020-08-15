/*
 *  MLibro.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#ifndef MLIBRO_H_
#define MLIBRO_H_
#include <string>
using namespace std;

class MLibro
{

private:

	//Definición de atributos
	string codigo, titulo;
	float precio;
	int area;

public:

	//Constructor
	MLibro();

	//Set's y Get's respectivos
	void setCodigo(string c);
	string getCodigo();
	void setTitulo(string t);
	string getTitulo();
	void setPrecio(float p);
	float getPrecio();
	void setArea(int a);
	int getArea();

	//Métodos de cálculo
	float calDescuento();
	float calPrecioVenta();

};

#endif /* MLIBRO_H_ */
