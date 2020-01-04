/**
  *
  * @file letra.cpp
  * @brief Implementación del TDA Letra.
  *
  */

#include <iostream>
#include "letra.h"

using namespace std;

/* _________________________________________________________________________ */

Letra::Letra( const Letra & L ) {

	letra = L.letra;
	puntos = L.puntos;
	repeticiones = L.repeticiones;

}

/* _________________________________________________________________________ */

Letra::Letra( const char & l, const int & punt, const int & rep ) {

	letra = l; puntos = punt; repeticiones = rep;

}

/* _________________________________________________________________________ */
/*							GETTERS Y SETTERS								 */
/* _________________________________________________________________________ */

void Letra::setLetra( const char & l ) { letra = l; }
void Letra::setPuntos( const int & punt ) { puntos = punt; }
void Letra::setRepeticiones( const int & rep ) { repeticiones = rep; }

char Letra::getLetra() const { return letra; }
int Letra::getPuntos() const { return puntos; }
int Letra::getRepeticiones() const { return repeticiones; }

/* _________________________________________________________________________ */

Letra & Letra::operator= ( const Letra & L ) {

	letra = L.letra;
	puntos = L.puntos;
	repeticiones = L.repeticiones;

}

/* _________________________________________________________________________ */

bool Letra::operator< ( const Letra & L ) const {
	return letra < L.letra;
}

/* _________________________________________________________________________ */

bool Letra::operator== ( const Letra & L ) const {
	return letra == L.letra;
}

/* _________________________________________________________________________ */

ostream & operator<< ( ostream & os, Letra & L ) {

	os << L.letra << " " << L.puntos << " " << L.repeticiones << endl;

}

/* _________________________________________________________________________ */

istream & operator>> ( istream & is, Letra & L ) {

	char letra;
	int puntos, repeticiones;

	is >> letra >> puntos >> repeticiones;

	L.setLetra( letra );
	L.setPuntos( puntos );
	L.setRepeticiones( repeticiones );

}