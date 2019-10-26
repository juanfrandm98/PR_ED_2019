#include "Mi_Cronologia.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char * argv[] ) {

	if( argc != 3 ) {
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

	Mi_Cronologia c1;
	f1 >> c1;
	cout << "c1:" << endl << c1 << endl;

	cout << "Copiando c1 en c2..." << endl;
	Mi_Cronologia c2(c1);
	cout << "c2:" << endl << c2 << endl;

	cout << "Modificando c2..." << endl;
	f2 >> c2;
	cout << "c2:" << endl << c2 << endl;

	int anio = 19;
	Mi_Fecha_Historica fh1;

	if( c1.buscarEventosAnio( anio, fh1 ) )
		cout << "Encontrada fecha histórica en el año " << anio << ": " << fh1 << endl;
	else
		cout << "Fecha histórica no encontrada en el año " << anio << endl;

	if( c2.buscarEventosAnio( anio, fh1 ) )
		cout << "Encontrada fecha histórica en el año " << anio << ": " << fh1 << endl;
	else
		cout << "Fecha histórica no encontrada en el año " << anio << endl;

	string clave1 = "SEGUN"; string clave2 = "ANTONIO";
	Mi_Cronologia c3;

	if( c1.buscarEventosClave( clave1, c3 ) )
		cout << "Encontrada la clave '" << clave1 << "' en c1:" << endl << c3 << endl;
	else
		cout << "Clave '" << clave1 << "' no encontrada en c1." << endl;

	if( c1.buscarEventosClave( clave2, c3 ) )
		cout << "Encontrada la clave '" << clave2 << "' en c1:" << endl << c3 << endl;
	else
		cout << "Clave '" << clave2 << "' no encontrada en c1." << endl;

	//Mi_Cronologia c4 = c1 + c2;
	Mi_Cronologia c4;
	c4 = c1 + c2;
	cout << "c1 + c2 = c4 = " << endl << c4 << endl;

	return 0;
}