// Nombre del problema Practica1
// Comentario general sobre la solución: usamos modulos
// explicando como se resuelve el problema 


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
#include <iomanip>

// Introduce más librerías si son necesarias
#include "ListaPuzzles.h"


using namespace std;


//ordenar crecete/ decrecient
void ordenarCreciente(tListaPuzzles& lp) {
	int pos;
	tPuzzle* tmp;//alomejor esto no lo necesitamos
	tPuzzle* tmp2;
	// Desde el segundo elemento hasta el último...
	for (int i = 1; i < lp.cont; i++) {
		pos = i;
		// Mientras no al principio y anterior mayor...
		while ((pos > 0) /*&& lp.lista[pos - 1]->nummaxacciones > lp.lista[pos]->nummaxacciones*/) {
			// Intercambiar...
			if (lp.lista[pos - 1]->nummaxacciones < lp.lista[pos]->nummaxacciones) {
				tmp = lp.lista[pos];
				lp.lista[pos] = lp.lista[pos - 1];
				lp.lista[pos - 1] = tmp;

			}
			else if (lp.lista[pos - 1]->nummaxacciones == lp.lista[pos]->nummaxacciones) {
				if (lp.lista[pos - 1]->nomPuzle < lp.lista[pos]->nomPuzle) {
					tmp2 = lp.lista[pos];
					lp.lista[pos] = lp.lista[pos - 1];
					lp.lista[pos - 1] = tmp2;
				}
			}
			pos--;
		}
	}
}
void ordenarDeCreciente(tListaPuzzles& lp) {
	int pos;
	tPuzzle* tmp;
	tPuzzle* tmp2;
	// Desde el segundo elemento hasta el último...
	for (int i = 1; i < lp.cont; i++) {
		pos = i;
		// Mientras no al principio y anterior mayor...
		while ((pos > 0)/* && lp.lista[pos - 1]->nummaxacciones < lp.lista[pos]->nummaxacciones*/) {
			// Intercambiar...
			if (lp.lista[pos - 1]->nummaxacciones > lp.lista[pos]->nummaxacciones) {
				tmp = lp.lista[pos];
				lp.lista[pos] = lp.lista[pos - 1];
				lp.lista[pos - 1] = tmp;

			}
			else if (lp.lista[pos - 1]->nummaxacciones == lp.lista[pos]->nummaxacciones) {
				if (lp.lista[pos - 1]->nomPuzle > lp.lista[pos]->nomPuzle) {
					tmp2 = lp.lista[pos];
					lp.lista[pos] = lp.lista[pos - 1];
					lp.lista[pos - 1] = tmp2;
				}
			}

			pos--;
		}
	}
}
void inicializar(tPuzzlesReunidos& jr) {
	jr->cont = 0;

	//for (int i = 0; i < 2; i++) {//no sabemos 1 o 2

		cargar(jr);
		// alomejor gaurdar

	//}
}
//Solo carga una lista
bool cargar(tPuzzlesReunidos& jr) {//hacerlo para una lista y otra co otra funcion
	tPuzzle  puzzle;
	ifstream archivo;
	string modo;
	char aux;
	bool caso = false;
	archivo.open("datosPuzzles.txt");
	if (archivo.is_open()) {
		caso = true;
		int numcasos;

		// inicializar numero casos
		//leer salto linea despus de num casos (con esto no carga)
		for (int j = 0; j < 2; j++) {
			archivo >> numcasos;
			archivo.get(aux);
			if (j == 0) {
				modo = "1D";
			}
			else {
				modo = "2D";
			}
			for (int i = 0; i < numcasos; i++) {
				jr[j].lista[i] = new tPuzzle;
				getline(archivo, jr[j].lista[i]->nomPuzle);
				getline(archivo, jr[j].lista[i]->nomFichero);
				//archivo >> jr[j].lista[i]->nomPuzle;
				//archivo >> jr[j].lista[i]->nomFichero;
				cargarPuzzle(*(jr[j].lista[i]), modo);//1d o dosd
				jr[j].cont++;
			}
		}

	}
	else {
		cout << "No se pudo cargar el archivo" << endl;
	}
	return caso;
}
void guardar(const tPuzzlesReunidos& jr) {
	ofstream archivo;
	archivo.open("datosPuzzles.txt");
	for (int x = 0; x < 2; x++) {
		guardarLista(jr[x], archivo);

	}
	archivo.close();
}
void guardarLista(const tListaPuzzles& lp, ofstream& archivo) {
	archivo << lp.cont;
	for (int i = 0; i < lp.cont; i++) {
		archivo << lp.lista[i]->nomPuzle;
		archivo << lp.lista[i]->nomFichero;
	}
}
int elegirPuzzle(tListaPuzzles& lp) {
	tPuzzlesReunidos jr;
	int op;

	cout << "Estan disponibles los siguiente retos" << endl;
	for (int i = 0; i < lp.cont; i++) {

		cout << i + 1 << " " << lp.lista[i]->nomPuzle << " con un maximo de " << lp.lista[i]->nummaxacciones << " movimientos" << endl;

	}

	cout << "0 Salir" << endl;
	cout << "-1 Mostrar la lista ordenada de mayor a menor " << endl;
	cout << "-2 Mostrar la lista ordenada de menor a mayor " << endl;
	//solo llamamos al puzle q queramos jugar
	cout << "Elige un reto" << endl;
	cin >> op;
	while (op > lp.cont || op < -2) {
		cout << "Opcion no valida" << endl;
		cout << "Elige un reto" << endl;
		cin >> op;
	}
	/*if (op < lp.cont && op > -3) {//vuelve a pregunat???
		/*if (op == 0) {
			//salir antes menu
			//menu();
			//system
		}*/
		if (op == -1) {
			ordenarCreciente(lp);
		}
		else if (op == -2) {
			ordenarDeCreciente(lp);
		}
		/*else {
			//jpm carga todos
			//jugar();
			//cargarPuzzle(lp.lista[op-1], "_1D.txt");
		}*/

	//}

	return op;
}
bool insertarOrdenado(tListaPuzzles& lp, tPuzzle* p) {// metodo burbuja
	int i = 0, j = 0, pos;
	bool caso = true;
	//buscar x si es igual    ALOMEJOR MOVERLO AL MAIN
	if (buscar(lp, p, pos)) {
		cout << "Ese puzzle ya existe" << endl;
		caso = false;
	}
	else {
		lp.cont++;// te devuelt¡ve ultima posicion
		lp.lista[pos] = p;
		ordenarCreciente(lp);//la ordena otra vez
	}
	return caso;
}
bool operator == (const tPuzzle& puzzle1, const tPuzzle& puzzle2) {//nombre, nombrefichero y numintentos

	return puzzle1.nummaxacciones == puzzle2.nummaxacciones && puzzle1.nomFichero == puzzle2.nomFichero
		&& puzzle1.nomPuzle == puzzle2.nomPuzle;
}
bool buscar(const tListaPuzzles& lp, tPuzzle* p, int& pos) {//bool numintents y nombre operador iguLDAD pnt lista y puntnombe
	bool caso = false;
	//pasas 2 puzles y comparas nombre fichero y acciones
   //cargar(jr);
	for (int i = 0; i < lp.cont; i++) {
		if (p == lp.lista[i]) {
			pos = i;
			caso = true;

		}
	}
	if (caso == false) {
		pos = lp.cont; //ultima posicion
	}
	return caso;
}