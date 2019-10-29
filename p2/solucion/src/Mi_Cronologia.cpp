#include <iostream>
#include <string>
#include "Mi_Cronologia.h"
#include "Mi_Fecha_Historica.h"

using namespace std;

// Resize
void Mi_Cronologia::resize( int r ) {
	Mi_Fecha_Historica *aux = new Mi_Fecha_Historica[r];

	for( int i = 0; i < num_fechas; i++ )
		aux[i] = fechas[i];

	delete[] fechas;
	fechas = aux;
	reservados = r;
}

// Ordenación
void Mi_Cronologia::ordenar() {
	for( int i = num_fechas - 1; i > 0; i-- )
		for( int j = 0; j < i; ++j )
			if( fechas[j].getAnio() > fechas[j+1].getAnio() ) {
				Mi_Fecha_Historica aux = fechas[j];
				fechas[j] = fechas[j+1];
				fechas[j+1] = aux;
			}
}

// Existe Fecha
int Mi_Cronologia::existeFecha( int a ) {
	int posicion = -1;
	bool encontrado = false;

	if( num_fechas > 0 )
		for( int i = 0; i < num_fechas && !encontrado; i++ )
			if( fechas[i].getAnio() == a ) {
				posicion = i;
				encontrado = true;
			}

	return posicion;
}

// Constructor por defecto
Mi_Cronologia::Mi_Cronologia(): num_fechas(0), reservados(0), fechas(0) {}

// Constructor de la clase
Mi_Cronologia::Mi_Cronologia( Mi_Fecha_Historica  *f, int n ) {
	assert( n > 0 );
	num_fechas = reservados = n;
	fechas = new Mi_Fecha_Historica[n];

	for( int i = 0; i < n; i++ )
		fechas[i] = f[i];
}

// Constructor de copia
Mi_Cronologia::Mi_Cronologia( const Mi_Cronologia & c ) {
	num_fechas = c.num_fechas;
	reservados = c.reservados;
	fechas = c.fechas;
}

// Operador de asignación
Mi_Cronologia & Mi_Cronologia::operator= ( const Mi_Cronologia & c ) {
	if( this != &c ) {
		num_fechas = c.num_fechas;
		reservados = c.reservados;
		fechas = new Mi_Fecha_Historica[reservados];
		for( int i = 0; i < num_fechas; i++ )
			fechas[i] = c.fechas[i];
	}

	return *this;
}

// Operador de suma
Mi_Cronologia Mi_Cronologia::operator+ ( const Mi_Cronologia & c ) {
	Mi_Cronologia sumada;
	sumada.num_fechas = 0;
	sumada.reservados = reservados + c.reservados;
	sumada.fechas = new Mi_Fecha_Historica[sumada.reservados];

	for( int i = 0; i < num_fechas; i++ )
		sumada.aniadeFecha( fechas[i] );
	
	for( int i = 0; i < c.num_fechas; i++ )
		sumada.aniadeFecha( c.fechas[i] );

	return sumada;
}

// Añade una Mi_Fecha_Historica
void Mi_Cronologia::aniadeFecha( Mi_Fecha_Historica & f ) {
	int posicion = existeFecha( f.getAnio() );

	if( posicion != -1 )
		fechas[posicion] = fechas[posicion] + f;
	else {
		if( num_fechas == reservados )
			resize( reservados + 1 );
		fechas[num_fechas] = f;
		num_fechas++;
		if( num_fechas > 0 )
			ordenar();
	}
}

// Busca una Mi_Fecha_Historica en la Mi_Cronologia a partir de un año
bool Mi_Cronologia::buscarEventosAnio( int anio, Mi_Fecha_Historica & f ) {
	bool encontrado = false;
	Mi_Fecha_Historica aux; f = aux;

	for( int i = 0; i < num_fechas && !encontrado; i++ )
		if( fechas[i].getAnio() == anio ) {
			encontrado = true;
			f = fechas[i];
		}

	return encontrado;
}

// Busca las Mi_Fecha_Historica en la Mi_Cronologia que contengan eventos que
// contengan la clave
bool Mi_Cronologia::buscarEventosClave( string clave, Mi_Cronologia & c ) {
	bool encontrado = false;
	Mi_Cronologia aux_c; c = aux_c;
	Mi_Fecha_Historica aux_f;

	for( int i = 0; i < num_fechas; i++ )
		if( fechas[i].buscarEventos( clave, aux_f ) ) {
			encontrado = true;
			c.aniadeFecha( aux_f );
		}

	return encontrado;
}

// Operator <<
ostream & operator<< ( ostream & os, const Mi_Cronologia & c ) {
	os << c.num_fechas << "\n";
	for( int i = 0; i < c.num_fechas; i++ )
		os << c.fechas[i] << "\n";

	return os;
}

// Operator >>
istream & operator>> ( istream & is, Mi_Cronologia & c) {
	string s;
	int n;
	Mi_Fecha_Historica f;

	getline( is, s );
	n = stoi( s );
	c.reservados = n;
	c.num_fechas = 0;
	c.fechas = new Mi_Fecha_Historica[c.reservados];

	for( int i = 0; i < c.reservados; i++ ) {
		is >> f;
		c.aniadeFecha(f);
	}

	return is;
}