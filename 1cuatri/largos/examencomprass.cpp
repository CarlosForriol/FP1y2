#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

const int MAX_PRODUCTOS = 8;
const int MAX_ELEMENTOS_CESTA = 4;

typedef struct
{
	string denominacion;
	float cantidad=0;
	float precio=0;

}tProducto;

typedef tProducto tLista[MAX_PRODUCTOS];

typedef struct
{
	tLista productos;
	int cont=0; // cont

}tListaProductos;

typedef struct
{
	string denominacion;
	float cantidad=0;

}tElementoCesta;

typedef struct
{
	tElementoCesta micesta[MAX_ELEMENTOS_CESTA];
	int cont=0;
}tCesta;

bool cargar(tListaProductos& lista);
void mostrar(tListaProductos lista);
bool guardar(tListaProductos lista);
void leerCesta(tCesta& cesta);
int buscar(tListaProductos lista, string denominacion);
void realizarcompara(tListaProductos lista, tCesta cesta);
void mostraragotados(tListaProductos lista);
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
		cargar( lista);
		mostrar(lista);
		cout << "Introduce tu compra" << endl;
		leerCesta( cesta);
		realizarcompara( lista,  cesta);
		guardar( lista);
		break;
	case 2:
		cargar(lista);
		mostraragotados( lista);
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}

bool cargar(tListaProductos& lista) {
	bool caso = false;
	ifstream archivo;
	archivo.open("almacen.txt");
	int i = 0;

	if (archivo.is_open()) {
		caso = true;
		lista.cont = 0;

		while (i < MAX_PRODUCTOS && lista.productos[i].denominacion != "XXX") {
			getline(archivo, lista.productos[i].denominacion);
			archivo >> lista.productos[i].cantidad;
			archivo >> lista.productos[i].precio;
			archivo.ignore();
			lista.cont++;
			i++;
		}
		archivo.close();
	}
	return caso;
}
void mostrar(tListaProductos lista) {

	for (int i = 0; i < lista.cont; i++) {
		cout << lista.productos[i].denominacion << " " << lista.productos[i].cantidad << " " << lista.productos[i].precio << endl;
	}
}
bool guardar(tListaProductos lista) {

	ofstream archivo;
	archivo.open("almacen.txt");
	bool caso = false;
	if (archivo.is_open()) {

		caso = true;
		for (int i = 0; i < lista.cont; i++) {
			archivo << lista.productos[i].denominacion << endl;
			archivo << lista.productos[i].cantidad << endl;
			archivo << lista.productos[i].precio << endl;
			if (i < lista.cont - 1) {
				archivo << endl;
			}
		}
		archivo.close();
	}
	return caso;
}
void leerCesta(tCesta& cesta) {
	string denominacion; 
	float cantidad;
	int i = 0;
	int contador;
	cesta.cont = 0;
	cin >> contador;
	while (i < MAX_ELEMENTOS_CESTA && contador == 0) {
		cin >> denominacion;
		cesta.micesta[i].denominacion = denominacion;
		cin >> cantidad;
		cesta.micesta[i].cantidad = cantidad;
		cesta.cont++;
		i++;
		cin >> contador;
	}
}

int buscar(tListaProductos lista, const string denominacion) {
	int pos = -1;

	for (int i = 0; i < lista.cont; i++) {
		if (lista.productos[i].denominacion == denominacion) {
			pos = i;
		}
		i++;
	}
	return pos;
}
void realizarcompara(tListaProductos lista, tCesta cesta) {
	float total = 0;

	for (int j = 0; j < cesta.cont; j++) {
		int pos = buscar(lista, lista.productos[j].denominacion);

		if (pos != -1) {
			if (lista.productos[pos].cantidad >= cesta.micesta[pos].cantidad) {
				total = total + lista.productos[pos].precio;
			}
			else if (lista.productos[pos].cantidad ==0) {
				cout << "El producto" << lista.productos[pos].denominacion << "es inexistente" << endl;
			}
			else {
				cout << "No hay suficiente cantidad de" << lista.productos[pos].denominacion << endl;
			}
		}
	}
	cout << "El precio a pagar es de:" << total << endl;
}
void mostraragotados(tListaProductos lista) {

	for (int i = 0; i < lista.cont; i++) {
		if (lista.productos[i].cantidad ==0) {


			cout << lista.productos[i].denominacion <<  endl;
		}
	}
}
int menu()
{
	int opcion = -1;

	while (opcion < 1 || opcion > 3)
	{
		cin >> opcion;
	}

	return opcion;
}