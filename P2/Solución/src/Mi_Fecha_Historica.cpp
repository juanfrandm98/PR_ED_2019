#include <iostream>
#include <string>
#include "Mi_Fecha_Historica.h"

using namespace std;

// Resize
void Mi_Fecha_Historica::resize( int r ) {
	string *aux = new string[r];

	for( int i = 0; i < num_eventos; i++ )
		aux[i] = eventos[i];

	delete[] eventos;
	eventos = aux;
	reservados = r;
}

// Constructor por defecto
Mi_Fecha_Historica::Mi_Fecha_Historica(): anio(0), num_eventos(0), reservados(0), eventos(0){}

// Constructor de la clase con parámetros año, número de eventos y eventos
Mi_Fecha_Historica::Mi_Fecha_Historica( int a, int n, string *s) {
	assert( a >= -9999 && a <= 9999);
	anio = a;
	reservados = num_eventos = n;
	eventos = new string[n];

	for( int i = 0; i < n; i++ )
		eventos[i] = s[i];
}

// Constructor de copia de la clase
Mi_Fecha_Historica::Mi_Fecha_Historica( const Mi_Fecha_Historica & f ) {
	anio = f.anio;
	num_eventos = f.num_eventos;
	reservados = f.reservados;
	eventos = new string[reservados];

	for( int i = 0; i < num_eventos; i++ )
		eventos[i] = f.eventos[i];
}

// Operator +
const Mi_Fecha_Historica & Mi_Fecha_Historica::operator+( const Mi_Fecha_Historica & f ) {
	Mi_Fecha_Historica sumada( *this );

	for( int i = 0; i < f.num_eventos; i++ )
		sumada.aniadeEvento( f.eventos[i] );

	return sumada;
}

// Operator =
Mi_Fecha_Historica & Mi_Fecha_Historica::operator= (const Mi_Fecha_Historica & f ) {
	if( this != &f ) {
		anio = f.anio;
		num_eventos = f.num_eventos;
		reservados = f.reservados;
		eventos = new string[reservados];
		for( int i = 0; i < num_eventos; i++ )
			eventos[i] = f.eventos[i];
	}

	return *this;
}

// Método de acceso a Ano
int Mi_Fecha_Historica::getAnio() { return anio; }

// Añade un evento
void Mi_Fecha_Historica::aniadeEvento( string & nuevo_evento ) {
	if( num_eventos == reservados )
		resize( reservados + 1 );

	eventos[num_eventos] = nuevo_evento;
	num_eventos++;
}

// Operator <<
ostream & operator<< ( ostream & os, const Mi_Fecha_Historica & f ) {
	os << f.anio << "#" << f.num_eventos << "#";

	if( f.num_eventos > 0 )
		for( int i = 0; i < f.num_eventos; i++ )
			os << f.eventos[i] << "#";

	return os;
}

// Operator >>
istream & operator>> ( istream & is, Mi_Fecha_Historica & f ) {
	char c;
	string s = "";
	bool terminado = false;

	is >> f.anio >> c >> f.reservados >> c;
	f.num_eventos=0;
	f.eventos = new string[f.reservados];

	for( int i = 0; i < f.reservados; i++ ) {
		is >> c;

		while( c != '#' ) {
			s += c;
			is >> c;
		}

		f.aniadeEvento( s );
		s = "";
	}

	return is;
}