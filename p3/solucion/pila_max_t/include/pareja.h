#ifndef __PAREJA_H__
#define __PAREJA_H__

#include <iostream>

using namespace std;

template <class T>
struct Pareja {
	T elemento;
	T maximo;

	Pareja() : elemento(0), maximo(0) {
	}

	Pareja( const T & elem, const T & max );

	Pareja<T> & operator= ( const Pareja<T> & otra );

	template <class U>
	friend ostream & operator<< ( ostream & os, const Pareja<U> & p );
};

#include "../src/pareja.cpp"

#endif