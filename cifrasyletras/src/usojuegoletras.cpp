/**
  *
  * @file usojuegoletras.cpp
  * @brief Programa de prueba del TDA JuegoLetras.
  *
  */

#include <iostream>
#include <fstream>
#include "juegoletras.h"
#include "diccionario.h"
#include "bolsaletras.h"
#include "conjuntoletras.h"
#include "letra.h"

using namespace std;

int main( int argc, char * argv[] ) {

	if( argc != 2 ) {
		cerr << "Dime el nombre de un fichero con un diccionario" << endl;
		return 0;
	}

	ifstream f1( argv[1] );
	if( !f1 ) {
		cerr << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

	Diccionario d1;
	f1 >> d1;

	JuegoLetras juego( d1 );
	juego.play();

}