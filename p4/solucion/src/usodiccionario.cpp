#include <iostream>
#include "../include/diccionario.h"

using namespace std;

void escribe_significados( const list<string> & l ) {

	list<string>::const_iterator it;

	for( it = l.begin(); it != l.end(); ++it )
		cout << *it << endl;
}

int main() {

	Diccionario<string,string> D;

	cin >> D;
	cout << D;

	string a;
	cout << "Introduce una palabra" << endl;
	cin >> a;

	list<string> l = D.get_info_asoc(a);

	if( l.size() > 0 )
		escribe_significados(l);
	else
		cout << endl << "Palabra no encontrada." << endl;
}