/*
 * problema_1_1.cpp
 *
 * Diseñar funciones para trabajar con listas de enteros capaces
 * de realizar las operaciones siguientes:
 *   - Invertir la lista.
 *   - Formar una lista que contenga los elementos comunes de otras
 *     dos.
 *   - Insertar un elemento después del elemento i-ésimo.
 *   - Ordenar los elementos en orden creciente.
 *   - Calcular la media y la desviación típica de los elementos de
 *     la lista.
 *   - Mover un nodo j, n posiciones más adelante.
 *
 */

#include <iostream>
#include <list>

using namespace std;

void imprimeListaInt( const list<int> & lista ) {
	list<int>::const_iterator it;

	for( it = lista.begin(); it != lista.end(); ++it )
		cout << *it << " ";

	cout << endl;
}

void vaciaListaInt( list<int> & lista ) {
	while( !lista.empty() )
		lista.pop_front();
}

void copiaListaInt( const list<int> & original, list<int> & copia ) {
	list<int>::const_iterator it;

	for( it = original.begin(); it != original.end(); ++it )
		copia.push_back(*it);
}

void invierteListaInt( list<int> & lista ) {
	list<int> aux;
	list<int>::iterator it;
	list<int>::reverse_iterator r_it;

	for( r_it = lista.rbegin(); r_it != lista.rend(); ++r_it )
		aux.push_back(*r_it);

	vaciaListaInt( lista );
	copiaListaInt( aux, lista );
}

list<int> elementosComunes( const list<int> & l1, const list<int> & l2 ) {
	list<int> resultado;
	list<int>::const_iterator it1, it2;
	bool encontrado;

	for( it1 = l1.begin(); it1 != l1.end(); ++it1 ) {
		encontrado = false;
		for( it2 = l2.begin(); it2 != l2.end() && !encontrado; ++it2)
			if( *it1 == *it2 ) {
				encontrado = true;
				resultado.push_back(*it1);
			}
	}

	return resultado;
}

void insertaTrasPos( list<int> & l, int i, int v ) {
	if( i >= 0 ) {
		if( i < l.size() ) {
			list<int> aux;
			list<int>::iterator it;
			int j = 0;

			for( it = l.begin(); it != l.end(); ++it ) {
				aux.push_back(*it);
				j++;

				if( i == j )
					aux.push_back(v);
			}

			vaciaListaInt(l);
			copiaListaInt( aux, l );
			
		} else {
			l.push_back(v);
		}
	}
}

int main() {
	list<int> lista;

	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);
	lista.push_back(4);
	lista.push_back(5);

	cout << "Lista antes de invertir:\t";
	imprimeListaInt( lista );
	invierteListaInt( lista );
	cout << "Lista después de invertir:\t";
	imprimeListaInt( lista );

	list<int> otra_lista, comunes;

	otra_lista.push_back(1);
	otra_lista.push_back(8);
	otra_lista.push_back(3);

	comunes = elementosComunes( lista, otra_lista );
	cout << endl << "Lista: ";
	imprimeListaInt( lista );
	cout << "Otra_lista: ";
	imprimeListaInt( otra_lista );
	cout << "Comunes: ";
	imprimeListaInt( comunes );

	int elemento = 15;
	int posicion = 2;
	cout << endl << "Vamos a insertar el elemento " << elemento <<
			" tras el elemento " << posicion << " en la lista ";
	imprimeListaInt( lista );
	insertaTrasPos( lista, posicion, elemento );
	cout << "Nueva lista: ";
	imprimeListaInt( lista );
}
