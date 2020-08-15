/*
 *  VLibroVend.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
 */

#include "VLibroVend.h"

//Constructor

VLibroVend::VLibroVend()
{

}

//Reporte tipo factura

void VLibroVend::reporteVenta(string ced, string dia, string formaPago, string cod, string libro, string area, float monto, float descuento, float precioVenta)
{

	//Datos de la compra

	ImprimirString("\nC�dula del Cliente: ", ced);
	ImprimirString("\nD�a de la compra: ", dia);
	ImprimirString("\nForma de pago: ", formaPago);

	ImprimirLineasBlanco(1);

	ImprimirMensaje("\n - DATOS DEL LIBRO - ");

	ImprimirLineasBlanco(1);

	//Datos del libro comprado

	ImprimirString("\nC�digo: ", cod);
	ImprimirString("\nNombre: ", libro);
	ImprimirString("\n�rea: ", area);
	ImprimirNroDecimal("\nPrecio: ", monto);
	ImprimirNroDecimal("\nDescuento por �rea: ", descuento);
	ImprimirNroDecimal("\nMonto Total: ", precioVenta);

	ImprimirLineasBlanco(2);

	Pausa();

}
