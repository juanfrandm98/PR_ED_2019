/**
  *
  * @file bolsaletras.cpp
  * @brief Implementación del TDA BolsaLetras.
  *
  */

#include "bolsaletras.h"
#include "diccionario.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

/* _________________________________________________________________________ */

BolsaLetras::BolsaLetras( const BolsaLetras & B ) {
	copiarBolsaLetras(B);
}

/* _________________________________________________________________________ */

BolsaLetras::BolsaLetras( const vector<char> & b ) {
	copiarBolsa(b);
}

/* _________________________________________________________________________ */

BolsaLetras & BolsaLetras::operator= ( const BolsaLetras & B ) {

	if( this != &B )
		copiarBolsaLetras(B);

	return *this;

}

/* _________________________________________________________________________ */

void BolsaLetras::setBolsa( const vector<char> & b ) {
	copiarBolsa(b);
}

/* _________________________________________________________________________ */

vector<char> BolsaLetras::getBolsa() { return bolsa; }

/* _________________________________________________________________________ */

vector<char> BolsaLetras::getLetrasEnJuego() { return letras_en_juego; }

/* _________________________________________________________________________ */

vector<string> BolsaLetras::posibilidades( const Diccionario & D ) {

	string palabra;
	vector<string> palabras_posibles;

	for( Diccionario::iterator it = D.begin(); it != D.end(); ++it ) {

		palabra = *it;

		if( comprobarPalabra( palabra ) )
			palabras_posibles.push_back( palabra );

	}

	return palabras_posibles;

}

/* _________________________________________________________________________ */

void BolsaLetras::letrasAleatorias( const int & num_letras ) {

	letras_en_juego.clear();
	srand( time(0) );

	for( int i = 0; i < num_letras; i++ ) {
		int random = rand() % bolsa.size();
		char letra = bolsa[random];
		letras_en_juego.push_back( letra );
	}

	ordenarCaracteres( letras_en_juego );

}

/* _________________________________________________________________________ */

void BolsaLetras::imprimirLetrasEnJuego() {

	for( int i = 0; i < letras_en_juego.size(); i++ )
		cout << letras_en_juego[i] << " ";

	cout << endl;

}

/* _________________________________________________________________________ */

bool BolsaLetras::comprobarPalabra( string palabra ) {

	bool valida = false;

	if( palabra.size() <= letras_en_juego.size() ) {

		vector<char> palabra_descompuesta;

		for( int i = 0; i < palabra.size(); i++ )
			palabra_descompuesta.push_back( palabra[i] );

		ordenarCaracteres( palabra_descompuesta );

		vector<char>::iterator it_letras  = letras_en_juego.begin();
		vector<char>::iterator it_palabra = palabra_descompuesta.begin();
		bool continua = true;

		while( it_palabra != palabra_descompuesta.end() &&
			   it_letras  != letras_en_juego.end() && continua) {

			if( (*it_palabra) == (*it_letras) ) {
				++it_letras;
				++it_palabra;
			} else if( (*it_palabra) < (*it_letras) ) {
				continua = false;
			} else {
				++it_letras;
			}
		}

		if( continua && ( it_palabra == palabra_descompuesta.end() ) )
			valida = true;

	}

	return valida;

}