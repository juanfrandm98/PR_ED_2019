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

	cout << "Constructor por defecto... ";
	Mi_Cronologia c1;
	cout << "bien." << endl;

	cout << "Operator >> ... ";
	f1 >> c1;
	cout << "bien." << endl;

	cout << "Operator << ... " << endl;
	cout << "Cronología leída del archivo:" << endl << endl << c1 << endl << endl;
	cout << "Operator << bien." << endl;

	cout << "Constructor de copia..." << endl;
	Mi_Cronologia c2(c1);
	cout << endl << c2 << endl << endl;
	cout << "Constructor de copia bien." << endl;

	f2 >> c1;

	cout << c1 << endl;
	cout << c2 << endl;

	return 0;
}