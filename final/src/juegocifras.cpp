/**
  *
  * @file juegocifras.cpp
  * @brief Implementación del TDA JuegoCifras
  *
  */

#include <string>
#include <iostream>
#include<algorithm>
#include <vector>
#include <stdio.h>
#include "juegocifras.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

/* _________________________________________________________________________ */

JuegoCifras::JuegoCifras() {

	allNumbers = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};
	operators={0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3};

}

/* _________________________________________________________________________ */

void JuegoCifras::inicializarTurno() {

	nums.clear();
	srand( time(0) );

	for( int i = 0; i < 6; i++ ) {
		int random = rand() % allNumbers.size();
		int numero = allNumbers[random];
		nums.push_back( numero );
	}

	target = 100 + rand() % ( 1000 - 100 );

}

void JuegoCifras::pausaTerminar() {

	int eleccion;

	do {

		cout << endl << "Pulsa 1 cuando hayas terminado: ";
		cin >> eleccion;

	} while( eleccion != 1 );

}

/* _________________________________________________________________________ */

void JuegoCifras::play() {

	cout << endl << "--------- COMENZANDO PARTIDA DE CIFRAS ----------" << endl << endl;

	inicializarTurno();

	cout << "Tus números son: ";

	for( int i = 0; i < nums.size(); i++ ) {
		cout << nums[i] << " ";
	}

	cout << endl << "Tienes que encontrar el número " << target << endl;

	for( int i = 0; i < 100000000; ++i ) {

		if( determine( (i%4)+3 ) == target ) {

			pausaTerminar();

			for( int j = 0; j < (i%4) + 1; j++ )
				cout << "(";

			cout << nums[0];

			for( int k = 0; k < (i%4) + 2; k++ ) {
				printCorrect( operators[k] );
				cout << nums[k+1] << ")";
			}

			cout << " = " << target << endl;
			cout << endl << "-------------------------------------------------" << endl << endl;
			break;

		}

		random_shuffle( nums.begin(), nums.end() );
		random_shuffle( operators.begin(), operators.end() );

	}

}