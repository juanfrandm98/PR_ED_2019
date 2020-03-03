/**
  *
  * @file puntuable1.cpp
  *
  * @brief Prueba sobre el set de la STL. Realiza la unión y la intersección
  * disjunta de tres sets.
  *
  * @author Juan Francisco Díaz Moreno
  *
  */

#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

/**
  *
  * @brief Devuelve la unión disjunta de tres sets.
  * @param c1 primer conjunto.
  * @param c2 segundo conjunto.
  * @param c3 tercer conjunto.
  * @return Devuelve un set<int> con la unión disjunta de c1, c2 y c3.
  *
  */
set<int> unionDisjunta( const set<int> & c1, const set<int> & c2, const set<int> & c3 ) {
  set<int> resultado;
  set<int>::const_iterator cit;

  for( cit = c1.begin(); cit != c1.end(); ++cit )
    if( !c2.count(*cit) && !c3.count(*cit) )
      resultado.insert(*cit);

  for( cit = c2.begin(); cit != c2.end(); ++cit )
    if( !c1.count(*cit) && !c3.count(*cit) )
      resultado.insert(*cit);

  for( cit = c3.begin(); cit != c3.end(); ++cit )
    if( !c2.count(*cit) && !c1.count(*cit) )
      resultado.insert(*cit);

  return resultado;
}

/**
  *
  * @brief Devuelve la intersección disjunta de tres sets.
  * @param c1 primer conjunto.
  * @param c2 segundo conjunto.
  * @param c3 tercer conjunto.
  * @return Devuelve un set<int> con la intersección disjunta de c1, c2 y c3.
  *
  */
set<int> interseccionDisjunta( const set<int> & c1, const set<int> & c2, const set<int> & c3 ) {
  set<int> resultado;
  set<int>::const_iterator cit;

  for( cit = c1.begin(); cit != c1.end(); ++cit )
    if( c2.count(*cit) && !c3.count(*cit) )
      resultado.insert(*cit);

  for( cit = c2.begin(); cit != c2.end(); ++cit )
    if( !c1.count(*cit) && c3.count(*cit) )
      resultado.insert(*cit);

  for( cit = c3.begin(); cit != c3.end(); ++cit )
    if( !c2.count(*cit) && c1.count(*cit) )
      resultado.insert(*cit);

  return resultado;
}

int main(){
  
  set<int> c1, c2, c3, c4, c5;

  c1.insert(1); c1.insert(2); c1.insert(4); c1.insert(5); c1.insert(8);
  c2.insert(4); c2.insert(5); c2.insert(6); c2.insert(9);
  c3.insert(3); c3.insert(4); c3.insert(7); c3.insert(8); c3.insert(9);

  cout << "c1: " << c1 << endl;
  cout << "c2: " << c2 << endl;
  cout << "c3: " << c3 << endl;

  c4 = unionDisjunta( c1, c2, c3 );

  cout << "Unión Disjunta de c1, c2 y c3: " << c4 << endl;

  c5 = interseccionDisjunta( c1, c2, c3 );

  cout << "Intersección Disjunta de c1, c2 y c3: " << c5 << endl;

}  