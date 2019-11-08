#include <iostream>
#include "pila_max.h"
//#include "pareja.h"

using namespace std;

int main() {
	Pila_max<int> pila1, pila2;
	Pareja<int> p;

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

	cout << endl << endl << "AHORA TRABAJAREMOS CON PILAS DE CHAR" << endl;

	Pila_max<char> pila3, pila4;
	Pareja<char> p2;

	if( pila3.empty() )
		cout << "La pila3 está vacía" << endl;
	else
		cout << "La pila3 NO está vacía" << endl;

	pila3.push('a');
	pila3.push('b');
	pila3.push('c');

	if( pila3.empty() )
		cout << "La pila3 está vacía" << endl;
	else
		cout << "La pila3 NO está vacía" << endl;

	cout << "pila3:" << endl << pila3;

	pila4 = pila3;

	cout << "pila4:" << endl << pila4;

	pila4.pop();
	pila4.push('e');

	cout << "pila4:" << endl << pila4;

	cout << "Tope de pila4: " << pila4.top();

	pila4.push('b');

	cout << "pila4:" << endl << pila4;

	return 0;
}