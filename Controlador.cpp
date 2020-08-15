/*
 *  Controlador.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: �Prot�ico indefinido!
 */

#include "Controlador.h"

//Constructor

Controlador::Controlador()
{

	//Inicializaci�n de variables
	cargaAreas = false;
	cargaLibros = false;
	cargaGeneral = false;
	proceso = false;

}

//M�todos que dan resoluci�n al programa

void Controlador::cargaDatos()
{

	//Definici�n de archivos de entrada
	char archAreas[128], archLibros[128];
	ifstream entradaAreas, entradaLibros;

	//Definici�n de atributos de lectura de Area
	string nombreArea;

	//Definici�n de atributos de lectura de Libro
	string codigo, titulo;
	float costo;
	int NArea;

	//Encabezado de la opci�n
	vlib.encabezado("CARGAR ARCHIVOS");

	//Validaci�n del proceso de carga de archivos de �reas y de Libros
	if(!cargaGeneral)
	{

		//Validaci�n con el proceso de carga de archivo de �reas
		if(!cargaAreas)
		{

			vlib.subTitulo("CARGANDO ARCHIVO DE �REAS");

			vlib.LeerNombreArchivo("\nIngrese el nombre del archivo: ", archAreas);

			//Error: El archivo no existe
			if(!vlib.AbrirArchivoEntrada(entradaAreas, archAreas))
				vlib.error("No existe el archivo mencionado.");

			//Error: Archivo incorrecto para el funcionamiento del programa
			nombreArea = vlib.LeerLineaArchivo(entradaAreas);
			if(vlib.FinArchivo(entradaAreas))
				vlib.error("Archivo incorrecto.");

			//Ciclo de lectura "Archivo de �reas"
			while(!vlib.FinArchivo(entradaAreas))
			{

				area.setNombreArea(nombreArea);

				mlib.incluirArea(area);

				nombreArea = vlib.LeerLineaArchivo(entradaAreas);
			}

			vlib.ImprimirMensaje("\n�Archivo de �reas cargado con exito!");
			vlib.ImprimirLineasBlanco(2);
			vlib.Pausa();

			//Validado el proceso de carga de archivo de �reas
			cargaAreas = true;

			vlib.CerrarArchivoEntrada(entradaAreas);

		}

		//El archivo de �reas ya fue cargado
		else
		{
			vlib.ImprimirMensaje("\nEl archivo de �reas ya ha sido cargado.");
			vlib.ImprimirLineasBlanco(2);
			vlib.Pausa();
		}


		//Validaci�n con el proceso de carga de archivo de Libros
		if(!cargaLibros)
		{
			//Carga de archivo de Libros
			vlib.subTitulo("CARGANDO ARCHIVO DE LIBROS");

			vlib.LeerNombreArchivo("\nIngrese el nombre del archivo: ", archLibros);

			//Error: El archivo no existe
			if(!vlib.AbrirArchivoEntrada(entradaLibros, archLibros))
				vlib.error("No existe el archivo mencionado.");

			//Error: Archivo incorrecto para el funcionamiento del programa
			codigo = vlib.LeerLineaArchivo(entradaLibros);
			if(vlib.FinArchivo(entradaLibros))
				vlib.error("Archivo incorrecto.");

			//Ciclo de lectura "Archivo de �reas"
			while(!vlib.FinArchivo(entradaLibros))
			{

				titulo = vlib.LeerLineaArchivo(entradaLibros);
				costo = vlib.LeerDatoNroDecimalArchivo(entradaLibros);
				NArea = vlib.LeerDatoNroArchivo(entradaLibros);

				libro.setCodigo(codigo);
				libro.setTitulo(titulo);
				libro.setPrecio(costo);
				libro.setArea(NArea);

				//M�todo que incluye el libro en el �rea correspondiente
				mlib.inclusionLibro(NArea, libro);

				codigo = vlib.LeerLineaArchivo(entradaLibros);
			}

			vlib.ImprimirMensaje("\n�Archivo de Libros cargado con exito!");
			vlib.ImprimirLineasBlanco(2);
			vlib.Pausa();

			//Validado el proceso de carga de archivo de Libros
			cargaLibros = true;

			vlib.CerrarArchivoEntrada(entradaLibros);

		}

		//El archivo de Libros ya fue cargado
		else
		{
			vlib.ImprimirMensaje("\nEl archivo de Libros ya ha sido cargado.");
			vlib.ImprimirLineasBlanco(2);
			vlib.Pausa();
		}


		//Validado el proceso de carga de ambos archivos
		if(cargaAreas && cargaLibros)
			cargaGeneral = true;

	}

	//Los archivos necesarios para el funcionamiento del programa ya han sido cargados
	else
	{
		vlib.ImprimirMensaje("\nLos archivos ya han sido cargados.");
		vlib.ImprimirLineasBlanco(2);
		vlib.Pausa();
	}

}

