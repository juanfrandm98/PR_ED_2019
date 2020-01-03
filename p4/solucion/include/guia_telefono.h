/**
  *
  * @file guia_telefono.h
  * @brief Fichero cabecera del TDA Guia_Telefono
  *
  * 
  *
  */

#ifndef __GUIA_TELEFONO__
#define __GUIA_TELEFONO__

#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
  *
  * @brief T.D.A. Guia_Telefono
  *
  * Una instancia @e c del tipo de datos abstracto @c Guia_Telefono es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n,e2n)}
  * ordenados por el primer elemento del par denominado clave. No existen elementos
  * repetidos.
  *
  * @author Juan Francisco Díaz Moreno
  * @date Noviembre 2019
  *
  */

class Guia_Telefono {

	/**
	  *
	  * @page repGuia_Telefono Rep del TDA Guia_Telefono
	  *
	  * @section invGuia_telefono Invariante de representación
	  *
	  * El invariante es \e para todo \e i y \e j tal que i < j entonces \e eli
	  * y elj son distintos
	  *
	  * @section faGuia_Telefono Función de abstraccion
	  *
	  * Un objeto válido @e rep del TDA Guia_Telefono representa al valor
	  * {(rep.begin().first,rep.begin().second),(rep.begin()+1.frist,rep.begin()+1.second),
	  * ...,(rep.begin()+n-1.first(),rep.begin()+n-1.second)}
	  *
	  */

private:

	map<string,string> datos;

public:

	/**
	  *
	  * @brief Acceso a un elemento
	  * @param nombre Nombre del elemento a acceder
	  * @return Devuelve el valor asociado a un nombre, en este caso, el teléfono
	  *
	  */
	string & operator[] ( const string & nombre );

	/**
	  *
	  * @brief Inserta un nuevo teléfono
	  * @param nombre Clave del nuevo teléfono
	  * @param telefono Teléfono del nuevo elemento
	  * @return Pair donde el first apunta al nuevo elemento insertado y second
	  * es true si se ha podido insertar
	  *
	  */
	pair<map<string,string>::iterator,bool> insertar( const string & nombre,
													  const string & telefono );

	/**
	  *
	  * @brief Inserta un nuevo teléfono
	  * @param nueva_pareja Pareja con el nombre y el teléfono a insertar
	  * @return Pair donde el first apunta al nuevo elemento insertado y second
	  * es true si se ha podido insertar
	  *
	  */
	pair<map<string,string>::iterator,bool> insertar_pareja( const pair<string,string> & nueva_pareja );

	/**
	  *
	  * @brief Borra un teléfono
	  * @param nombre Nombre que se quiere borrar
	  *
	  */
	void borrar( const string & nombre );
}