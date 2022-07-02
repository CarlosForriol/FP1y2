#include <fstream>
#include<iostream>
#include<string>

using namespace std;



const int MARCA_I = -1;
const string MARCA_S = "XXX";

const int NUM_INTERVALOS = 5;
typedef enum {particular, pyme, industria}tTipo;

typedef struct {
	string idContrato;
	double consumo;
	tTipo tipo;
}tCliente;
typedef struct{
	int sup, frec;
}tPar;
typedef tPar tTablaFrec[NUM_INTERVALOS];

bool cargarIntervalos(tTablaFrec tabla);
void mostrarTabla(tTablaFrec tabla);
bool buscarIntervalo(tTablaFrec tabla, const  tCliente& cliente, int& pos);
bool frecuenciaConsumo(tTablaFrec tabla, tTipo tipo);

int main() {
	tTablaFrec tabla;
	cout << "Calculamos la frecuencias de consumo de los clientes de tipo PYME." << endl;
	if (cargarIntervalos(tabla)) {
		if (frecuenciaConsumo(tabla, pyme)) {
			mostrarTabla(tabla);
		}
		else {
			cout << "Error en archivo consumos\n";
		}
	}
	else {
		cout << "Error en archivo intervalos\n";
	}
	cin.get();
	return 0;

}


bool cargarIntervalos(tTablaFrec tabla) {
	bool caso;
	ifstream archivo;
	archivo.open("intervalos.txt");
	if (!archivo.is_open()) {
		caso = false;
	}
	else {
		int ant= 0, cont=0, sup;
		archivo >> sup;
		while (sup != MARCA_I && cont < NUM_INTERVALOS && sup > ant) {
			tabla[cont].sup = sup;
			tabla[cont].frec = 0;
			cont++;
			ant = sup;
			archivo >> sup;
		}
		if (sup == -1 && cont == NUM_INTERVALOS) {
			caso = true;
		}
		else {
			caso = false;
		}
	}
	return caso;
}
void mostrarTabla(tTablaFrec tabla) {
	cout << "Tabla de frecuencias por consumo:" << endl;
	int ant = 0;// Alomejor aqui esta mal
	for (int i = 0; i < NUM_INTERVALOS; i++) {
		cout << "De " << ant << " a " << tabla[i].sup << ": " << tabla[i].frec << endl;   //  setw(20) << 
		ant = tabla[i].sup;
		
	}
}
bool buscarIntervalo(tTablaFrec tabla,const  tCliente & cliente, int & pos) {
	bool caso = false;
	pos = 0;
	while (pos < NUM_INTERVALOS && !caso) {
		if (cliente.consumo > tabla[pos].sup) {
			pos++;
		}
		else{
		
			caso = true;
		}
	}
}
bool frecuenciaConsumo(tTablaFrec tabla, tTipo tipo) {
	bool caso;
	ifstream archivo;
	archivo.open("consumos.txt");
	if (!archivo.is_open()) {
		caso = false;
	}
	else {
		int pos, tipo;
		tCliente cliente;
		archivo >> cliente.consumo;
		while (cliente.consumo != MARCA_I) {
			archivo >> tipo;
			cliente.tipo = tTipo(tipo);
			getline(archivo, cliente.idContrato);
			if (cliente.tipo == tipo && buscarIntervalo(tabla, cliente, pos)) {
				tabla[pos].frec++;
				archivo >> cliente.consumo;
			}
			caso = true;
		}
	}
	return caso;
}