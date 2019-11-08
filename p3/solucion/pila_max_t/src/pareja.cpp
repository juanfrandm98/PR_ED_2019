#include <iostream>
#include "pareja.h"

using namespace std;

template <class T>
Pareja<T>::Pareja( const T & elem, const T & max ){
	elemento = elem;
	maximo = max;
}

template <class T>
Pareja<T> & Pareja<T>::operator=( const Pareja<T> & otra ) {
	if( this != &otra ) {
		elemento = otra.elemento;
		maximo = otra.maximo;
	}

	return *this;
}

template <class T>
ostream & operator<< ( ostream & os, const Pareja<T> & p ) {
	os << "Elemento: " << p.elemento << " Máximo: " << p.maximo << endl;
	return os;
}
