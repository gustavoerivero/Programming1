/*
 *  VArea.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#ifndef VAREA_H_
#define VAREA_H_
#include "VGeneral.h"
#include <vector>

class VArea: public VGeneral
{
public:

	//Constructor
	VArea();

	//Listado de Libros disponibles
	void listadoLibros(vector<string> codigoLibro, vector<string> nombreLibro, vector<float> precioLibro);

};

#endif /* VAREA_H_ */
