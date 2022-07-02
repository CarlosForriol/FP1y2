#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

const int N_STK = 10;

typedef struct {
	string compania;
	double precio=0;
	int unidades=0;

}tStock;

typedef tStock tStockArray[N_STK];

typedef struct {
	tStockArray stockArray;
	int cont=0;
}tStockLista;

bool cargar(tStockLista& lista);
double valorTotal(tStockLista& lista);
void mostrar(tStockLista& lista);
int encontrarcompania(string compania, tStockLista lista);
void procesar(tStockLista lista);
void guardar(tStockLista lista);

int main() {
	tStockLista lista;
	if (cargar(lista)) {
		mostrar(lista);
		procesar(lista);
		mostrar(lista);
		guardar(lista);
	}
	return 0;
}

bool cargar(tStockLista &lista) {
	ifstream archivo;
	bool caso = false;
	int i = 0;
	archivo.open("stocks.txt");
	if (!archivo.is_open()) {
		bool caso = false;
		cout << "No se pudo cargar el archivo" << endl;
	}
	lista.cont = 0;
	
	archivo >> lista.stockArray[i].compania;
	while (i < N_STK && lista.stockArray[i].compania != "#" ) {
		archivo >> lista.stockArray[i].precio;
		archivo >> lista.stockArray[i].unidades;
		lista.cont++;
		i++;
		archivo >> lista.stockArray[i].compania;

	}
	if (lista.cont < N_STK) {
		caso = false;
		cout << "La lista contiene pocos elementos" << endl;
	}
	archivo.close();
	return caso;
}

double valorTotal(tStockLista& lista) {
	double total=0;
	for (int i = 0; i < N_STK; i++) {
		total = (lista.stockArray[i].precio * lista.stockArray[i].unidades);
	}

	return total;

}

void mostrar(tStockLista& lista) {
	cout << endl << setw(10) << left << "COMPANIA" << setw(20) << left << "UNIDADES" << setw(10) << right << "PRECIO" << endl << endl;
	for (int i = 0; i < N_STK; i++) {
		cout << setw(10) << left << lista.stockArray[i].compania << setw(20) << left << lista.stockArray[i].unidades;
		cout << setw(10) << fixed << right << setprecision(2) <<" $"<< lista.stockArray[i].precio << right << endl;
	}
	cout << "Valor Total" << valorTotal(lista) << endl << endl;
}

int encontrarcompania(string compania,tStockLista lista) {
	int pos = -1;
	
	for (int i = 0; i < N_STK; i++) {
		if (compania == lista.stockArray[i].compania) {
			pos = i;
		}
	}
	return pos;
}

void procesar(tStockLista lista) {
	ifstream archivo;
	bool caso = false;
	char op;
	string compania;
	int unidades;
	int pos;

	archivo.open("week.txt");

	if (!archivo.is_open()) {
		bool caso = false;
		cout << "No se pudo cargar el archivo" << endl;
	}
	archivo >> op;
	while (op != 'X') {
		archivo >> compania;
		archivo >> unidades;
		pos = encontrarcompania(compania, lista);
		cout << op << " " << compania << " " << unidades;
		if (pos != -1) {
			if (op == 'B') {
				lista.stockArray[pos].unidades = unidades;
				cout << "OK" << endl;
			}
			else if(op == 'S'){
				if (lista.stockArray[pos].unidades >= unidades) {
					lista.stockArray[pos].unidades = unidades;
					cout << "OK" << endl;
				}
				else {
					cout << "Error:No suficientes unidades" << endl;
				}
			}
			else if (op == 'P') {
				lista.stockArray[pos].precio = unidades;
				cout << "OK" << endl;
			}
		}
		else {
			cout << "Error:Compania no encontrada" << endl;
		}
		archivo >> op;
	}
	cout << endl;

}
void guardar(tStockLista lista) {
	ofstream archivo;
	archivo.open("stocks.txt");
	if (!archivo.is_open()) {
		cout << "No se ha podido abrir el archivo" << endl;
	}
	else {
		for (int i = 0; i < N_STK; i++) {
			archivo << lista.stockArray[i].compania << " " << lista.stockArray[i].precio << " " << lista.stockArray[i].unidades << endl;
		}
		archivo << "#" << endl;
	}
}