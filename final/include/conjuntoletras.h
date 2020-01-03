	/**
  *
  * @file conjuntoletras.h
  * @brief Fichero cabecera del TDA ConjuntoLetras
  *
  */

#ifndef __CONJUNTOLETRAS_H__
#define __CONJUNTOLETRAS_H__

#include <iostream>
#include <set>
#include "letra.h"

using namespace std;

/**
  *
  * @brief T.D.A. ConjuntoLetras
  *
  * Una instancia @e c del tipo de datos abstracto @c ConjuntoLetras es un
  * objeto con un conjunto de Letras que permite trabajar con ellas.
  *
  * @Author Juan Francisco Díaz Moreno
  * @Date Diciembre 2019
  *
  */
class ConjuntoLetras {

private:

	set<Letra> letras;

	// Copia un conjunto de letras en otro.
	void copiar( const ConjuntoLetras & C ) {
		borrar();
		letras.insert( C.letras.begin(), C.letras.end() );
	}

	// Elimina todos los elementos de un conjunto de letras.
	void borrar() {
		letras.erase( letras.begin(), letras.end() );
	}

public:

	/**
	  *
	  * @brief Constructor por defecto.
	  * 
	  */
	ConjuntoLetras(){}

	/**
	  *
	  * @brief Constructor de copia.
	  * @param C Conjunto de letras que se va a copiar.
	  *
	  */
	ConjuntoLetras( const ConjuntoLetras & C );

	/**
	  *
	  * @brief Constructor con parámetros.
	  * @param conjunto Set de letras.
	  *
	  */
	ConjuntoLetras( const set<Letra> & conjunto );

	/**
	  *
	  * @brief Destructor de la clase.
	  *
	  */
	~ConjuntoLetras(){}

	/**
	  *
	  * @brief Setter de las letras.
	  * @param conjunto Set de letras.
	  *
	  */
	void setLetras( const set<Letra> & conjunto );

	/**
	  *
	  * @brief Getter de las letras.
	  *
	  */
	set<Letra> getLetras();

	/**
	  *
	  * @brief Devuelve el tamaño del conjunto de letras.
	  * @return Tamaño del conjunto de letras.
	  *
	  */
	int size();

	/**
	  *
	  * @brief Devuelve la letra con mejor puntuación.
	  * @return Letra con mayor puntuación.
	  *
	  */
	char mejorLetra();

	/**
	  *
	  * @brief Devuelve la puntuación de una letra.
	  * @param letra Letra cuya puntuación se quiere conocer.
	  * @return Puntuación de la letra dada o -1 si no se encuentra.
	  *
	  */
	int puntosLetra( const char & letra );

	/**
	  *
	  * @brief Inserta una nueva letra en el conjunto de letras.
	  * @param L Letra a insertar.
	  *
	  */
	void insertarLetra( const Letra & L );

	/**
	  *
	  * @brief Operador de asignación.
	  * @param C ConjuntoLetras a asignar.
	  * @return ConjuntoLetras asignado.
	  *
	  */
	ConjuntoLetras & operator= ( const ConjuntoLetras & C );

	/**
    *
    * @brief Salida de un ConjuntoLetras a ostream.
    * @param os Stream de salida.
    * @param C ConjuntoLetras a escribir.
    * @post Se obtiene el ConjuntoLetras con el formato adecuado.
    *
    */
	friend ostream & operator<< ( ostream & os, ConjuntoLetras & C );

	/**
	*
	* @brief Entrada de un ConjuntoLetras desde istream.
	* @param is Stream de entrada.
	* @param C ConjuntoLetras en el que se escribe.
	* @retval El ConjuntoLetras leído.
	* @pre La entrada tiene el siguiente formato:
	*		 Número de letras
	*        Letra Puntos Repeticiones
	*		 Letra Puntos Repeticiones
	*		 ...
	*
	*/
	friend istream & operator>> ( istream & is, ConjuntoLetras & C );

};

#endif