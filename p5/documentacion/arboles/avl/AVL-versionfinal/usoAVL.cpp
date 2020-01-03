#include <iostream>
#include "AVL.hpp"
using namespace std;

/*

    FUNCIONES A AÑADIR:

    - Intersección de dos avl.
    - Unión de dos avl.

*/

void interseccionAVL( AVL<int> & a1, AVL<int> & a2, AVL<int> & res ) {

  AVL<int>::iterator it1, it2;
  it1 = a1.begin();
  it2 = a2.begin();

  while( ( it1 != a1.end() ) && ( it2 != a2.end() ) ) {

    if( *it1 < *it2 ) {
      ++it1;
    } else if( *it1 > *it2 ) {
      ++it2;
    } else {
      res.insertar( *it1 );
      ++it1;
      ++it2;
    }

  }

}

void unionAVL( AVL<int> & a1, AVL<int> & a2, AVL<int> & res ) {

  AVL<int>::iterator it1, it2;
  it1 = a1.begin();
  it2 = a2.begin();

  while( ( it1 != a1.end() ) || ( it2 != a2.end() ) ) {
    if( *it1 < *it2 ) {
      res.insertar( *it1 );
      ++it1;
    } else if( *it1 > *it2 ) {
      res.insertar( *it2 );
      ++it2;
    } else {
      res.insertar( *it1 );
      ++it1;
      ++it2;
    }
  }

  while( it1 != a1.end() ) {
    res.insertar( *it1 );
    ++it1;
  }

  while( it2 != a2.end() ) {
    res.insertar( *it2 );
    ++it2;
  }

}

int main(int argc, const char * argv[]) {
  AVL<int> avl, avl2, avl3;
  AVL<int>::iterator it, it2, it3;
  int e;
  
  cout << "INSERCIÓN DE DATOS" << endl;
  
  cout << "Introduce un entero (<0 para terminar) ";
  cin >> e;
  while(e>=0){
    avl.insertar(e);
    for(it = avl.begin(); it!=avl.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl.Esquema();

    cout << "Introduce un entero (<0 para terminar) ";
    cin >> e;
  }
  
//  const int N = 50;
//  const float max = 100.0;
//  srand(time(NULL));
//  for(int i=0; i<N; i++)
//    avl.insertar((int) (max*rand()/RAND_MAX));
//  
//  
//  for(it = avl.begin(); it!=avl.end(); ++it)
//    cout << *it << " ";
//  cout << endl;
//  
//  avl.Esquema();
  
  cout << "BÚSQUEDA DE DATOS" << endl;
  cout << "Introduce un entero (< 0 para terminar) ";
  cin >> e;
  while(e>=0){
    cout << e << (avl.existe(e)? " SÍ" : " NO") << " está en el AVL" << endl;
    cout << "Introduce un entero (< 0 para terminar) ";
    cin >> e;
  }
  
  avl.Esquema();
  cout << "BORRADO DE DATOS" << endl;
  cout << "Introduce un entero (< 0 para terminar) ";
  cin >> e;
  while(e>=0){
    avl.borrar(e);
    for(it = avl.begin(); it!=avl.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl.Esquema();
    
    cout << "Introduce un entero (< 0 para terminar) ";
    cin >> e;
  }

  cout << "INSERCIÓN DE DATOS AVL2" << endl;
  
  cout << "Introduce un entero (<0 para terminar) ";
  cin >> e;
  while(e>=0){
    avl2.insertar(e);
    for(it2 = avl2.begin(); it2!=avl2.end(); ++it2)
      cout << *it2 << " ";
    cout << endl;
    avl2.Esquema();

    cout << "Introduce un entero (<0 para terminar) ";
    cin >> e;
  }

  cout << "INTERSECCIÓN DE AVL Y AVL2" << endl << endl;

  interseccionAVL( avl, avl2, avl3 );
  avl3.Esquema();
  
  return 0;
}

