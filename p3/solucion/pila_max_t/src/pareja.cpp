#include <iostream>
#include "pareja.h"

using namespace std;

Pareja::Pareja( const int & elem, const int & max ){
	elemento = elem;
	maximo = max;
}

Pareja & Pareja::operator=( const Pareja & otra ) {
	if( this != &otra ) {
		elemento = otra.elemento;
		maximo = otra.maximo;
	}

	return *this;
}

ostream & operator<< ( ostream & os, const Pareja & p ) {
	os << "Elemento: " << p.elemento << " Máximo: " << p.maximo << endl;
	return os;
}
