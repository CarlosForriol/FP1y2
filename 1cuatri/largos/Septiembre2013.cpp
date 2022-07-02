#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

const int MAX_CLIENTES = 100;

typedef struct {
	int categoria;
	
	int dias;
	double precio;
}tAlquiler;

typedef struct {
	int dia = 0;
	int mes = 0;
	int ano = 0;
}tFecha;

typedef struct {
	string nif;
	tAlquiler alquiler;
	tFecha fecha;
}tCliente;

typedef tCliente tarrayCliente[MAX_CLIENTES];

typedef struct {
	tarrayCliente cliente;
	int cont;
}tListaCliente;

bool cargar(tListaCliente& lista);
int Buscarcliente(tListaCliente& lista, string nif);
void insertar(tListaCliente& lista, string nif, int pos);
double costedias(tListaCliente& lista);
void mostrar(tListaCliente lista, int pos);






int main() {

}

bool cargar(tListaCliente& lista) {
	bool caso = true;
	ifstream archivo;
	archivo.open("alquileres.txt");
	char basura;
	
	if (!archivo.is_open()) {
		caso = false;
	}
	else {
		for (int i = 0; i < MAX_CLIENTES; i++) {
			archivo>> lista.cliente[i].nif;
			lista.cont = 0;
			while (lista.cliente[i].nif != "X") {
				archivo.ignore();
				archivo >> lista.cliente[i].alquiler.categoria;
				archivo.get(basura);
				archivo >> lista.cliente[i].fecha.dia;
				archivo >> lista.cliente[i].fecha.mes;
				archivo >> lista.cliente[i].fecha.ano;
				archivo.get(basura);
				archivo >> lista.cliente[i].alquiler.dias;
				i++;
				lista.cont++;
				archivo >> lista.cliente[i].nif;
			}
		}
	}
	archivo.close();
	return caso;
}

int Buscarcliente(tListaCliente& lista, string nif) {
	int pos = -1;
	int i = 0;
	while (pos ==-1 && i<lista.cont) {
		if (lista.cliente[i].nif == nif) {
			pos = i;
		}
		i++;
	}
	return pos;
}
void insertar(tListaCliente& lista, string nif, int pos) {
	if (lista.cliente[pos].nif == nif) {
		cout << "El nif ya se encuentra en el programa" << endl;
	}
	else {
		lista.cliente[pos].nif = nif;
	}
}

double costedias(tListaCliente& lista) {
	double coste = 0;
	double costet = 0;
	
	for (int i = 0; i < MAX_CLIENTES; i++) {
		if (lista.cliente[i].alquiler.categoria == '0') {
			lista.cliente[i].alquiler.categoria = 1;
		}
		if (lista.cliente[i].alquiler.categoria == '1') {
			lista.cliente[i].alquiler.categoria = 1.5;
		}
		if (lista.cliente[i].alquiler.categoria == '2') {
			lista.cliente[i].alquiler.categoria = 1.5;
		}
		if (lista.cliente[i].alquiler.categoria == '3') {
			lista.cliente[i].alquiler.categoria = 4;
		}

		coste = (23.95 + (32.67 * lista.cliente[i].alquiler.dias * lista.cliente[i].alquiler.categoria));
		costet = (coste * 0, 21) + coste;
	}
	return costet;

}

void mostrar(tListaCliente lista, int pos) {
	if (lista.cliente[pos].alquiler.categoria == '0') {
		cout << "mini" << endl;;
	}
	if (lista.cliente[pos].alquiler.categoria == '1') {
		cout << "Utilitario" << endl;
	}
	if (lista.cliente[pos].alquiler.categoria == '2') {
		cout << "Monovolumen" << endl;
	}
	if (lista.cliente[pos].alquiler.categoria == '3') {
		cout << "Lujo" << endl;
	}
	cout << endl;
	cout << lista.cliente[pos].nif << endl;
	cout << lista.cliente[pos].alquiler.categoria << " " << lista.cliente[pos].fecha.dia << "/" << lista.cliente[pos].fecha.mes << "/" << lista.cliente[pos].fecha.ano << " " << lista.cliente[pos].alquiler.dias << "dias" << costedias(lista) << "$" << endl;
	cout << "Coste total alquileres del cliente:" << costedias(lista) << endl;
}