#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_PRODUCTOS = 8;
const int MAX_ELEMENTOS_CESTA = 4;

typedef struct {
	string denominacion;
	float cantidad=0;
	float precio=0;
}tProducto;

typedef tProducto tLista[MAX_PRODUCTOS];

typedef struct{

	tLista productos;
	int numProductosActuales=0;

}tListaProductos;

typedef struct{

	string denominacion;
	float cantidad=0;

}tElementoCesta;

typedef struct{

	tElementoCesta micesta[MAX_ELEMENTOS_CESTA];
	int numElementosActuales=0;
}tCesta;

bool cargar(tListaProductos& lista);
void mostrar(tListaProductos& lista);
bool guardar(tListaProductos& lista);
void leerCesta(tCesta& cesta);
int buscarProducto(tListaProductos lista, const string denominacion);
void realizarCompra(tListaProductos& lista, tCesta& cesta);
void mostrarAgotados(tListaProductos& lista);
int menu();

int main() {
	int opcion;
	tListaProductos lista;
	tCesta cesta;

	cout << "1. Realizar la compra de un pescadero" << endl;
	cout << "2. Mostrar productos agotados" << endl;
	cout << "3. Salir" << endl;
	opcion = menu();

	switch (opcion) {
		case 1:
			cargar(lista);
			mostrar(lista);
			cout << "Introduce tu compra" << endl;
			leerCesta(cesta);
			realizarCompra(lista, cesta);
			guardar(lista);
			break;
		case 2:
			cargar(lista);
			mostrarAgotados(lista);

			break;
		default:

			break;
	}
	system("pause");
	return 0;


}

bool cargar(tListaProductos &lista) {
	ifstream archivo;
	bool caso = false;

	int i = 0;

	archivo.open("almacen.txt");
	if (!archivo.is_open()) {
		bool caso = false;
		cout << "No se pudo cargar el archivo" << endl;
	}
	lista.numProductosActuales = 0;
	archivo >> lista.productos[i].denominacion;
	while (i < MAX_PRODUCTOS && lista.productos[i].denominacion != "XXX") {
		getline(archivo, lista.productos[i].denominacion);
		archivo >> lista.productos[i].cantidad;
		archivo >> lista.productos[i].precio;
		lista.numProductosActuales++;
		i++;
		archivo>> lista.productos[i].denominacion;

	}
	if (lista.numProductosActuales < MAX_PRODUCTOS) {
		caso = false;
		cout << "La lista contiene pocos elementos" << endl;
	}
	archivo.close();
	return caso;
}

void mostrar(tListaProductos &lista) {

	for (int i = 0; i < MAX_PRODUCTOS; i++) {
		cout << lista.productos[i].denominacion << " " << lista.productos[i].cantidad << " " << lista.productos[i].precio << endl;
	}
}

bool guardar(tListaProductos& lista) {

	ofstream archivo;
	bool caso = false;
	archivo.open("almacen.txt");

	if (archivo.is_open()) {
		caso = true;
		for (int i = 0; i < lista.numProductosActuales; i++) {
			archivo << lista.productos[i].denominacion << endl << lista.productos[i].cantidad << endl << lista.productos[i].precio << endl;
			if (i < lista.numProductosActuales - 1) {
				archivo << endl;
			}
		}
		archivo.close();
	}
	return caso;
}

void leerCesta(tCesta &cesta) {
	int i = 0;
	int contadorCompra;
	string nombreProducto;
	float cantidad;


	cesta.numElementosActuales = 0;
	cin >> contadorCompra;

	while(i < MAX_ELEMENTOS_CESTA && contadorCompra ==0 ){

		cin >> nombreProducto;
		cesta.micesta[i].denominacion = nombreProducto;
		cin >> cantidad;
		cesta.micesta[i].cantidad = cantidad;
		cesta.numElementosActuales++;
		i++;
		cin >> contadorCompra;

	}

}

int buscarProducto(tListaProductos lista, const string denominacion) {
	int pos = -1;

	for (int i = 0; i < lista.numProductosActuales; i++) {
		if (denominacion == lista.productos[i].denominacion) {
			pos = i;
		}
	}
	return pos;
}

void realizarCompra(tListaProductos& lista, tCesta& cesta) {

	float costeFinal = 0;

	for (int j = 0; j < cesta.numElementosActuales; j++) {
		int pos = buscarProducto(lista, cesta.micesta[j].denominacion);

		if (pos != -1) {

			if (lista.productos[pos].cantidad >= cesta.micesta[j].cantidad) {
				lista.productos[pos].cantidad = lista.productos[pos].cantidad - cesta.micesta[j].cantidad;
				costeFinal = costeFinal + lista.productos[pos].precio;

			}
			else if (lista.productos[pos].cantidad == 0) {
				cout << "El producto" << lista.productos[pos].denominacion << endl;
			}
			else
			{
				cout << "No hay suficiente cantidad de " << lista.productos[pos].denominacion << endl;
			}
		}
	}

	cout << "El precio a pagar es de " << costeFinal << endl;




}



void mostrarAgotados(tListaProductos& lista) {
	
	for (int i = 0; i < lista.numProductosActuales; i++) {
		if (lista.productos[i].cantidad==0) {
			cout << lista.productos[i].denominacion << endl;
		}
	}

}

int menu() {
	int opcion = -1;
	while (opcion < 1 || opcion > 3) {
		cin >> opcion;
	}
	return opcion;
}