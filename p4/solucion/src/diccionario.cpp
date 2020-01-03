/**
  *
  * @file diccionario.cpp
  * @brief Implementación del TDA Diccionario
  *
  */

#include <list>

/* _________________________________________________________________________ */

template <class T, class U>
Diccionario<T,U> & Diccionario<T,U>::operator= ( const Diccionario<T,U> & D ) {
	
	if( this != &D ) {
		Borrar();
		Copiar(D);
	}

	return *this;
}

/* _________________________________________________________________________ */

template <class T, class U>
bool Diccionario<T,U>::esta_clave( const T & p, typename list<data<T,U>>::iterator & it_out ) {

	if( datos.size() > 0 ) {

		typename list<data<T,U>>::iterator it;

		for( it = datos.begin(); it != datos.end(); ++it ) {

			if( (*it).clave == p ) {
				it_out = it;
				return true;
			} else if( (*it).clave > p ) {
				it_out = it;
				return false;
			}
		}

		it_out = it;
		return false;

	} else {
		it_out = datos.end();
		return false;
	}
}

/* _________________________________________________________________________ */

template <class T, class U>
void Diccionario<T,U>::insertar( const T & clave, const list<U> & info ) {

	typename list<data<T,U>>::iterator it;

	if( !esta_clave( clave, it ) ) {
		Nueva( clave, info );
	} else {
		(*it).info_asociada.insert( info );
	}
}

/* _________________________________________________________________________ */

template <class T, class U>
void Diccionario<T,U>::add_significado_palabra( const T & clave, const U & info ) {

	typename list<data<T,U>>::iterator it;

	if( !esta_clave( clave, it ) )
		Nueva( clave, info );
	else
		(*it).info_asociada.insert( info );
}

/* _________________________________________________________________________ */

template <class T, class U>
list<U> Diccionario<T,U>::get_info_asoc( const T & clave ) {

	typename list<data<T,U>>::iterator it;

	if( !esta_clave( clave, it ) )
		return list<U>();
	else
		return (*it).info_asociada;
}

/* _________________________________________________________________________ */

template <class T, class U>
int Diccionario<T,U>::size() const {
	return datos.size();
}

/* _________________________________________________________________________ */

template <class T, class U>
typename list<data<T,U>>::iterator Diccionario<T,U>::begin() {
	typename list<data<T,U>>::iterator i;
	i.it = datos.begin();
	return i;
}

/* _________________________________________________________________________ */

template <class T, class U>
typename list<data<T,U>>::iterator Diccionario<T,U>::end() {
	typename list<data<T,U>>::iterator i;
	i.it = datos.end();
	return i;
}

/* _________________________________________________________________________ */

template <class T, class U>
ostream & operator<< ( ostream & os, Diccionario<T,U> & D ) {

	typename list<data<T,U>>::iterator it;

	for( it = D.begin(); it != D.end(); ++it ) {
		list<string>::const_iterator it_s;

		os << endl << "Palabra: " << (*it).clave << endl;
		os << "Información asociada:";

		for( it_s = (*it).info_asociada.begin();
			 it_s != (*it).info_asociada.end(); ++it_s )
			os << endl << (*it_s);

		os << "**************************************";
	}

	return os;

}

/* _________________________________________________________________________ */

template <class T, class U>
istream & operator>> ( istream & is, Diccionario<T,U> & D ) {
	int np;
	is >> np;
	is.ignore(); // Para quitar \n

	Diccionario<string,string> Daux;

	for( int i = 0; i < np; i++ ) {
		string clave;
		getline( is, clave );

		int ns;
		is >> ns;
		is.ignore(); // Para quitar \n

		list<string> laux;

		for( int j = 0; j < ns; j++ ) {
			string s;
			getline( is, s );
			laux.insert( laux.end(), s );
		}

		Daux.insertar( clave, laux );
	}

	D = Daux;

	return is;
}