#include <iostream>
#include <string>
#include <ArbolBinario.h>
#include <queue>

using namespace std;

template <class Tbase>
void preorden(const ArbolBinario<Tbase>& a, 
              const typename ArbolBinario<Tbase>::Nodo n){
  if (n!=0){
    cout << a.etiqueta(n) << ' ';
    preorden(a,a.izquierda(n));
    preorden(a,a.derecha(n));
  }
}
     
   
template <class Tbase>
void inorden(const ArbolBinario<Tbase>& a, 
             const typename ArbolBinario<Tbase>::Nodo n){
  if (n!=0){
    inorden(a,a.izquierda(n));
    cout << a.etiqueta(n) << ' ';
    inorden(a,a.derecha(n));
  }
}
     
template <class Tbase>
void postorden(const ArbolBinario<Tbase>& a, 
               const typename ArbolBinario<Tbase>::Nodo n){
  if (n!=0){
    postorden(a,a.izquierda(n));         
    postorden(a,a.derecha(n));
	cout << a.etiqueta(n) << ' ';
  }
}


template <class Tbase>
int Altura(const ArbolBinario<Tbase>& a, 
           const typename ArbolBinario<Tbase>::Nodo n){
  int iz,de;
  if (n==0)
    return -1;
  else {
    iz= Altura(a,a.izquierda(n));
    de= Altura(a,a.derecha(n));
    return 1+(iz>de?iz:de);
  }
}


template <class Tbase>
void refleja(ArbolBinario<Tbase>& a){
  ArbolBinario<Tbase> ai,ad;

  if (!a.empty()){
    a.podar_izquierda(a.raiz(),ai);
    a.podar_derecha(a.raiz(),ad);
    refleja(ai);
    refleja(ad);
    a.insertar_izquierda(a.raiz(),ad);
    a.insertar_derecha(a.raiz(),ai);
  }
}
 
      
template <class Tbase>
void Esquema(const ArbolBinario<Tbase>& a, 
             const typename ArbolBinario<Tbase>::Nodo n, string& pre){
  int i;
  
  if (n==0)
    cout << pre << "-- x" << endl;
  else {
    cout << pre << "-- " << a.etiqueta(n) << endl;
    if (a.derecha(n)!=0 || a.izquierda(n)!=0) {// Si no es una hoja
      pre += "   |";
      Esquema(a, a.derecha(n), pre);
      pre.replace(pre.size()-4, 4, "    ");
      Esquema (a, a.izquierda(n), pre);
      pre.erase(pre.size()-4, 4);    
    }
  }
}

template <class Tbase>
void Niveles(const ArbolBinario<Tbase> & a){
  queue<typename ArbolBinario<Tbase>::Nodo> c;
  typename ArbolBinario<Tbase>::Nodo n;

  if (!a.empty()){
    c.push(a.raiz());
    while (!c.empty()){
      n=c.front();
      c.pop();
      cout << a.etiqueta(n) << ' ';
      if (a.izquierda(n) != 0)
        c.push(a.izquierda(n));
      if (a.derecha(n) != 0)
        c.push(a.derecha(n));
    }
  }
  cout << endl;
}


template <class Tbase>
void listadohojas(const ArbolBinario<Tbase>& a, 
              const typename ArbolBinario<Tbase>::Nodo n){
  if (n!=0){
    if ((a.izquierda(n) ==0)  && (a.izquierda(n) ==0)) cout << a.etiqueta(n) << ' ';
    listadohojas(a,a.izquierda(n));
    listadohojas(a,a.derecha(n));
  }
}


// Formato de entrada: n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x
//          El árbol: n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x  
//          tiene el esquema:
//          -- 1
//             |-- 3
//             |   |-- 7
//             |    -- 6
//              -- 2
//                 |-- 5
//                 |   |-- 8
//                 |    -- x
//                  -- 4  
//


