/**
  *
  * @file juegoletras.cpp
  * @brief Implementación del TDA JuegoLetras.
  *
  */

#include <iostream>
//#include <vector>
#include "juegoletras.h"
#include "diccionario.h"
#include "bolsaletras.h"
#include "conjuntoletras.h"
#include "letra.h"

using namespace std;

/* _________________________________________________________________________ */

JuegoLetras::JuegoLetras( const Diccionario & D ) {

	diccionario = D;
	inicializarLetras();

}

JuegoLetras::JuegoLetras( const JuegoLetras & J ) {

	diccionario = J.diccionario;
	bolsaLetras = J.bolsaLetras;
	conjuntoLetras = J.conjuntoLetras;
	
}

JuegoLetras & JuegoLetras::operator= ( const JuegoLetras & J ) {

	if( this != &J ) {
		diccionario = J.diccionario;
		bolsaLetras = J.bolsaLetras;
		conjuntoLetras = J.conjuntoLetras;
	}

	return *this;

}

void JuegoLetras::play() {

	cout << endl << "--------- COMENZANDO PARTIDA DE LETRAS ----------" << endl << endl;

	int num_letras;
	cout << "Selecciona el número de letras de tu mano: ";
	cin >> num_letras;

	vector<string> posibles;

	do {
		bolsaLetras.letrasAleatorias( num_letras );
		posibles = bolsaLetras.posibilidades( diccionario );
	} while( posibles.empty() );

	cout << endl; "Tus letras son: ";
	bolsaLetras.imprimirLetrasEnJuego();

	string palabra;
	cout << "Piensa en una palabra: ";
	cin >> palabra;

	bool correcta = false;
	if( bolsaLetras.comprobarPalabra( palabra ) ) {
		if( diccionario.comprobarPalabra( palabra ) ) {
			cout << "Palabra " << palabra << " correcta." << endl << endl;
			correcta = true;
		} else {
			cout << "Esa palabra no existe en el diccionario." << endl << endl;
		}
	} else {
		cout << "No puedes formar esa palabra con las letras de tu mano." << endl << endl;
	}

	cout << "La IA está pensando su palabra..." << endl;
	string palabra_IA = calcularMejorPalabra( posibles );
	cout << "La IA dice: " << palabra_IA << endl << endl;

	if( correcta ) {

		int puntos = puntuarPalabra( palabra );
		int puntos_IA = puntuarPalabra( palabra_IA );

		cout << "Tu palabra: " << palabra << ", puntos: " << puntos << endl;
		cout << "Palabra de la IA: " << palabra_IA << ", puntos: " << puntos_IA << endl << endl;

		if( puntos > puntos_IA )
			cout << "¡¡¡HAS GANADO!!!" << endl;
		else if( puntos < puntos_IA )
			cout << "¡¡¡GANA LA IA!!!" << endl;
		else
			cout << "¡¡¡EMPATE!!!" << endl;

	} else {

		cout << "Palabra de la IA: " << palabra_IA << ", puntos: " << puntuarPalabra( palabra_IA ) << endl;
		cout << "¡¡¡GANA LA IA!!!" << endl;

	}

	cout << endl << "-------------------------------------------------" << endl << endl;

}

int JuegoLetras::puntuarPalabra( const string & palabra ) {

	int puntos = 0;

	for( int i = 0; i < palabra.size(); i++ )
		puntos += conjuntoLetras.puntosLetra( palabra[i] );

	return puntos;

}

string JuegoLetras::calcularMejorPalabra( const vector<string> & posibles ) {

	string palabra = posibles[0];
	int puntos = puntuarPalabra( palabra );
	string otra_palabra;
	int otros_puntos;

	for( int i = 1; i < posibles.size(); i++ ) {

		otra_palabra = posibles[i];
		otros_puntos = puntuarPalabra( otra_palabra );

		if( puntos < otros_puntos ) {
			palabra = otra_palabra;
			puntos = otros_puntos;
		}
	}

	return palabra;

}