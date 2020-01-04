/**
  *
  * @file usodiccionario.cpp
  * @brief Programa de prueba del TDA Diccionario.
  *
  */

#include <iostream>
#include <fstream>
#include "diccionario.h"

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

	cout << "Diccionario insertado:" << endl << d1;
	cout << "El diccionario tiene " << d1.getNumLetras() << " letras." << endl;
	cout << "La letra W aparece " << d1.frecuenciaLetra('w') << " veces." << endl;
	cout << "La letra A aparece " << d1.frecuenciaLetra('a') << " veces." << endl;

	d1.aniadirPalabra( "pikachu" );
	cout << "Palabra pikachu añadida, el diccionario ahora es:" << endl << d1;

}