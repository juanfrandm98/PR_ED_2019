/**
  * @file pila_max.h
  * @brief Fichero cabecera del TDA Pila max
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo.
  *
  */

#ifndef __Pila_max_H__
#define __Pila_max_H__

#include "cola.h"
#include <cassert>

template <class T>
typedef struct {
	T elemento;		// Elemento a almacenar
	T maximo;		// El máximo
} pareja;

ostream & operator<< ( ostream & os, const pareja & p ) {
	os << "Elemento: " << p.elemento << " Máximo: " << p.maximo << endl;
	return os;
}

/**
  *
  * @brief T.D.A. Pila_max
  *
  *
  * Una instancia @e v del tipo de dato abstracto Pila_max sobre un tipo @c T es
  * una lista de pares de elementos <T,T> con un funcionamiento @e LIFO (Last In
  * First Out). En una pila, las operaciones de inserción y borrado de elementos
  * tienen lugar en uno de los extremos denominado @e Tope. Una Pila_max de longitud
  * @e n la denotamos:
  *
  * - [<a1,max{a1...an}>,<a2,max{a2...an}>,<a3,max{a3...an}>,...,<an,an>]
  *
  * donde @e ai es el elemento de la posición i-ésima y @e max{ai...aj} es el máximo
  * del conjunto de * elementos que van desde @e ai hasta @e aj.
  *
  * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es decir,
  * a @e an. El borrado o consulta de un elemento será sobre @e an, y la
  * inserción de un nuevo elemento se hará sobre éste, quedando el elemento
  * insertado como @e Tope de la pila.
  *
  * Si @e n == 0, diremos que la pila está vacía.
  *
  * El espacio requerido para el almacenamiento es O(n), donde n es el número de
  * elementos de la Pila_max.
  *
  * @author Juan Francisco Díaz Moreno
  * @date Octubre 2019
  *
  */

template <class T>
class Pila_max {

	private:

		Cola<pareja> elementos; ///< Cola de elementos

	public:

		// -------------------- Constructores -------------------- //
		/**
		  *
		  * @brief Constructor por defecto
		  *
		  */
		Pila_max() {
		}

		/**
		  *
		  * @brief Constructor de copias
		  * @param original La Pila_max de la que se hará la copia.
		  *
		  */
		Pila_max( const Pila_max<T> & original );

		// -------------------- Destructor -------------------- //
		/**
		  *
		  * @brief Destructor
		  *
		  */
		~Pila_max();

		// -------------------- Funciones -------------------- //
		/**
		  *
		  * @brief Operador de asignación
		  * @param otra La Pila_max que se va a asignar.
		  *
		  */
		Pila_max<T>& operator= ( const Pila_max<T> & otra );

		/**
		  *
		  * @brief Comprueba si la pila está vacía
		  *
		  */
		bool empty() const;

		/**
		  *
		  * @brief Devuelve el tamaño de la pila
		  *
		  */
		int size();

		/**
		  *
		  * @brief Devuelve el elemento del tope de la pila
		  *
		  */
		pareja<T> & top();

		/**
		  *
		  * @brief Devuelve el elemento del tope de la pila constante
		  *
		  */
		const pareja<T> & top() const;

		/**
		  *
		  * @brief Añade un elemento encima del tope de la pila
		  * @param nuevo Elemento que se va a añadir
		  *
		  */
		void push( const T & nuevo );

		/**
		  *
		  * @brief Quita el elemento del tope de la pila
		  *
		  */
		void pop();

};