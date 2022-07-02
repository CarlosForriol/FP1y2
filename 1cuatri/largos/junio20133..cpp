#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

const int MAX_CLIENTES = 300;
const int MAX_LLAMADAS = 100;

typedef struct {
	string fecha;
	int duracion;
	double coste;
}tLlamada;

typedef tLlamada arrayllamada[MAX_LLAMADAS];

typedef struct {
	arrayllamada llamada;
	int cont=0;
}tListallamadas;

typedef struct {
	string nif;
	double gastototal;
	tListallamadas llamadas;
}tCliente;

typedef tCliente arraycliente[MAX_CLIENTES];

typedef struct {
	arraycliente cliente;
	int cont=0;
}tListacliente;

bool cargallamadas(tListacliente& lista);
int buscaclientes(tListacliente& lista, string nif);

void mostrarllamada(tListacliente& lista, int i, int j);
void mostrarcliente(tListacliente& lista, int i);
void muestraclientes(tListacliente& lista);
double descuento();

int main() {
	cargallamadas(lista);

}

bool cargallamadas(tListacliente& lista) {
	bool caso = true;
	
	string nif;
	int i = 0;
	double total = 0;
	if (!archivo.is_open) {
		caso = false;
	}
	else {
		archivo >> lista.cliente[i].nif;
		while (lista.cliente[i].nif != "X") {
			for (int j = 0; j < lista.cont;j++) {

				if (lista.cliente[i].nif == nif) {
					archivo >> lista.cliente[i].llamadas.llamada[lista.cliente[i].llamadas.cont].fecha;
					archivo >> lista.cliente[i].llamadas.llamada[lista.cliente[i].llamadas.cont].duracion;

					total = 0.15 + (0.08 *60* lista.cliente[i].llamadas.llamada[lista.cliente[i].llamadas.cont].duracion);
					lista.cliente[i].llamadas.llamada[lista.cliente[i].llamadas.cont].coste = total;
					lista.cliente[i].gastototal = total;

					lista.cont++;
				}
				else {
					lista.cliente[i].nif = nif;
					archivo >> lista.cliente[i].llamadas.llamada[lista.cliente[i].llamadas.cont].fecha;
					archivo >> lista.cliente[i].llamadas.llamada[lista.cliente[i].llamadas.cont].duracion;

					total = 0.15 + (0.08 * 60 * lista.cliente[i].llamadas.llamada[lista.cliente[i].llamadas.cont].duracion);
					lista.cliente[i].llamadas.llamada[lista.cliente[i].llamadas.cont].coste = total;
					lista.cliente[i].gastototal = total + lista.cliente[i].gastototal;
					lista.cont++;
						
				}
				
			}
			i++;
			archivo >> nif;
		}
		
	}
	archivo.close();
	return caso;
	
}

int buscaclientes(tListacliente& lista, string nif) {
	int pos = -1;
	int i = 0;
	while (pos == -1 && i < lista.cont) {
		if (lista.cliente[i].nif == nif) {
			pos = i;
		}
		i++;
	}
	return pos;
}
void insertallamada(tListacliente& lista,string nif,int pos) { // string fecha, int duracion

	if (lista.cliente[pos].nif == nif) {
		cout << "Este nif ya existe" << endl;
	}
	else {
		lista.cliente[pos].nif = nif;
	}
}
void mostrarllamada(tListacliente& lista, int i,int j) {
	cout << endl;
	cout << lista.cliente[i].llamadas.llamada[j].fecha << " " << lista.cliente[i].llamadas.llamada[j].duracion << "seg.";
	cout << lista.cliente[i].llamadas.llamada[j].coste << "Eur" << endl;

}

void mostrarcliente(tListacliente& lista,int i) {
	cout << endl;
	cout << lista.cliente[i].nif << endl;
	for (int j= 0; j < lista.cont; j++) {
	
		mostrarllamada(lista,i, j);
	}
	cout << "Coste Valor total  de las llamadas:" << lista.cliente[i].gastototal << endl;
	
}
		
void muestraclientes(tListacliente& lista) {
	for (int i = 0; i < lista.cont;i++) {
		mostrarcliente(lista, i);
	}
}
double descuento(tListacliente& lista) {

}
