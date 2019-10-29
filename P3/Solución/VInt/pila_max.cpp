/**
  *
  * @file pila_max.cpp
  * @brief Implementación del TDA Pila_max
  *
  */

#include <cassert>

using namespace std;

Pila_max::Pila_max() {
}

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

Pareja & Pila_max::top () {
	assert( elementos.num_elementos() > 0 );
	Cola<Pareja> aux;

	while( !elementos.vacia() ) {
		aux.poner( elementos.frente() );
		elementos.quitar();
	}

	Pareja tope = aux.frente();

	while( !aux.vacia() ) {
		elementos.poner( aux.frente() );
		aux.quitar();
	}

	return tope;
}

/* _________________________________________________________________________ */

const Pareja & Pila_max::top () const {
	cout << "Comienzo top" << endl;
	assert( elementos.num_elementos() > 0 );
	Cola<Pareja> aux1;
	Cola<Pareja> aux2 = elementos;

	cout << elementos.num_elementos() << endl;

	for( int i = 0; i < elementos.num_elementos() - 2; i++ ) {
		cout << i << endl;
		aux1.poner( aux2.frente() );
		aux2.quitar();
	}

	Pareja tope = aux2.frente();

	return tope;
}

/* _________________________________________________________________________ */

void Pila_max::push ( const int & nuevo ) {
	if( nuevo > maximo || elementos.vacia() )
		maximo = nuevo;

	Pareja nueva = Pareja( nuevo, maximo );
	elementos.poner( nueva );
}


/* _________________________________________________________________________ */

void Pila_max::pop () {
	assert( elementos.num_elementos() > 0 );
	Cola<Pareja> aux;

	while( !elementos.vacia() ) {
		aux.poner( elementos. frente() );
		elementos.quitar();
	}

	aux.quitar();

	while( !aux.vacia() ) {
		elementos.poner( aux.frente() );
		aux.quitar();
	}
}