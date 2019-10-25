/**
  *
  * @file Mi_Fecha_Historica.h
  * @brief Fichero de cabecera del TDA Mi_Fecha_Historica
  *
  */

#ifndef _MI_FECHA_HISTORICA_
#define _MI_FECHA_HISTORICA_

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/**
  *
  * @brief TDA Mi_Fecha_Historica
  *
  * Una instancia @e c del tipo de datos abstracto @c Mi_Fecha_Historica es un objeto
  * con cuatro campos: tres enteros y un vestor de Strings.
  *
  * Uno de los enteros es la fecha base del conjunto de eventos y los otros dos son la base
  * del vector dinámico que representamos como:
  *
  * Año
  * Número de eventos
  * Evento/s:
  *   - Evento_1
  *   - Evento_2
  *   - ...
  *   - Evento_N
  *
  * Un ejemplo de su uso:
  * @include pruebamicronologia.cpp
  *
  * @author Juan Francisco Díaz Moreno
  * @date Octubre de 2019
  *
  */

class Mi_Fecha_Historica {

private:
	/**
	  *
	  * @page repConjunto Rep del TDA Mi_Fecha_Historica
	  *
	  * @section invConjunto Invariante de la representación
	  *
	  * El invariante es \e rep.anio >= -9999 && rep.anio <= 9999
	  *
	  * Fijamos como límite que los años no sean ni menores de 9999 ni superiores a 9999.
	  *
	  * @section faConjunto Función de abstracción
	  *
	  * Un objeto válido @e rep del TDA Mi_Fecha_Historica representa al valor
	  *
	  * Año
	  * Número de eventos
	  * Evento/s:
	  *   - Evento_1
	  *   - ...
	  *   - Evento_N
	  *
	  */

	int anio;				/**< Año */
	int num_eventos;		/**< Número de eventos históricos almacenados en este Año */
	int reservados;			/**< Número de elementos reservados */
	string *eventos;		/**< Vector de Strings que almacena los eventos históricos */

	void resize( int r );	/**< Función privada para gestionar el vector dinámico de Strings */

public:

	/**
	  *
	  * @brief Constructor por defecto de la clase Crea una fecha histórica por defecto con año 0, con
	  * el vector nulo y 0 num_eventos y reservados
	  */
	Mi_Fecha_Historica();

	/**
	  *
	  * @brief Constructor de la clase.
	  * @param a Año del evento a construir.
	  * @param n Número de eventos que contiene el vector s
	  * @param s Vector de Strings con los eventos de ese año.
	  * @return Crea Mi_Fecha_Hitorica con año a y n eventos asociados.
	  * @pre a debe ser >= -9999 y <=9999.
	  *
	  */
	Mi_Fecha_Historica( int a, int n, string *s );

	/**
	  *
	  * @brief Constructor de copia de la clase.
	  * @param f Objeto de la clase que se quiere copiar.
	  * @return Crea Mi_Fecha_Historica con los datos de f.
	  *
	  */
	Mi_Fecha_Historica( const Mi_Fecha_Historica & f );

	/**
	  *
	  * @brief Destructor de la clase. Hace un delete del vector de Strings.
	  *
	  */
	~Mi_Fecha_Historica() {
		anio = reservados = num_eventos = 0;
		delete[] eventos;
	}

	/**
	  *
	  * @brief Operador de suma.
	  * @param f Mi_Fecha_Historica que sumar a this.
	  * @return Suma de las Mi_Fecha_Historica.
	  * @pre anio == f.anio
	  *
	  */
	const Mi_Fecha_Historica & operator+( const Mi_Fecha_Historica & f );

	/**
	  *
	  * @brief Operador de asignación.
	  * @param f Mi_Fecha_Hitorica que asignar a this.
	  * @return this
	  *
	  */
	Mi_Fecha_Historica & operator=( const Mi_Fecha_Historica & f );

	/**
	  *
	  * @brief Método de acceso al Año de Mi_Fecha_Historica
	  * @return int con el valor del campo anio.
	  *
	  */
	int getAnio();

	/**
	  *
	  * @brief Añade un evento.
	  * @param nuevo_evento String con el evento a añadir.
	  *
	  */
	void aniadeEvento( string & nuevo_evento );

	/**
	  *
	  * @brief Salida de un Mi_Fecha_Historica a ostream.
	  * @param os Stream de salida.
	  * @param f Mi_Fecha_Historica a escribir.
	  * @post Se muestra f en formato "anio#num_eventos#evento1#evento2#...#eventoN"
	  *
	  */
	friend ostream & operator<< ( ostream & os, const Mi_Fecha_Historica & f );

	/**
	  *
	  * @brief Entrada de un Mi_Fecha_Historica desde istream
	  * @param is Stream de entrada.
	  * @param f Mi_Fecha_Historica que recibe el valor.
	  * @retval El Mi_Fecha_Historica leído en f.
	  * @pre La entrada tiene el formato "anio#num_eventos#evento1#...#eventoN"
	  *
	  */
	friend istream & operator>> ( istream & is, Mi_Fecha_Historica & f );
};

#endif