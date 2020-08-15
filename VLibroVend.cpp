/*
 *  VLibroVend.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
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

	ImprimirString("\nCédula del Cliente: ", ced);
	ImprimirString("\nDía de la compra: ", dia);
	ImprimirString("\nForma de pago: ", formaPago);

	ImprimirLineasBlanco(1);

	ImprimirMensaje("\n - DATOS DEL LIBRO - ");

	ImprimirLineasBlanco(1);

	//Datos del libro comprado

	ImprimirString("\nCódigo: ", cod);
	ImprimirString("\nNombre: ", libro);
	ImprimirString("\nÁrea: ", area);
	ImprimirNroDecimal("\nPrecio: ", monto);
	ImprimirNroDecimal("\nDescuento por Área: ", descuento);
	ImprimirNroDecimal("\nMonto Total: ", precioVenta);

	ImprimirLineasBlanco(2);

	Pausa();

}
