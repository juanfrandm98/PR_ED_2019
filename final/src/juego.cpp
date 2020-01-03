/**
  *
  * @file juego.cpp
  * @brief Implementación del TDA Juego.
  *
  */

#include "juego.h"
#include "juegoletras.h"
#include <iostream>

using namespace std;

/* _________________________________________________________________________ */

Juego::Juego( const Diccionario & D ) {

	JuegoLetras nuevoJuego(D);
	juegoLetras = nuevoJuego;

}

/* _________________________________________________________________________ */

Juego::Juego( const Juego & J ) {

	juegoLetras = J.juegoLetras;

}

/* _________________________________________________________________________ */

void Juego::play() {

	cout << "/////////////////////////////////////////////////" << endl;
	cout << "//                                             //" << endl;
	cout << "//               CIFRAS Y LETRAS               //" << endl;
	cout << "//                                             //" << endl;
	cout << "//        Por Juan Fransico Díaz Moreno        //" << endl;
	cout << "//                                             //" << endl;
	cout << "/////////////////////////////////////////////////" << endl;

	int eleccion;

	do {

		eleccion = menu();

		if( eleccion == 1 ) {

			juegoCifras.play();

		} else if( eleccion == 2 ) {

			juegoLetras.play();

		} else if( eleccion == 3 ) {

			mostrarInstrucciones();

		}

	} while( eleccion != 0 );

	cout << endl << endl << "¡Gracias por jugar a CIFRAS Y LETRAS!" << endl;
	cout << "Vuelve cuando quieras." << endl;

}