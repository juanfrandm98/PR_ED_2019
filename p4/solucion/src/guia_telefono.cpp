/**
  *
  * @file guia_telefono.cpp
  * @brief Implementación del TDA Guia_Telefono
  *
  */

/* _________________________________________________________________________ */

string & Guia_Telefono::operator[] ( const string & nombre ) {
	return datos[nombre];
}

/* _________________________________________________________________________ */

pair<map<string,string>::iterator,bool> insertar( const string & nombre,
												  const string & telefono ) {

	pair<string,string> nueva_pareja( nombre, telefono );

	return insertar_pareja( nueva_pareja );

}

/* _________________________________________________________________________ */

pair<map<string,string>::iterator,bool> Guia_Telefono::insertar_pareja(
								const pair<string,string> & nueva_pareja ) {

	pair<map<string,string>::iterator,bool> resultado;

	resultado = datos.insert( nueva_pareja );

	return resultado;
}

/* _________________________________________________________________________ */

void Guia_Telefono::borrar( const string & nombre ) {

	datos.erase( nombre );

}