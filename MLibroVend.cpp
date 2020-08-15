/*
 *  MLibroVend.h
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#include "MLibroVend.h"

//Constructor

MLibroVend::MLibroVend()
{

	//Inicialización de atributos numéricos
	dia = 0;
	metPago = 0;

}

//Set's y Get's correspondientes

void MLibroVend::setCodigoVend(string c)
{
	codigoVend = c;
}

string MLibroVend::getCodigoVend()
{
	return codigoVend;
}

void MLibroVend::setDia(int d)
{
	dia = d;
}

int MLibroVend::getDia()
{
	return dia;
}

void MLibroVend::setMetPago(int m)
{
	metPago = m;
}

int MLibroVend::getMetPago()
{
	return metPago;
}

//Métodos de cálculo

string MLibroVend::nombreDia()
{
	//Declaración de variable local
	string nombre;

	//Convierte el valor de la variable "dia" en el string correspondiente
	switch(dia)
	{

	case 1:
		{
			nombre = "Lunes";
			break;
		}

	case 2:
		{
			nombre = "Martes";
			break;
		}

	case 3:
		{
			nombre = "Miércoles";
			break;
		}

	case 4:
		{
			nombre = "Jueves";
			break;
		}

	case 5:
		{
			nombre = "Viernes";
			break;
		}

	case 6:
		{
			nombre = "Sábado";
			break;
		}

	}

	//Retorno del valor string
	return nombre;

}

string MLibroVend::nombrePago()
{
	//Declaración de variable local
	string pago;

	//Convierte el valor int del 'metPago' en su respectivo valor string
	switch(metPago)
	{

	case 1:
		{
			pago = "Débito";
			break;
		}

	case 2:
		{
			pago = "Crédito";
			break;
		}

	case 3:
		{
			pago = "Transferencia";
			break;
		}

	}

	//Retorno del valor string
	return pago;

}
