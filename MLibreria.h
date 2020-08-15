/*
 *  MLibreria.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
 */

#ifndef MLIBRERIA_H_
#define MLIBRERIA_H_
#include "MArea.h"

class MLibreria
{

private:

	//Definici�n de atributos
	vector<MArea> vecAreas;
	vector<float> vecMontoAreas;

public:

	//Constructor
	MLibreria();

	//M�todos del vector vecAreas
	void setVecAreas(int i, MArea area);
	MArea getVecAreas(int i);
	void incluirArea(MArea area);
	int cantAreas();

	//M�todos del vector vecMontoAreas
	void setVecMontoAreas(int pos, float monto);
	float getVecMontoAreas(int pos);
	void incluirMontoArea(float monto);
	int cantMontoAreas();
	void actualizarMontoArea(int pos, float monto);

	//B�squeda de libro en �reas
	int busquedaLibroEnAreas(string cod);

	//Inclusi�n de libro en �rea espec�fica
	void inclusionLibro(int posArea, MLibro lib);

	//M�todos de c�lculo
	void generarAreas(vector<string> &nombreArea);
	void generarMontosTotales(vector<float> &montoArea);
	float montoTotalVendido();

};

#endif /* MLIBRERIA_H_ */
