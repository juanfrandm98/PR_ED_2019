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
#include "pareja.h"
#include <cassert>

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

class Pila_max {

	private:

		Cola<Pareja> elementos; ///< Cola de elementos
		int maximo;				///< Elemento máximo actual

	public:

		// -------------------- Constructores -------------------- //
		/**
		  *
		  * @brief Constructor por defecto
		  *
		  */
		Pila_max() {
			maximo = 0;
		}

		/**
		  *
		  * @brief Constructor de copias
		  * @param original La Pila_max de la que se hará la copia.
		  *
		  */
		Pila_max( const Pila_max & original );

		// -------------------- Destructor -------------------- //
		/**
		  *
		  * @brief Destructor
		  *
		  */
		~Pila_max(){
			maximo = 0;
		}

		// -------------------- Funciones -------------------- //
		/**
		  *
		  * @brief Operador de asignación
		  * @param otra La Pila_max que se va a asignar.
		  *
		  */
		Pila_max & operator= ( const Pila_max & otra );

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
		int size() const;

		/**
		  *
		  * @brief Devuelve el elemento del tope de la pila
		  *
		  */
		Pareja top();

		/**
		  *
		  * @brief Devuelve el elemento del tope de la pila constante
		  *
		  */
		const Pareja & top() const;

		/**
		  *
		  * @brief Añade un elemento encima del tope de la pila
		  * @param nuevo Elemento que se va a añadir
		  *
		  */
		void push( const int & nuevo );

		/**
		  *
		  * @brief Quita el elemento del tope de la pila
		  *
		  */
		void pop();

		friend ostream & operator<< ( ostream & os, const Pila_max & p );

};


#endif // __Pila_max_H__