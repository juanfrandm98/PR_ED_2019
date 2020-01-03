/**
  *
  * @file diccionario.cpp
  * @brief Implementación del TDA Diccionario.
  *
  */

#include <iostream>
#include <string>
#include <set>
#include "diccionario.h"

using namespace std;

/* _________________________________________________________________________ */

Diccionario & Diccionario::operator= ( const Diccionario & D ) {

	if( this != &D ) {
		borrar();
		copiar(D);
	}

	return *this;

}

/* _________________________________________________________________________ */

Diccionario & Diccionario::operator+ ( const Diccionario & D ) {

	datos.insert( D.datos.begin(), D.datos.end() );

}

/* _________________________________________________________________________ */

void Diccionario::aniadirPalabra( const string & palabra ) {
	datos.insert( palabra );
}

/* _________________________________________________________________________ */

bool Diccionario::comprobarPalabra( const string & palabra ) {

	if( datos.find( palabra ) != datos.end() )
		return true;
	else
		return false;

}

/* _________________________________________________________________________ */

int Diccionario::frecuenciaLetra( const char & letra ) {

	set<string>::iterator it1;
	string::iterator it2;
	string palabra;
	int frecuencia = 0;

	for( it1 = datos.begin(); it1 != datos.end(); ++it1 ) {
		palabra = *it1;

		for( it2 = palabra.begin(); it2 != palabra.end(); ++it2 )
			if( *it2 == letra )
				frecuencia++;
	}

	return frecuencia;

}

/* _________________________________________________________________________ */

int Diccionario::getNumLetras() {

	int total = 0;
	set<string>::iterator it;

	for( it = datos.begin(); it != datos.end(); ++it )
		total += (*it).size();

	return total;

}

/* _________________________________________________________________________ */

Diccionario::iterator Diccionario::begin() const {

	iterator i;

	i.it = datos.begin();
	i.final = datos.end();

	return i;

}

/* _________________________________________________________________________ */

Diccionario::iterator Diccionario::end() const {

	iterator i;

	i.it = datos.end();
	i.final = datos.end();
	
	return i;

}

/* _________________________________________________________________________ */

ostream & operator<< ( ostream & os, Diccionario & D ) {

	for( Diccionario::iterator it = D.begin();
		 it != D.end(); ++it )
		os << (*it) << endl;

	return os;

}

/* _________________________________________________________________________ */

istream & operator>> ( istream & is, Diccionario & D ) {

	string palabra;

	while( is >> palabra )
		D.aniadirPalabra( palabra );

	return is;

}