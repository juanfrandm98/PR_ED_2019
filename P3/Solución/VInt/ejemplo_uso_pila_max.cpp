#include <iostream>
#include <pila_max.h>
//#include <pareja.h>

using namespace std;

int main() {
	Pila_max pila1, pila2;
	Pareja p;

	if( pila1.empty() )
		//cout<<"empty"<<endl;

	pila1.push(1);
	pila1.push(2);
	pila1.push(3);
	cout << "PUSH BIEN" << endl;

	if( pila1.empty() )
		//cout<<"empty"<<endl;

	pila2 = pila1;
	cout << "OPERATOR= BIEN" << endl;

	while( !pila1.empty() ) {
		p = pila1.top();
		cout << "TOP BIEN" << endl;
		pila1.pop();
		cout << "POP BIEN" << endl;
		cout << "(" << p.elemento << "," << p.maximo << ")" << endl; 
	}

	while( !pila2.empty() ) {
		p = pila2.top();
		pila2.pop();
		cout << "(" << p.elemento << "," << p.maximo << ")" << endl; 
	}
}