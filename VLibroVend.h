/*
 *  VLibroVend.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#ifndef VLIBROVEND_H_
#define VLIBROVEND_H_
#include "VGeneral.h"

class VLibroVend: public VGeneral
{
public:

	//Constructor
	VLibroVend();

	//Reporte tipo factura
	void reporteVenta(string ced, string dia, string formaPago, string cod, string libro, string area, float monto, float descuento, float precioVenta);
};

#endif /* VLIBROVEND_H_ */