void Controlador::procesarVenta()
{

	//Definici�n de clases
	MPersona per;
	MLibroVend libroV;
	VLibroVend vlibroV;
	VLibro vlibro;
	VArea varea;

	//Definici�n de atributos de MPersona
	string ced;

	//Definici�n de atributos de MLibroVend
	string codV;
	int dia, metP;

	//Definici�n de atributos para impresi�n de venta
	string nombreDia, nombreMetP, nombreLibr, nombrArea;

	//Definici�n de vectores a utilizar
	vector<string> auxCod, auxTit, auxArea;
	vector<float> auxPrecio;

	//Definici�n de atributos propios del m�todo
	int nArea, posL, resp1, resp2;
	float monto, descuento, precioV;


	//Encabezado de la opci�n
	vlib.encabezado("PROCESAR VENTAS");

	//Validaci�n de la carga de archivos
	if(cargaGeneral)
	{
		do
		{
			ced = vlib.LeerString("\nIngrese la c�dula del cliente: ");
			per.SetCedula(ced);

    		dia = vlibroV.LeerValidarNro("\n\nD�a que se hizo la compra"
    								   	 "\n(1) Lunes"
    								   	 "\n(2) Martes"
    								   	 "\n(3) Mi�rcoles"
    								   	 "\n(4) Jueves"
    								  	 "\n(5) Viernes"
    								  	 "\n(6) S�bado"
    								   	 "\nIngrese un valor: ",1,6);

    		metP = vlibroV.LeerValidarNro("\n\nM�todo de pago"
    								   	 "\n(1) D�bito"
    								   	 "\n(2) Cr�dito"
    								   	 "\n(3) Transferencia"
    								   	 "\nIngrese un valor: ",1,3);

    		do
    		{

    			//Limpieza del vector auxArea
    			auxArea.clear();

    			//Dar origen al vector auxArea
    			mlib.generarAreas(auxArea);

    			//Listado de �reas
    			vlib.listadoAreas(auxArea);

    			nArea = vlibroV.LeerValidarNro("\nIngrese un �rea: ", 1, 8);

    			//Limpieza de vectores auxCod, auxTit, auxPrecio
    			auxCod.clear();
    			auxTit.clear();
    			auxPrecio.clear();

    			//Dar origen a los vectores auxCod, auxTit, auxPrecio
    			mlib.getVecAreas(nArea - 1).generarListadoLibros(auxCod, auxTit, auxPrecio);

    			//Listado de libros disponibles en el �rea espec�fica
    			varea.listadoLibros(auxCod, auxTit, auxPrecio);

    			codV = vlibroV.LeerString("\nC�digo del libro que desea comprar: ");

    			libroV.setDia(dia);
    			libroV.setMetPago(metP);
    			libroV.setCodigoVend(codV);

    			//Verificaci�n de existencia del libro indicado
    			posL = mlib.getVecAreas(nArea - 1).buscarLibro(codV);

    			//Libro no existente
    			if(posL == -1)
    				vlib.error("Libro no encontrado.");

    			//Libro existente
    			else
    			{

    				//Definici�n de variables para simplificar el reporte
    				nombreDia = libroV.nombreDia();
    			    nombreMetP = libroV.nombrePago();

    			    nombreLibr = mlib.getVecAreas(nArea - 1).getVecLibros(posL).getTitulo();
    			    nombrArea = mlib.getVecAreas(nArea - 1).getNombreArea();

    			    monto = mlib.getVecAreas(nArea - 1).getVecLibros(posL).getPrecio();
    			    descuento = mlib.getVecAreas(nArea - 1).getVecLibros(posL).calDescuento();
    			    precioV = mlib.getVecAreas(nArea - 1).getVecLibros(posL).calPrecioVenta();

    			    //M�todo que acumula por �rea los montos vendidos
    			    mlib.actualizarMontoArea(nArea, precioV);

    			    //Reporte tipo factura del libro vendido
    			    vlibroV.reporteVenta(ced, nombreDia, nombreMetP, codV, nombreLibr, nombrArea, monto, descuento, precioV);

    			    //Opci�n: Otra compra
    			    resp1 = vlib.LeerValidarNro("\n�Desea realizar otra compra?"
							   	   	   	   	    "\n(1) Si."
							   	   	   	   	    "\n(2) No."
							   	   	   	   	    "\nIngrese un valor: ", 1, 2);

    			    //El reporte de la Librer�a ya est� disponible para su visualizaci�n
    			    proceso = true;

    			}

    		}

    		while (resp1 == 1);

    		//Opci�n: Procesar otro cliente
    		resp2 = vlib.LeerValidarNro("\n�Desea procesar a otro cliente?"
									   	"\n(1) Si."
									    "\n(2) No."
									    "\nIngrese un valor: ", 1, 2);
		}
		while (resp2 == 1);

	}

	//Error en validaci�n de la carga de archivos
	else
		vlib.error("No se han cargado los datos necesarios.");

}

void Controlador::reporteEstadistico()
{

	//Definici�n de vectores a utilizar
	vector<string> auxAreas;
	vector<float> auxMontoArea;

	//Encabezado de la opci�n
	vlib.encabezado("REPORTE ESTAD�STICO");

	//Verificaci�n del proceso de carga de archivos
	if(cargaGeneral)
	{

		//Verificaci�n del proceso de venta
		if(proceso)
		{

			//Limpieza de los vectores auxAreas, auxMontoArea
			auxAreas.clear();
			auxMontoArea.clear();

			//Dar origen a ambos vectores por separado
			mlib.generarAreas(auxAreas);
			mlib.generarMontosTotales(auxMontoArea);

			//Reporte de la librer�a
			vlib.reporteLibreria(auxAreas, auxMontoArea, mlib.montoTotalVendido());
		}

		//Error: No se ha procesado ninguna venta
		else
			vlib.error("No se han procesado los datos necesarios.");

	}

	//Error: No se han cargado los archivos necesarios
	else
		vlib.error("No se han cargado los datos necesarios.");

}
