/*
 *  MLibro.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#include "MLibro.h"

//Constructor

MLibro::MLibro()
{

	//Inicialización de atributos numéricos
	area = 0;
	precio = 0;

}

//Set's y Get's correspondientes

void MLibro::setCodigo(string c)
{
	codigo = c;
}

string MLibro::getCodigo()
{
	return codigo;
}

void MLibro::setTitulo(string t)
{
	titulo = t;
}

string MLibro::getTitulo()
{
	return titulo;
}

void MLibro::setPrecio(float p)
{
	precio = p;
}

float MLibro::getPrecio()
{
	return precio;
}

void MLibro::setArea(int a)
{
	area = a;
}

int MLibro::getArea()
{
	return area;
}

//Métodos de cálculo

float MLibro::calDescuento()
{

	//Declaración de variable local e iniciación en '0'
	float descuento = 0;

	switch(area)
	{

	//Programación
	case 1:
		{
			descuento = precio * 0.155;
			break;
		}

	//Robótica
	case 2:
		{
			descuento = precio * 0.18;
			break;
		}

	//Redes
	case 3:
		{
			descuento = precio * 0.105;
			break;
		}

	//Inteligencia Artificial
	case 4:
		{
			descuento = precio * 0.12;
			break;
		}

	//Base de Datos
	case 5:
		{
			descuento = precio * 0.07;
			break;
		}

	//Sistemas de Información
	case 6:
		{
			descuento = precio * 0.17;
			break;
		}

	//Sistemas Operativos
	case 7:
		{
			descuento = precio * 0.2;
			break;
		}

	//Software Libre
	case 8:
		{
			descuento = precio * 0.055;
			break;
		}

	}

	//Retorno de la variable local
	return descuento;
}

float MLibro::calPrecioVenta()
{
	//Cálculo del precio de venta que tiene el libro
	return precio - calDescuento();
}
