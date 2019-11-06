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

Pila_max::Pila_max ( const Pila_max & original ) {
	elementos = original.elementos;
	maximo = original.maximo;
}

/* _________________________________________________________________________ */

Pila_max & Pila_max::operator= ( const Pila_max & otra ) {
	elementos = otra.elementos;
	maximo = otra.maximo;
	return *this;
}

/* _________________________________________________________________________ */

bool Pila_max::empty () const {
	return elementos.vacia();
}

/* _________________________________________________________________________ */

int Pila_max::size () const {
	return elementos.num_elementos();
}

/* _________________________________________________________________________ */

Pareja Pila_max::top () {
	assert( elementos.num_elementos() > 0 );
	return elementos.frente();
}

/* _________________________________________________________________________ */

const Pareja & Pila_max::top () const {
	assert( elementos.num_elementos() > 0 );
	return elementos.frente();
}

/* _________________________________________________________________________ */

void Pila_max::push ( const int & nuevo ) {
	if( elementos.num_elementos() > 0 ) {
		Cola<Pareja> aux = elementos;

		while( !elementos.vacia() )
			elementos.quitar();

		if( nuevo > maximo )
			maximo = nuevo;

		elementos.poner( Pareja( nuevo, maximo ) );

		while( !aux.vacia() ) {
			elementos.poner( aux.frente() );
			aux.quitar();
		}

	} else {
		Pareja nueva( nuevo, nuevo );
		elementos.poner( nueva );
	}
}


/* _________________________________________________________________________ */

void Pila_max::pop () {
	if( elementos.num_elementos() > 0 )
		elementos.quitar();
}

/* _________________________________________________________________________ */

ostream & operator<< ( ostream & os, const Pila_max & p ) {
	Cola<Pareja> aux = p.elementos;

	while( !aux.vacia() ){
		cout << aux.frente();
		aux.quitar();
	}

	return os;
}