// AÑADIR 4 FUNCIONES:
//  - FUNCIÓN QUE CALCULA LA PROFUNDIDAD DE UN NODO, ES DECIR, LA
//    LONGITUD DEL CAMINO QUE VA DESDE EL NODO HASTA LA RAIZ
//  - FUNCIÓN QUE DEVUELVE EL NÚMERO DE NODOS INTERIORES QUE TIENE UN
//    ÁRBOL
//  - FUNCIÓN QUE INDICA SI EL ÁRBOL ES UN K-ÁRBOL, ES DECIR, DEVUELVE
//    TRUE SI ES UN ÁRBOL BINARIO CUYA DIFERENCIA ENTRE EL NÚMERO DE
//    NODOS QUE HAY A LA IZQUIERDA DE LA RAIZ Y A LA DERECHA DE LA RAIZ
//    ES AL MENOS K O BIEN SI UN NODO ES UN K-NODO, ES DECIR, UN NODO
//    CUYA DIFERENCIA ENTRE EL NÚMERO DE NODOS QUE TIENE A SU IZQ Y A
//    SU DER ES AL MENOS K
//  - FUNCIÓN QUE DETERMINA SI UN NODO DE UN ÁRBOL BINARIO DE ENTEROS
//    ES UN P-NODO, ES DECIR, UN NODO CUYA SUMA DE DESCENDIENTES SUMAN
//    EL VALOR P.
//            1
//        2       6       2 ES UN 12 NODO (3+4+5)
//      3   4
//            5
//  - FUNCIÓN QUE ENCUENTRA LOS CAMINOS CUYA SUMA DE VALORES SEA K. PARA
//    SIMPLIFICARLO, LOS CAMINOS QUE DETECTA SON LOS QUE PARTEN DE LA
//    RAIZ.

template <class Tbase>
int profundidad( const ArbolBinario<Tbase> & a,
                 const typename ArbolBinario<Tbase>::Nodo n ) {

  int prof = 0;
  typename ArbolBinario<Tbase>::Nodo aux = n;

  if( n == 0 )
    return -1;
  else {
    while( a.padre(aux) != 0 ) {
      prof++;
      aux = a.padre(aux);
    }

    return prof;
  }
}

template <class Tbase>
bool esHoja( const ArbolBinario<Tbase> & a,
             const typename ArbolBinario<Tbase>::Nodo n ) {
  return ( ( a.izquierda(n) == 0 ) && ( a.derecha(n) == 0 ) );
}

template <class Tbase>
int numIntermedios( const ArbolBinario<Tbase> & a,
                    const typename ArbolBinario<Tbase>::Nodo n ) {
  if( n == 0 ){
    return -1;
  } else {
    int nodos = 0;

    if( !esHoja( a, n ) ){
      nodos++;
      nodos += numIntermedios( a,a.izquierda(n) );
      nodos += numIntermedios( a,a.derecha(n) );
    }

    return nodos;
  }
}

int main(int argc, char *argv[]){
  ArbolBinario<float> a;
  string pre;


  cout << "Introduce el arbol en el formato:" << endl;
  cout << "n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x" << endl;
  cin >> a; 
	
  cout << "El arbol: " << a << " tiene recorridos:" << endl;	

  cout << "Preorden: ";
  preorden(a,a.raiz());
  cout << endl;

  cout << "Inorden: ";
  inorden(a,a.raiz());
  cout << endl;

  cout << "Postorden: ";
  postorden(a,a.raiz());
  cout << endl;	       

  cout << "y la altura es: " << Altura(a,a.raiz()) << endl;
  
  cout << "Listado por niveles del arbol" << endl;
  Niveles(a);

  cout << "El arbol: " << a << " tiene el esquema:" << endl;	
  pre="";
  Esquema(a,a.raiz(), pre);

  refleja(a);

  cout << "Listado por niveles del arbol reflejado" << endl;
  Niveles(a);

  cout << "El arbol reflejado tiene el esquema:" << endl;
  pre="";
  Esquema(a,a.raiz(), pre);
  
  
  cout << "El arbol: " << a << " tiene estas hojas :" << endl;	

  cout << "Hojas: ";
  listadohojas(a,a.raiz());
  cout << endl;

  cout << "Profundidad del hijo izquierdo de la raiz: " << profundidad( a, a.raiz()->izqda ) << endl;

  cout << "El árbol " << a << " tiene " << numIntermedios( a, a.raiz() ) << " nodos intermedios." << endl;  
  
  
  return 0;
}
