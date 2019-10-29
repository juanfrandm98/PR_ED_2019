#include "Mi_Fecha_Historica.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char * argv[] ) {

	if( argc != 4 ) {
		cerr << "Dime el nombre de dos ficheros con cronologías." << endl;
		return 0;
	}

	ifstream f1( argv[1] );
	if( !f1 ) {
		cerr << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

	ifstream f2( argv[2] );
	if( !f2 ) {
		cerr << "No puedo abrir el fichero " << argv[2] << endl;
		return 0;
	}

	ifstream f3( argv[3] );
	if( !f3 ) {
		cerr << "No puedo abrir el fichero " << argv[3] << endl;
		return 0;
	}

	Mi_Fecha_Historica fh1;
	f1 >> fh1;
	cout << "fh1 = " << fh1 << endl;

	Mi_Fecha_Historica fh2(fh1);
	cout << "fh2 = " << fh2 << endl;

	Mi_Fecha_Historica fh3, fh4, fh5;
	f2 >> fh3;
	f3 >> fh4;
	cout << "fh3 = " << fh3 << endl;
	cout << "fh4 = " << fh4 << endl;

	fh5 = fh3 + fh4;
	cout << "fh3 + fh4 = fh5 = " << fh5 << endl;

	Mi_Fecha_Historica fh6, fh7, fh8;
	string clave6 = "EV", clave7 = "YA", clave8 = "ANTONIO";

	if( fh5.buscarEventos( clave6, fh6 ) ){
		cout << "Se ha encontrado la clave '" << clave6 << "' en fh5: " << endl;
		cout << "fh6 = " << fh6 << endl;
	} else {
		cout << "No se ha encontrado la clave '" << clave6 << "' en fh5: " << endl;
		cout << "fh6 = " << fh6 << endl;
	}

	if( fh5.buscarEventos( clave7, fh7 ) ){
		cout << "Se ha encontrado la clave '" << clave7 << "' en fh5: " << endl;
		cout << "fh7 = " << fh7 << endl;
	} else {
		cout << "No se ha encontrado la clave '" << clave7 << "' en fh5: " << endl;
		cout << "fh7 = " << fh7 << endl;
	}

	if( fh5.buscarEventos( clave8, fh8 ) ){
		cout << "Se ha encontrado la clave '" << clave8 << "' en fh5: " << endl;
		cout << "fh8 = " << fh8 << endl;
	} else {
		cout << "No se ha encontrado la clave '" << clave8 << "' en fh5: " << endl;
		cout << "fh8 = " << fh8 << endl;
	}

	return 0;
}