#include <iostream>
#include "pila_max.h"
//#include "pareja.h"

using namespace std;

int main() {
	Pila_max pila1, pila2;
	Pareja p;

	if( pila1.empty() )
		cout << "La pila1 está vacía" << endl;
	else
		cout << "La pila1 NO está vacía" << endl;

	pila1.push(1);
	pila1.push(2);
	pila1.push(3);

	if( pila1.empty() )
		cout << "La pila1 está vacía" << endl;
	else
		cout << "La pila1 NO está vacía" << endl;

	cout << "pila1:" << endl << pila1;

	pila2 = pila1;

	cout << "pila2:" << endl << pila2;

	pila2.pop();
	pila2.push(5);

	cout << "pila2:" << endl << pila2;

	cout << "Tope de pila2: " << pila2.top();

	pila2.push(2);

	cout << "pila2:" << endl << pila2;

	return 0;
}