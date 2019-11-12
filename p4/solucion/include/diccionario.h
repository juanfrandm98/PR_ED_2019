/**
  *
  * @file diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  * Gestiona una secuencia de elementos ordenador de menor a mayor, cada uno de
  * los cuales tiene una información asociada.
  *
  */

#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <iostream>
#include <string>
#include <list>

using namespace std;

/* 
   Tipo de elemento gestionado por el diccionario. T es el tipo de dato asociado
   a una clave que no se repite y list<U> es una lista de datos asociados a dicha
   clave de tipo T.
*/
template <class T, class U>
struct data {
	T clave;
	list<U> info_asociada;
};

/*
   Comparador de data. Ordena 2 registros de acuerdo a la clave de tipo T.
*/
template <class T, class U>
bool operator< ( const data<T,U> & d1, const data<T,U> & d2 ) {
	if( d1.clave < d2.clave )
		return true;
	else
		return false;
}

/**
  *
  * @brief T.D.A. Diccionario
  *
  * Una instancia @e v del tipo de dato abstracto Diccionario sobre dos tipos
  * @c T y @c U es una lista de elementos <T,U>. El primer valor de dichos
  * elementos no puede repetirse, y los elementos están ordenados de menor a
  * mayor en función de dicho valor.
  *
  * Un Diccionario con @e n elementos lo denotaremos:
  *
  * - [<a1<b1,c1>>,<a2<b2,c2>>,<a3<b3,c3>>,...,<an<bn,cn>>]
  *
  * donde @e ai es el elemento de la posición i-ésima formado por @e bi (su
  * clave) y @e ci, su información asociada.
  *
  * Si @e n == 0, diremos que el diccionario está vacío.
  *
  * @author Juan Francisco Díaz Moreno
  * @date Noviembre 2019
  *
  */

template <class T, class U>
class Diccionario {

private:

	list< data<T,U> > datos;

	// Copia un diccionario en otro
	void Copiar ( const Diccionario<T,U> & D ) {
		datos.assign( D.datos.begin(), D.datos.end() );
	}

	// Elimina todos los elementos de un diccionario
	void Borrar () {
		this->datos.erase( datos.begin(), datos.end() );
	}

public:

	// -------------------- Constructores -------------------- //

	/**
	  *
	  * @brief Constructor por defecto
	  *
	  */
	Diccionario() : datos( list< data<T,U> >() ) {}

	/**
	  *
	  * @brief Constructor de copia
	  * @param D Diccionario que se va a copiar
	  *
	  */
	Diccionario( const Diccionario & D ) {
		Copiar( D );
	}

	/**
	  *
	  * @brief Destructor
	  *
	  */
	~Diccionario() {}

	/**
	  *
	  * @brief Busca una clave en el Diccionario.
	  * @param clave Clave a buscar.
	  * @param it_out Si la clave existe, dejará este iterador apuntando al sitio
	  * donde está. Si no existe, lo deja en end().
	  * @return Devuelve true si encuentra la clave y false si no.
	  *
	  */
	bool esta_clave( const T & clave, iterator it_out );

	/**
	  *
	  * @brief Inserta una nueva clave junto a su información asociada.
	  * @param clave Clave a insertar.
	  * @param info Información asociada a la nueva clave.
	  *
	  */
	void insertar( const T & clave, const list<U> & info );

	/**
	  *
	  * @brief Añade información asociada a una clave que está en el Diccionario.
	  * Si la clave no está, la añade también.
	  * @param clave Clave cuya información quiere insertarse.
	  * @param info Información que quiere añadirse.
	  *
	  */
	void add_significado_palabra( const T & clave, const U & info );

	/**
	  *
	  * @brief Devuelve una lista con la información asociada a una clave
	  * @param clave Clave cuya información quiere devolverse.
	  *
	  */
	list<U> get_info_asoc( const T & clave );

	/**
	  *
	  * @brief Devuelve el tamaño del diccionario.
	  *
	  */
	int size() const {
		return datos.size();
	}

	/**
	  *
	  * @brief Clase para iterar sobre el Diccionario
	  *
	  */
	class iterator {
	private:
		list< data<T,U> >::iterator it;
	
	public:

		iterator & operator++ () {
			++it;
		}

		iterator & operator-- () {
			--it;
		}

		data<T,U> & operator* () {
			return *it;
		}

		bool operator== ( const iterator & i ) {
			return i.it = it;
		}

		bool operator!= ( const iterator & i ) {
			return i.it != it;
		}

		friend class Diccionario;
	};

	/**
	  *
	  * @brief Inicializa un iterador al comienzo del Diccionario
	  *
	  */
	iterator begin();

	/**
	  *
	  * @brief Inicializa un iterador al final del Diccionario
	  *
	  */
	iterator end();

};

#endif;