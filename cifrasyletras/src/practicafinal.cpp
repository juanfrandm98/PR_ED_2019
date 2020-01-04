/**
  *
  * @file practicafinal.cpp
  * @brief Programa que ejecuta la Práctica Final de la asignatura de
  * Estructuras de Datos 2019/2020 - CIFRAS Y LETRAS.
  *
  */

#include <iostream>
#include <fstream>
#include "diccionario.h"
#include "juego.h"

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

	Juego juego( d1 );
	juego.play();

}