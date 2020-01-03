/**
  *
  * @file usoconjuntoletras.cpp
  * @brief Programa de prueba del TDA ConjuntoLetras.
  *
  */

#include "conjuntoletras.h"
#include <fstream>
#include <iostream>

using namespace std;

int main( int argc, char *argv[] ) {

	if( argc != 2 ) {
		cerr << "Dime el nombre de un fichero con un conjunto de letras" << endl;
		return 0;
	}

	ifstream f1( argv[1] );
	if( !f1 ) {
		cerr << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

	ConjuntoLetras c1;
	f1 >> c1;
	cout << "c1 = " << c1;

}