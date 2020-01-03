/**
  *
  * @file diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <iostream>
#include <string>
#include <set>

using namespace std;

/**
  *
  * @brief T.D.A. Diccionario
  *
  * Una instancia @e del tipo de datos abstracto @c Diccionario es un objeto
  * con un conjunto de strings.  Dicho conjunto almacena una serie de strings
  * no repetidos.
  *
  * El TDA proporciona una serie de operaciones para trabajar con los strings
  * y con sus letras, así como un iterador para recorrer el conjunto.
  *
  * @Author Juan Francisco Díaz Moreno
  * @date Diciembre 2019
  *
  */

class Diccionario {

private:

	set<string> datos;

	// Copia un diccionario en otro.
	void copiar( const Diccionario & D ) {
		borrar();
		datos.insert( D.datos.begin(), D.datos.end() );
	}

	// Elimina todos los elementos de un diccionario.
	void borrar() {
		datos.erase( datos.begin(), datos.end() );
	}

public:

	// -------------------- Constructores -------------------- //

	/**
	  *
	  * @brief Constructor por defecto.
	  *
	  */
	Diccionario(){}

	/**
	  *
	  * @brief Constructor de copia.
	  * @param D Diccionario que se va a copiar.
	  *
	  */
	Diccionario( const Diccionario & D ) { copiar(D); }

	/**
	  *
	  * @brief Destructor.
	  *
	  */
	~Diccionario() {}

	/**
	  *
	  * @brief Operador de asignación.
	  * @param D Diccionario a asignar.
	  * @return Diccionario asignado.
	  *
	  */
	Diccionario & operator= ( const Diccionario & D );

	/**
	  *
	  * @brief Operador de suma.
	  * @param D Diccionario a sumar.
	  * @return Suma de Diccionarios.
	  *
	  */
	Diccionario & operator+ ( const Diccionario & D );

	/**
	  *
	  * @brief Añade una nueva palabra al Diccionario.
	  * @param palabra Nueva palabra a añadir.
	  *
	  */
	void aniadirPalabra( const string & palabra );

	/**
	  *
	  * @brief Comprueba si una palabra forma parte del diccionario.
	  * @param palabra Palabra a comprobar.
	  * @return Devuelve true si la palabra está incuida.
	  *
	  */
	bool comprobarPalabra( const string & palabra );

	/**
	  *
	  * @brief Obtiene la contidad de veces que aparece una letra dada.
	  * @param letra Letra cuya frecuencia se quiere calcular.
	  * @return Ńúmero de apariciones de la letra dada.
	  *
	  */
	int frecuenciaLetra( const char & letra );

	/**
	  *
	  * @brief Obtiene el número de letras que hay en el Diccionario
	  * @return Número de letras totales.
	  *
	  */
	int getNumLetras();

	/**
	  *
	  * @brief Iterador sobre la clase Diccionario
	  *
	  */
	class iterator {

	private:

		set<string>::iterator it, final;

	public:

		iterator(){}

		bool operator== ( const iterator & i ) {
			return it == i.it;
		}

		bool operator!= ( const iterator & i ) {
			return it != i.it;
		}

		string operator* () {
			return *it;
		}

		iterator & operator++ () {
			if( it != final )
				++it;
		}

		friend class Diccionario;
	};

	/**
	  *
	  * @brief Construye un iterador que apunta al principio del
	  * set de datos.
	  * @return Iterador constuido.
	  *
	  */
	Diccionario::iterator begin() const;

	/**
	  *
	  * @brief Construye un iterador que apunta al final del set
	  * de datos.
	  * @return Iterador construido.
	  *
	  */
	Diccionario::iterator end() const;

	/**
	  *
	  * @brief Salida de un Diccionario a ostream.
	  * @param os Stream de salida.
	  * @param D Diccionario a escribir.
	  * @post Se obtiene un Diccionario con el formato adecuado.
	  *
	  */
	friend ostream & operator<< ( ostream & os, Diccionario & D );

	/**
	  *
	  * @brief Entrada de un Diccionario desde istream.
	  * @param is Stream de entrada.
	  * @param D Diccionario en el que se escribe.
	  * @retval El Diccionario leído.
	  * @pre La entrada tiene el siguiente formato:
	  *			Palabra1
	  *			Palabra2
	  *			...
	  *
	  */
	friend istream & operator>> ( istream & is, Diccionario & L );
};

#endif