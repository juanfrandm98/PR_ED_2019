/**
  *
  * @file pila_max.cpp
  * @brief Implementación del TDA Pila_max
  *
  */

#include <cassert>

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
Pareja<T> & Pila_max<T>::top () {
	assert( elementos.num_elementos > 0 );
	Cola<T> aux;

	while( !elementos.vacia() ) {
		aux.poner( elementos.frente() );
		elementos.quitar();
	}

	Pareja<T> tope = aux.frente();

	while( !aux.vacia() ) {
		elementos.poner( aux.frente() );
		aux.quitar();
	}

	return tope;
}

/* _________________________________________________________________________ */

template <class T>
const Pareja<T> & Pila_max<T>::top () const {
	assert( elementos.num_elementos() > 0 );
	Cola<T> aux;

	while( !elementos.vacia() ) {
		aux.poner( elementos.frente() );
		elementos.quitar();
	}

	Pareja<T> tope = aux.frente();

	while( !aux.vacia() ) {
		elementos.poner( aux.frente() );
		aux.quitar();
	}

	return tope;
}

/* _________________________________________________________________________ */

template <class T>
void Pila_max<T>::push ( const T & nuevo ) {
	if( nuevo > maximo || elementos.vacia() )
		maximo = nuevo;

	Pareja<T> nueva = Pareja<T>( nuevo, maximo );
	elementos.poner( nueva );
}


/* _________________________________________________________________________ */

template <class T>
void Pila_max<T>::pop () {
	assert( elementos.num_elementos() > 0 );
	Cola<T> aux;

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