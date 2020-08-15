/*
 *  MLibroVend.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
 */

#ifndef MLIBROVEND_H_
#define MLIBROVEND_H_
#include <string>
using namespace std;

class MLibroVend
{

private:

	//Definici�n de atributos
	string codigoVend;
	int dia, metPago;

public:

	//Constructor
	MLibroVend();

	//Set's y Get's respectivos
	void setCodigoVend(string c);
	string getCodigoVend();
	void setDia(int d);
	int getDia();
	void setMetPago(int m);
	int getMetPago();

	//M�todos de c�lculo
	string nombreDia();
	string nombrePago();

};

#endif /* MLIBROVEND_H_ */
