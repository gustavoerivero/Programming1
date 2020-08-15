/*
 *  Controlador.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_


#include "VLibro.h"
#include "VLibroVend.h"
#include "VArea.h"
#include "VLibreria.h"
#include "MLibroVend.h"
#include "MLibreria.h"
#include "MPersona.h"

class Controlador
{

private:

	//Definici�n de variables para validaciones
	bool cargaAreas, cargaLibros, cargaGeneral, proceso;

	//Definici�n de clases
	MLibreria mlib;
	VLibreria vlib;
	MArea area;
	MLibro libro;

public:

	//Constructor
	Controlador();

	//M�todos que dan resoluci�n al programa
	void cargaDatos();
	void procesarVenta();
	void reporteEstadistico();

};

#endif /* CONTROLADOR_H_ */
