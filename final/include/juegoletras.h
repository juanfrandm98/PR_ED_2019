/**
  *
  * @file juegoletras.h
  * @brief Fichero cabecera del TDA JuegoLetras.
  *
  */

#ifndef __JUEGO_LETRAS_H__
#define __JUEGO_LETRAS_H__

#include <iostream>
//#include <vector>
#include "diccionario.h"
#include "bolsaletras.h"
#include "conjuntoletras.h"
#include "letra.h"

using namespace std;

/**
  *
  * @brief T.D.A. JuegoLetras
  *
  * Una instancia @e c del tipo de datos abstracto @c JuegoLetras es un objeto
  * con 3 campos:
  *
  *		- Un diccionario que incluye las palabras que se podrán adivinar en
  *		  la partida de Letras.
  *		- Una bolsa de letras que incluye las letras disponibles inicialmente
  *		  y la mano de juego actual.
  * 	- Un conjunto de letras que incluye la información de las letras en
  *		- juego.
  *
  * Permite jugar partidas de Letras.
  *
  * @Author Juan Francisco Díaz Moreno
  * @Date Enero 2020
  *
  */

class JuegoLetras {

private:

	Diccionario diccionario;
	BolsaLetras bolsaLetras;
	ConjuntoLetras conjuntoLetras;

	// Función que comprueba si una letra está incluida en un vector de char
	bool esta( const vector<char> & vector_bolsa, const char & caracter ) {

		for( int i = 0; i < vector_bolsa.size(); i++ )
			if( vector_bolsa[i] == caracter )
				return true;

		return false;

	}

	// Función que rellena un set<Letra> y un vector<char> en función
	// del diccionario actual.
	void rellenarConjuntos( set<Letra> & set_conjunto, vector<char> & vector_bolsa ) {

		Diccionario::iterator it;
		string palabra;
		char caracter;
		int repeticiones;
		int puntos;

		for( it = diccionario.begin(); it != diccionario.end(); ++it ) {
			palabra = (*it);

			for( int i = 0; i < palabra.size(); i++ ) {
				caracter = palabra[i];

				if( !esta( vector_bolsa, caracter ) ) {
					repeticiones = diccionario.frecuenciaLetra( caracter );
					puntos = ( ( 1 - ( repeticiones / diccionario.getNumLetras() ) ) * 100 );

					Letra letra( caracter, puntos, repeticiones );

					vector_bolsa.push_back( caracter );
					set_conjunto.insert( letra );
				}
			}
		}

	}

	// Función que inicializar bolsaLetras y conjuntoLetras cuando
	// se añade un nuevo Diccionario al JuegoLetras
	void inicializarLetras() {

		set<Letra> set_conjunto;
		vector<char> vector_bolsa;

		rellenarConjuntos( set_conjunto, vector_bolsa );

		BolsaLetras nuevaBolsa( vector_bolsa );
		bolsaLetras = nuevaBolsa;

		ConjuntoLetras nuevoConjunto( set_conjunto );
		conjuntoLetras = nuevoConjunto;

	}

public:

	/**
	  *
	  * @brief Constructor por defecto.
	  *
	  */
	JuegoLetras(){}

	/**
	  *
	  * @brief Constructor con parámetros.
	  * @param D Diccionario con el que se va a jugar.
	  *
	  */
	JuegoLetras( const Diccionario & D );

	/**
	  *
	  * @brief Constructor de copia.
	  * @param J JuegoLetras que se va a copiar.
	  *
	  */
	JuegoLetras( const JuegoLetras & J );

	/**
	  *
	  * @brief Operador de asignación.
	  * @param D JuegoLetras a asignar.
	  * @return JuegoLetras asignado.
	  *
	  */
	JuegoLetras & operator= ( const JuegoLetras & J );

	/**
	  *
	  * @brief Función para jugar una ronda de Letras.
	  *
	  */
	void play();

	/**
	  *
	  * @brief Calcula los puntos que tiene una palabra.
	  * @param palabra Palabra cuyos puntos se quieren calcular.
	  * @return Devuelve la puntuación de la palabra dada.
	  *
	  */
	int puntuarPalabra( const string & palabra );

	/**
	  *
	  * @brief Calcula la mejor palabra de la mano.
	  * @return Devuelve la mejor palabra de la mano.
	  *
	  */
	string calcularMejorPalabra( const vector<string> & posibles );

};

#endif