
struct Pareja {
	int elemento;
	int maximo;

	Pareja() : elemento(0), maximo(0){
	}

	Pareja( const int & elem, const int & max ) : elemento( elem ), maximo( max ){
	}
};