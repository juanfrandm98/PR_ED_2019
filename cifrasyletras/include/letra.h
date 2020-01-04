/**
  *
  * @file letra.h
  * @brief Fichero cabecera del TDA Letra
  *
  */

#ifndef __LETRA_H__
#define __LETRA_H__

#include <iostream>
using namespace std;

/**
  *
  * @brief T.D.A. Letra
  *
  * Una instancia @e c del tipo de datos abstracto @c Letra es un objeto
  * con cuatro campos: un char y dos enteros.
  *
  * El char indica la letra que se está almacenando y los enteros indican
  * su puntuación y el número de repeticiones que tiene en un diccionario.
  *
  * @Author Juan Francisco Díaz Moreno
  * @date Diciembre 2019
  *
  */
class Letra {

private:

  char letra;
  int puntos;
  int repeticiones;

public:

  /**
    *
    * @brief Constructor por defecto.
    *
    */
  Letra(){}

  /**
    * 
    * @brief Constructor de copia
    * @param L Letra que se va a copiar.
    *
    */
  Letra( const Letra & L );

  /**
    *
    * @brief Constructor con parámetros.
    * @param l Letra.
    * @param punt Puntuación de la letra.
    * @param rep Número de repeticiones de la letra en el Diccionario.
    *
    */
  Letra( const char & l, const int & punt, const int & rep );

  /**
    *
    * @brief Destructor de la clase
    *
    */
  ~Letra(){}

  /**
    *
    * @brief Setter de letra.
    * @param l Letra.
    *
    */
  void setLetra( const char & l );

  /**
    *
    * @brief Getter de letra.
    *
    */
  char getLetra() const;

  /**
    *
    * @brief Setter de puntos.
    * @param punt Puntuación de la letra.
    *
    */
  void setPuntos( const int & punt );

  /**
    *
    * @brief Getter de puntos.
    * @param l Letra.
    *
    */
  int getPuntos() const;

  /**
    *
    * @brief Setter de repeticiones.
    * @param rep Número de repeticiones de la letra.
    *
    */
  void setRepeticiones( const int & rep );

  /**
    *
    * @brief Getter de repeticiones.
    *
    */
  int getRepeticiones() const;

  /**
    *
    * @brief Operador de asignación.
    * @param L Letra a asignar.
    * @return Letra asignada.
    *
    */
  Letra & operator= ( const Letra & L );

  /**
    *
    * @brief Operador igual igual.
    * @param L Letra con la que comparar.
    * @return Devuelve true si el valor de la letra es igual
    * que la pasada como argumento.
    *
    */
  bool operator== ( const Letra & L ) const;

  /**
    *
    * @brief Operador menor que.
    * @param L Letra con la que comparar.
    * @return Devuelve true si el valor de la letra es menor
    * que la pasada como argumento.
    *
    */
  bool operator< ( const Letra & L ) const;

  /**
    *
    * @brief Salida de una Letra a ostream.
    * @param os Stream de salida.
    * @param L Letra a escribir.
    * @post Se obtiene la Letra con el formato adecuado.
    *
    */
  friend ostream & operator<< ( ostream & os, Letra & L );

  /**
    *
    * @brief Entrada de una Letra desde istream.
    * @param is Stream de entrada.
    * @param L Letra en la que se escribe.
    * @retval La Letra leída.
    * @pre La entrada tiene el siguiente formato:
    *        Letra Puntos Repeticiones
    *
    */
  friend istream & operator>> ( istream & is, Letra & L );

};

#endif