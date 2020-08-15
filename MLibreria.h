/*
 *  MLibreria.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#ifndef MLIBRERIA_H_
#define MLIBRERIA_H_
#include "MArea.h"

class MLibreria
{

private:

	//Definición de atributos
	vector<MArea> vecAreas;
	vector<float> vecMontoAreas;

public:

	//Constructor
	MLibreria();

	//Métodos del vector vecAreas
	void setVecAreas(int i, MArea area);
	MArea getVecAreas(int i);
	void incluirArea(MArea area);
	int cantAreas();

	//Métodos del vector vecMontoAreas
	void setVecMontoAreas(int pos, float monto);
	float getVecMontoAreas(int pos);
	void incluirMontoArea(float monto);
	int cantMontoAreas();
	void actualizarMontoArea(int pos, float monto);

	//Búsqueda de libro en áreas
	int busquedaLibroEnAreas(string cod);

	//Inclusión de libro en área específica
	void inclusionLibro(int posArea, MLibro lib);

	//Métodos de cálculo
	void generarAreas(vector<string> &nombreArea);
	void generarMontosTotales(vector<float> &montoArea);
	float montoTotalVendido();

};

#endif /* MLIBRERIA_H_ */
