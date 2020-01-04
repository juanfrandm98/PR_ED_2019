/**
  *
  * @file conjuntoletras.cpp
  * @brief Implementación del TDA ConjuntoLetras.
  *
  */

#include "conjuntoletras.h"
#include "letra.h"
#include <iostream>

using namespace std;

/* _________________________________________________________________________ */

ConjuntoLetras::ConjuntoLetras( const ConjuntoLetras & C ) {
	copiar(C);
}

/* _________________________________________________________________________ */

ConjuntoLetras::ConjuntoLetras( const set<Letra> & conjunto ) {

	setLetras( conjunto );

}

/* _________________________________________________________________________ */

void ConjuntoLetras::setLetras( const set<Letra> & conjunto ) {

	letras.insert( conjunto.begin(), conjunto.end() );

}

/* _________________________________________________________________________ */

set<Letra> ConjuntoLetras::getLetras() { return letras; }

/* _________________________________________________________________________ */

int ConjuntoLetras::size() { return letras.size(); }

/* _________________________________________________________________________ */

char ConjuntoLetras::mejorLetra() {

	char letra;
	int puntos = -1;

	set<Letra>::iterator it;

	for( it = letras.begin(); it != letras.end(); ++it )
		if( (*it).getPuntos() > puntos ) {
			letra = (*it).getLetra();
			puntos = (*it).getPuntos();
		}

	return letra;

}

/* _________________________________________________________________________ */

void ConjuntoLetras::insertarLetra( const Letra & L ) {

	letras.insert(L);

}

/* _________________________________________________________________________ */

int ConjuntoLetras::puntosLetra( const char & letra ) {

	for( set<Letra>::iterator it = letras.begin(); it != letras.end(); ++it )
		if( (*it).getLetra() == letra )
			return (*it).getPuntos();

	return -1;

}

/* _________________________________________________________________________ */

ConjuntoLetras & ConjuntoLetras::operator= ( const ConjuntoLetras & C ) {

	if( this != &C ) {
		copiar(C);
	}

	return *this;

}

/* _________________________________________________________________________ */

ostream & operator<< ( ostream & os, ConjuntoLetras & C ) {

	cout << "Número de letras: " << C.size() << endl;
	os << C.size() << endl;

	/*
	for( set<Letra>::iterator it = C.getLetras().begin(); it != C.getLetras().end(); ++it ) {
		Letra l = *it;
		cout << "Letra: " << l;
		os << l;
	}
	*/

	for( Letra l : C.getLetras() )
		cout << l;

}

/* _________________________________________________________________________ */

istream & operator>> ( istream & is, ConjuntoLetras & C ) {

	int numLetras;
	is >> numLetras;

	cout << "Número de letras: " << numLetras << endl;

	for( int i = 0; i < numLetras; i++ ) {
		Letra l;
		is >> l;
		cout << "Insertando: " << l;
		C.insertarLetra(l);
	}

}