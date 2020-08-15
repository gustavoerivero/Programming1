/*
 *  VLibreria.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#ifndef VLIBRERIA_H_
#define VLIBRERIA_H_
#include "VGeneral.h"
#include <vector>

class VLibreria: public VGeneral
{
public:

	//Constructor
	VLibreria();

	//Encabezado personalizado
	void encabezado(string enc);

	//Subtítulo personalizado
	void subTitulo(string sub);

	//Mensaje de error personalizado
	void error(string msjError);

	//Listado de Áreas
	void listadoAreas(vector<string> nombreArea);

	//Reporte tipo listado
	void reporteLibreria(vector<string> nombreAreas, vector<float> montoAreas, float montoTotal);

};

#endif /* VLIBRERIA_H_ */
