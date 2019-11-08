/**
  *
  * @file pila_max.cpp
  * @brief Implementación del TDA Pila_max
  *
  */

#include <cassert>
#include <iostream>
#include "pila_max.h"

using namespace std;

/* _________________________________________________________________________ */

template <class T>
Pila_max<T>::Pila_max ( const Pila_max<T> & original ) {
	elementos = original.elementos;
	maximo = original.maximo;
}

/* _________________________________________________________________________ */

template <class T>
Pila_max<T> & Pila_max<T>::operator= ( const Pila_max<T> & otra ) {
	elementos = otra.elementos;
	maximo = otra.maximo;
	return *this;
}

/* _________________________________________________________________________ */

template <class T>
bool Pila_max<T>::empty () const {
	return elementos.vacia();
}

/* _________________________________________________________________________ */

template <class T>
int Pila_max<T>::size () const {
	return elementos.num_elementos();
}

/* _________________________________________________________________________ */

template <class T>
Pareja<T> Pila_max<T>::top () {
	assert( elementos.num_elementos() > 0 );
	return elementos.frente();
}

/* _________________________________________________________________________ */

template <class T>
const Pareja<T> & Pila_max<T>::top () const {
	assert( elementos.num_elementos() > 0 );
	return elementos.frente();
}

/* _________________________________________________________________________ */

template <class T>
void Pila_max<T>::push ( const T & nuevo ) {
	if( elementos.num_elementos() > 0 ) {
		Cola<Pareja<T>> aux = elementos;

		while( !elementos.vacia() )
			elementos.quitar();

		if( nuevo > maximo )
			maximo = nuevo;

		elementos.poner( Pareja<T>( nuevo, maximo ) );

		while( !aux.vacia() ) {
			elementos.poner( aux.frente() );
			aux.quitar();
		}

	} else {
		Pareja<T> nueva( nuevo, nuevo );
		elementos.poner( nueva );
	}
}


/* _________________________________________________________________________ */

template <class T>
void Pila_max<T>::pop () {
	if( elementos.num_elementos() > 0 )
		elementos.quitar();
}

/* _________________________________________________________________________ */

template <class T>
ostream & operator<< ( ostream & os, const Pila_max<T> & p ) {
	Cola<Pareja<T>> aux = p.elementos;

	while( !aux.vacia() ){
		cout << aux.frente();
		aux.quitar();
	}

	return os;
}