template <class T>
struct Pareja {
	T elemento;
	T maximo;

	Pareja() : elemento(0), maximo(0){
	}

	Pareja( const T & elem, const T & max ) : elemento( elem ), maximo( max ){
	}
};