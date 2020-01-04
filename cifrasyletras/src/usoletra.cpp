/**
  *
  * @file usoletra.cpp
  * @brief Programa de prueba del TDA Letra.
  *
  */

#include "letra.h"
#include <fstream>
#include <iostream>

using namespace std;

int main( int argc, char * argv[] ) {

	if( argc != 2 ) {
		cerr << "Dime el nombre de un fichero con una letra" << endl;
		return 0;
	}

	ifstream f1( argv[1] );
	if( !f1 ) {
		cerr << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

	Letra l1;
	f1 >> l1;
	cout << "l1 = " << l1;

	Letra l2(l1);
	cout << "l2 = " << l2;

	l2.setLetra( 'x' );

	Letra l3 = l2;
	cout << "l3 = " << l3;
}