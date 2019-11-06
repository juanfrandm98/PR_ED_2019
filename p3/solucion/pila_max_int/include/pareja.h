#ifndef __PAREJA_H__
#define __PAREJA_H__

#include <iostream>

using namespace std;

struct Pareja {
	int elemento;
	int maximo;

	Pareja(){
		elemento = 0;
		maximo = 0;
	}

	Pareja( const int & elem, const int & max );

	Pareja & operator= ( const Pareja & otra );

	friend ostream & operator<< ( ostream & os, const Pareja & p );
};

#endif