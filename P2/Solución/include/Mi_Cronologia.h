/**
  *
  * @file Mi_Cronologia.h
  * @brief Fichero de cabecera del TDA Mi_Cronologia
  *
  */

#ifndef _MI_CRONOLOGIA_
#define _MI_CRONOLOGIA_

#include <iostream>
#include <string>
#include "Mi_Fecha_Historica.h"

using namespace std;

/**
  *
  * @brief TDA Mi_Cronologia
  *
  * Una instancia @e c del tipo de dato abstracto @c Mi_Cronologia es un objeto
  * con tres campos, dos enteros y un vector de objetos de Mi_Fecha_Historica
  * Los dos enteros son utilizados para trabajar con el vector dinámicamente.
  *
  * Lo representamos como:
  * Año_1
  * Número_Eventos_1
  * Eventos_1:
  *    - Evento_1_1
  *    - ...
  *    - Evento_1_M
  *
  * ...
  *
  * Año_N
  * Número_Eventos_N
  * Eventos_N:
  *    - Evento_N_1
  *    - ...
  *    _ Evento_N_M
  *
  * Un ejemplo de uso:
  * @include pruebamicronologia.cpp
  *
  * @author Juan Francisco Díaz Moreno
  * @date Octubre de 2019
  *
  */

class Mi_Cronologia {

private:

	/**
	  *
	  * @page repConjunto Rep del TDA Mi_Cronologia
	  *
	  * @section invConjunto Invariante de la representación
	  *
	  * El invariante está ligado al de Mi_Fecha_Historica \e rep.anio >= -9999 && rep.anio <= 9999
	  *
	  * @section faConjunto Función de abstracción
	  *
	  * Un objeto válido @e rep del TDA Cronología representa al valor:
	  * Año_1
	  * Número_Eventos_1
	  * Eventos_1:
	  *    - Evento_1_1
	  *    - ...
	  *    - Evento_1_M
	  *
	  * ...
	  *
	  * Año_N
	  * Número_Eventos_N
	  * Eventos_N:
	  *    - Evento_N_1
	  *    - ...
	  *    _ Evento_N_M
	  *
	  */

	int num_fechas;					/**< Número de Mi_Fecha_Historica almacenadas */
	int reservados;					/**< Número de elementos reservados */
	Mi_Fecha_Historica *fechas;		/**< Vector de fechas históricas */

	void resize( int r );			/**< Función privada para gestionar el vector dinámico de Mi_Fecha_Historica */
	void ordenar();					/**< Función privada para ordenar las fechas históricas por año */
	int existeFecha( int a );		/**< Función privada que devuelve la posición en fechas de la Mi_Fecha_Historica con ese año (si existe) */

public:

	/**
	  *
	  * @brief Constructor por defecto de la clase. Crea una cronología por defecto con
	  * 0 num_fechas y reservados y un vector nulo.
	  *
	  */
	Mi_Cronologia();

	/**
	  *
	  * @brief Constructor de la clase.
	  * @param f Vector de Mi_Fecha_Historica.
	  * @param n Número de elementos que contiene el vector f.
	  * @return Crea una Mi_Cronologia con n Mi_Fecha_Historica.
	  * @pre n debe ser un número positivo igual al número de objetos contenidos en el vector f.
	  *
	  */
	Mi_Cronologia( Mi_Fecha_Historica *f, int n );

	/**
	  *
	  * @brief Constructor de copia de la clase.
	  * @param c Mi_Cronologia que se quiere copiar.
	  * @return Crea Mi_Cronologia con los datos de c.
	  *
	  */
	Mi_Cronologia( const Mi_Cronologia & c );

	/**
	  *
	  * @brief Destructor de la clase. Hace un delete del vector de Mi_Fecha_Historica.
	  *
	  */
	~Mi_Cronologia() {
		num_fechas = reservados = 0;
		delete[] fechas;
	}

	/**
	  *
	  * @brief Operador de asignación.
	  * @param c Mi_Cronologia a copiar.
	  * @return Mi_Cronologia asignada.
	  *
	  */
	Mi_Cronologia & operator= ( const Mi_Cronologia & c );

	/**
	  *
	  * @brief Añade una Mi_Fecha_Historica a la cronología.
	  * @param f Mi_Fecha_Historica a añadir.
	  *
	  */
	void aniadeFecha( Mi_Fecha_Historica & f );

	/**
	  *
	  * @brief Salida de una Cronologia a ostream.
	  * @param os Stream de salida.
	  * @param c Cronologia a escribir.
	  * @post Se obtienen varias Mi_Fecha_Historica seguidas con su formato correspondiente.
	  *
	  */
	friend ostream & operator<< ( ostream & os, const Mi_Cronologia & c );

	/**
	  *
	  * @brief Entrada de una Cronologia desde istream.
	  * @param is Stream de entrada.
	  * @param c Cronologia leía en c.
	  * @retval La Cronologia leía en c.
	  * @pre La entrada tiene el formato de Mi_Fecha_Historica dividida num_fechas número de veces.
	  *
	  */
	friend istream & operator>> ( istream & is, Mi_Cronologia & c);

};

#endif