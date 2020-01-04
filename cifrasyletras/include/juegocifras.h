/**
  *
  * @file juegocifras.h
  * @brief Fichero cabecera del TDA JuegoCifras
  * 
  */

#ifndef __JUEGO_CIFRAS_H__
#define __JUEGO_CIFRAS_H__

#include <string>
#include <iostream>
#include<algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
  *
  * @brief T.D.A. JuegoCifras
  *
  * Permite jugar partidas de Cifras.
  *
  * @Author Juan Francisco Díaz Moreno, mim42 (https://github.com/mim42/countdown-solver)
  * @date Enero 2020
  *
  */

class JuegoCifras {

private:

	vector<int> allNumbers;
	vector<int> nums;
	vector<int> operators;
	int target;

	// Función obtenida de mim42 (https://github.com/mim42/countdown-solver)
	int determine( int size )
	{
		int number=nums[0];
		for(int i=1; i<size; i++)
			switch(operators[i-1])
			{
				case 0: number+= nums[i]; break;
				case 1: number -= nums[i]; break;
				case 2: number *= nums[i]; break;
				case 3: number /= nums[i]; break;
			}
		return number;
	}

	// Función obtenida de mim42 (https://github.com/mim42/countdown-solver)
	void printCorrect(int a)
	{
		switch(a)
			{
				case 0: std::cout<< "+"; break;
				case 1: std::cout<<"-"; break;
				case 2: std::cout<<"*"; break;
				case 3: std::cout<<"/"; break;
			}
	}

public:

	/**
	  *
	  * @brief Constructor por defecto.
	  *
	  */
	JuegoCifras();

	/**
	  *
	  * @brief Función que inicializa una partida, obteniendo los 6 números
	  * y el objetivo.
	  *
	  */
	void inicializarTurno();

	/**
	  *
	  * @brief Función que imita una pausa para que el jugador piense.
	  *
	  */
	void pausaTerminar();

	// Función obtenida de mim42 (https://github.com/mim42/countdown-solver)
	// Modificada para que trabaje la práctica.
	void play();

};

#endif