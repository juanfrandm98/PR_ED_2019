/**
  *
  * @file bolsaletras.h
  * @brief Fichero cabecera del TDA BolsaLetras.
  *
  */

#ifndef __BOLSA_LETRAS_H__
#define __BOLSA_LETRAS_H__

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "diccionario.h"

using namespace std;

/**
  *
  * @brief T.D.A. BolsaLetras
  *
  * @Author Juan Francisco Díaz Moreno
  * @Date Enero 2020
  *
  */

class BolsaLetras {

private:

	vector<char> bolsa;				// Contiene las letras del juego
	vector<char> letras_en_juego; 	// Mano con la que se juega

	// Copia una bolsa en otra
	void copiarBolsa( const vector<char> & b ) {
		bolsa.clear();
		for( int i = 0; i < b.size(); i++ )
			bolsa.push_back(b[i]);
	}

	// Copia las letras en juego
	void copiarLetras( const vector<char> & l ) {
		letras_en_juego.clear();
		for( int i = 0; i < l.size(); i++ )
			letras_en_juego.push_back(l[i]);
	}

	// Copia una BolsaLetras
	void copiarBolsaLetras( const BolsaLetras & B ) {
		copiarBolsa( B.bolsa );
		copiarLetras( B.letras_en_juego );
	}

	// Ordena los caracteres de un vector de char en orden ascendente
	void ordenarCaracteres( vector<char> & v ) {

		vector<char> ordenado;
		char menor;
		int pos;

		while( !v.empty() ) {

			menor = v.front();
			pos = 0;

			for( int i = 1; i < v.size(); i++ )
				if( v[i] < menor ) {
					menor = v[i];
					pos = i;
				}

			ordenado.push_back( menor );
			v.erase( v.begin() + pos );

		}

		v.swap( ordenado );
		
	}

public:

	/**
	  *
	  * @brief Constructor por defecto.
	  *
	  */
	BolsaLetras(){}

	/**
	  *
	  * @brief Constructor de copia.
	  * @param B Bolsa de letras que se va a copiar.
	  *
	  */
	BolsaLetras( const BolsaLetras & B );

	/**
	  *
	  * @brief Constructor con parámetros.
	  * @param b Bolsa con las letras.
	  *
	  */
	BolsaLetras( const vector<char> & b );

	/**
	  *
	  * @brief Operador de asignación.
	  * @param B BolsaLetras a copiar.
	  * @return BolsaLetras copiada.
	  *
	  */
	BolsaLetras & operator= ( const BolsaLetras & B );

	/**
	  *
	  * @brief Setter de la bolsa de letras.
	  * @param b Bolsa.
	  *
	  */
	void setBolsa( const vector<char> & b );

	/**
	  *
	  * @brief Getter de la bolsa de letras.
	  * @return Bolsa.
	  *
	  */
	vector<char> getBolsa();

	/**
	  *
	  * @brief Getter de las letras en juego.
	  * @return Letras_en_juego.
	  *
	  */
	vector<char> getLetrasEnJuego();

	/**
	  *
	  * @brief Devuelve las palabras que puedan formarse con
	  * letras_en_juego.
	  * @param D Diccionario en el que comprobar las palabras.
	  * @return Palabras que se pueden formar.
	  *
	  */
	vector<string> posibilidades( const Diccionario & D );

	/**
	  *
	  * @brief Genera una nueva mano de letras_en_juego.
	  * @param num_letras Número de letras que se quiere obtener.
	  *
	  */
	void letrasAleatorias( const int & num_letras );

	/**
	  *
	  * @brief Muestra por pantalla las letras en juego.
	  *
	  */
	void imprimirLetrasEnJuego();

	/**
	  *
	  * @brief Comprueba si una palabra puede formarse con las
	  * letras de la mano actual.
	  * @param palabra Palabra a comprobar.
	  * @return Devuelve true si la palabra se puede formar con
	  * las letras de letras_en_juego.
	  *
	  */
	bool comprobarPalabra( string palabra );


};

#endif