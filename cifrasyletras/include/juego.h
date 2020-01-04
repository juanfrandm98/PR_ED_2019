/**
  *
  * @file juego.h
  * @brief Fichero cabecera del TDA Juego.
  *
  */

#ifndef __JUEGO_H__
#define __JUEGO_H__

#include <iostream>
#include "juegoletras.h"
#include "juegocifras.h"

using namespace std;

/**
  *
  * @brief T.D.A. Juego
  *
  * Una instancia @e c del tipo de datos abstracto @c Juego es
  * un objeto con 2 campos:
  *
  * 	- Un JuegoLetras que permite jugar partidas de Letras.
  *		- Un JuegoCifras que permite jugar partidas de Cifras.
  *
  * Permite almacenar los dos juegos ya instanciados y jugar a
  * ambos cuando se quiera gracias a un menú.
  *
  * @Author Juan Francisco Díaz Moreno
  * @Date Enero 2020
  *
  */

class Juego {

private:

	JuegoLetras juegoLetras;
	JuegoCifras juegoCifras;

	// Función que muestra el menú principal.
	int menu() {

		int eleccion;

		cout << endl << "Pulse uno de estos números para jugar:" << endl;
		cout << "1 - Juego de las cifras." << endl;
		cout << "2 - Juego de las letras." << endl;
		cout << "3 - ¿En qué consiste cada juego?" << endl;
		cout << "0 - Salir." << endl;

		do {

			cout << "Elección: ";
			cin >> eleccion;

			if( eleccion < 0 || eleccion > 3 )
				cout << "Número no válido..." << endl;

		} while( eleccion < 0 || eleccion > 3 );

		return eleccion;

	}

	// Función que muestra las instrucciones de los juegos.
	void mostrarInstrucciones() {

		cout << endl << " --------------- El Juego de las Cifras --------------- " << endl;
		cout << " En este juego se te proporcionarán seis números" << endl;
		cout << " enteros y otro número de 3 cifras." << endl;
		cout << " Tendrás que conseguir obtener el número de tres cifras " << endl;
		cout << " utilizando el resto de números como mucho una sola vez" << endl;
		cout << " y las operaciones elementales de la suma, resta" << endl;
		cout << " producto y división entera." << endl;
		cout << " No están permitidas las divisiones no exactas ni la" << endl;
		cout << " utilización de números negativos en pasos intermedios." << endl;
		cout << " En caso de que no sea posible obtener el número" << endl;
		cout << " deseado, ganará aquel que se acerque más." << endl << endl;

		cout << " --------------- El Juego de las Letras --------------- " << endl;
		cout << " En este juego se te proporcionará una serie de letras" << endl;
		cout << " y tendrás que formar una palabra utilizando las que" << endl;
		cout << " necesites una sola vez para crear una palabra." << endl;
		cout << " Elige bien porque tu rival también escogerá una." << endl;
		cout << " palabra." << endl;
		cout << " Para ganar, crea una palabra con más puntos que la" << endl;
		cout << " de tu rival, teniendo en cuenta que las letra más" << endl;
		cout << " raras proporcionan más puntos." << endl << endl;

	}

public:

	/**
	  *
	  * @brief Constructor por defecto.
	  *
	  */
	Juego(){}

	/**
	  *
	  * @brief Constructor con parámetros.
	  * @param D Diccionario con el que se va a jugar en el
	  * juego de las letras.
	  *
	  */
	Juego( const Diccionario & D );

	/**
	  *
	  * @brief Constructor de copia.
	  * @param J Juego a copiar.
	  *
	  */
	Juego( const Juego & J );

	/**
	  *
	  * @brief Función principal para jugar.
	  *
	  */
	void play();

};

#endif