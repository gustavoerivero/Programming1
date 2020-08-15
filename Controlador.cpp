/*
 *  Controlador.cpp
 *  Creado: 23/05/2018
 *  Autor: Gustavo Rivero
 *  PD: ¡Protéico indefinido!
 */

#include "Controlador.h"

//Constructor

Controlador::Controlador()
{

	//Inicialización de variables
	cargaAreas = false;
	cargaLibros = false;
	cargaGeneral = false;
	proceso = false;

}

//Métodos que dan resolución al programa

void Controlador::cargaDatos()
{

	//Definición de archivos de entrada
	char archAreas[128], archLibros[128];
	ifstream entradaAreas, entradaLibros;

	//Definición de atributos de lectura de Area
	string nombreArea;

	//Definición de atributos de lectura de Libro
	string codigo, titulo;
	float costo;
	int NArea;

	//Encabezado de la opción
	vlib.encabezado("CARGAR ARCHIVOS");

	//Validación del proceso de carga de archivos de Áreas y de Libros
	if(!cargaGeneral)
	{

		//Validación con el proceso de carga de archivo de Áreas
		if(!cargaAreas)
		{

			vlib.subTitulo("CARGANDO ARCHIVO DE ÁREAS");

			vlib.LeerNombreArchivo("\nIngrese el nombre del archivo: ", archAreas);

			//Error: El archivo no existe
			if(!vlib.AbrirArchivoEntrada(entradaAreas, archAreas))
				vlib.error("No existe el archivo mencionado.");

			//Error: Archivo incorrecto para el funcionamiento del programa
			nombreArea = vlib.LeerLineaArchivo(entradaAreas);
			if(vlib.FinArchivo(entradaAreas))
				vlib.error("Archivo incorrecto.");

			//Ciclo de lectura "Archivo de Áreas"
			while(!vlib.FinArchivo(entradaAreas))
			{

				area.setNombreArea(nombreArea);

				mlib.incluirArea(area);

				nombreArea = vlib.LeerLineaArchivo(entradaAreas);
			}

			vlib.ImprimirMensaje("\n¡Archivo de Áreas cargado con exito!");
			vlib.ImprimirLineasBlanco(2);
			vlib.Pausa();

			//Validado el proceso de carga de archivo de Áreas
			cargaAreas = true;

			vlib.CerrarArchivoEntrada(entradaAreas);

		}

		//El archivo de Áreas ya fue cargado
		else
		{
			vlib.ImprimirMensaje("\nEl archivo de Áreas ya ha sido cargado.");
			vlib.ImprimirLineasBlanco(2);
			vlib.Pausa();
		}


		//Validación con el proceso de carga de archivo de Libros
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

			//Ciclo de lectura "Archivo de Áreas"
			while(!vlib.FinArchivo(entradaLibros))
			{

				titulo = vlib.LeerLineaArchivo(entradaLibros);
				costo = vlib.LeerDatoNroDecimalArchivo(entradaLibros);
				NArea = vlib.LeerDatoNroArchivo(entradaLibros);

				libro.setCodigo(codigo);
				libro.setTitulo(titulo);
				libro.setPrecio(costo);
				libro.setArea(NArea);

				//Método que incluye el libro en el área correspondiente
				mlib.inclusionLibro(NArea, libro);

				codigo = vlib.LeerLineaArchivo(entradaLibros);
			}

			vlib.ImprimirMensaje("\n¡Archivo de Libros cargado con exito!");
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

	//Definición de clases
	MPersona per;
	MLibroVend libroV;
	VLibroVend vlibroV;
	VLibro vlibro;
	VArea varea;

	//Definición de atributos de MPersona
	string ced;

	//Definición de atributos de MLibroVend
	string codV;
	int dia, metP;

	//Definición de atributos para impresión de venta
	string nombreDia, nombreMetP, nombreLibr, nombrArea;

	//Definición de vectores a utilizar
	vector<string> auxCod, auxTit, auxArea;
	vector<float> auxPrecio;

	//Definición de atributos propios del método
	int nArea, posL, resp1, resp2;
	float monto, descuento, precioV;


	//Encabezado de la opción
	vlib.encabezado("PROCESAR VENTAS");

	//Validación de la carga de archivos
	if(cargaGeneral)
	{
		do
		{
			ced = vlib.LeerString("\nIngrese la cédula del cliente: ");
			per.SetCedula(ced);

    		dia = vlibroV.LeerValidarNro("\n\nDía que se hizo la compra"
    								   	 "\n(1) Lunes"
    								   	 "\n(2) Martes"
    								   	 "\n(3) Miércoles"
    								   	 "\n(4) Jueves"
    								  	 "\n(5) Viernes"
    								  	 "\n(6) Sábado"
    								   	 "\nIngrese un valor: ",1,6);

    		metP = vlibroV.LeerValidarNro("\n\nMétodo de pago"
    								   	 "\n(1) Débito"
    								   	 "\n(2) Crédito"
    								   	 "\n(3) Transferencia"
    								   	 "\nIngrese un valor: ",1,3);

    		do
    		{

    			//Limpieza del vector auxArea
    			auxArea.clear();

    			//Dar origen al vector auxArea
    			mlib.generarAreas(auxArea);

    			//Listado de Áreas
    			vlib.listadoAreas(auxArea);

    			nArea = vlibroV.LeerValidarNro("\nIngrese un área: ", 1, 8);

    			//Limpieza de vectores auxCod, auxTit, auxPrecio
    			auxCod.clear();
    			auxTit.clear();
    			auxPrecio.clear();

    			//Dar origen a los vectores auxCod, auxTit, auxPrecio
    			mlib.getVecAreas(nArea - 1).generarListadoLibros(auxCod, auxTit, auxPrecio);

    			//Listado de libros disponibles en el área específica
    			varea.listadoLibros(auxCod, auxTit, auxPrecio);

    			codV = vlibroV.LeerString("\nCódigo del libro que desea comprar: ");

    			libroV.setDia(dia);
    			libroV.setMetPago(metP);
    			libroV.setCodigoVend(codV);

    			//Verificación de existencia del libro indicado
    			posL = mlib.getVecAreas(nArea - 1).buscarLibro(codV);

    			//Libro no existente
    			if(posL == -1)
    				vlib.error("Libro no encontrado.");

    			//Libro existente
    			else
    			{

    				//Definición de variables para simplificar el reporte
    				nombreDia = libroV.nombreDia();
    			    nombreMetP = libroV.nombrePago();

    			    nombreLibr = mlib.getVecAreas(nArea - 1).getVecLibros(posL).getTitulo();
    			    nombrArea = mlib.getVecAreas(nArea - 1).getNombreArea();

    			    monto = mlib.getVecAreas(nArea - 1).getVecLibros(posL).getPrecio();
    			    descuento = mlib.getVecAreas(nArea - 1).getVecLibros(posL).calDescuento();
    			    precioV = mlib.getVecAreas(nArea - 1).getVecLibros(posL).calPrecioVenta();

    			    //Método que acumula por área los montos vendidos
    			    mlib.actualizarMontoArea(nArea, precioV);

    			    //Reporte tipo factura del libro vendido
    			    vlibroV.reporteVenta(ced, nombreDia, nombreMetP, codV, nombreLibr, nombrArea, monto, descuento, precioV);

    			    //Opción: Otra compra
    			    resp1 = vlib.LeerValidarNro("\n¿Desea realizar otra compra?"
							   	   	   	   	    "\n(1) Si."
							   	   	   	   	    "\n(2) No."
							   	   	   	   	    "\nIngrese un valor: ", 1, 2);

    			    //El reporte de la Librería ya está disponible para su visualización
    			    proceso = true;

    			}

    		}

    		while (resp1 == 1);

    		//Opción: Procesar otro cliente
    		resp2 = vlib.LeerValidarNro("\n¿Desea procesar a otro cliente?"
									   	"\n(1) Si."
									    "\n(2) No."
									    "\nIngrese un valor: ", 1, 2);
		}
		while (resp2 == 1);

	}

	//Error en validación de la carga de archivos
	else
		vlib.error("No se han cargado los datos necesarios.");

}

void Controlador::reporteEstadistico()
{

	//Definición de vectores a utilizar
	vector<string> auxAreas;
	vector<float> auxMontoArea;

	//Encabezado de la opción
	vlib.encabezado("REPORTE ESTADÍSTICO");

	//Verificación del proceso de carga de archivos
	if(cargaGeneral)
	{

		//Verificación del proceso de venta
		if(proceso)
		{

			//Limpieza de los vectores auxAreas, auxMontoArea
			auxAreas.clear();
			auxMontoArea.clear();

			//Dar origen a ambos vectores por separado
			mlib.generarAreas(auxAreas);
			mlib.generarMontosTotales(auxMontoArea);

			//Reporte de la librería
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
