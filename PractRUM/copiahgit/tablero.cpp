#include "tablero.h"

void nuevaJugada(tTablero& tablero, tJugada jugada) {
	tablero.jugadas[tablero.contTablero] = jugada;

}

void mostrarIndices(int num) {
	cout << "          " << 1 << "  ";
	for (int i = 2; i < num + 1; i++) {
		cout << i << "  ";
	}
	cout << endl;
}
bool jugar(tTablero& tablero, tSoporte& soporte) {
	tJugada jugada;
	bool jugadas = false, colocada = false;
	int cont = 0, pos = -1;
	mostrar(soporte);
	mostrarIndices(soporte.cont);

	cout << "Fichas(0 al final)";


	while (pos != 0) {
		cin >> pos;
		if (pos > 0 && pos <= soporte.cont) {
			jugada.fichas[jugada.numFichas] = soporte.ficha[pos - 1];
			cont++;
			jugada.numFichas++;
		}
	}
	mostrar(tablero);
	if (cont == 1) {
		cout << "Jugadas del tablero donde poner la ficha: ";
		cin >> pos;
		if (ponerFicha(tablero.jugadas[pos - 1], jugada.fichas[0])) {
			cout << "-> Colocada" << endl;
			colocada = true;
			jugadas = true;
		}
	}
	else if (nuevaJugada(soporte, jugada) != -1) {
		tablero.jugadas[tablero.contTablero] = jugada;
		tablero.contTablero++;
		jugadas = true;
	}
	return jugadas;
}

void mostrar(tTablero tablero) {
	cout << "Tablero:" << endl;
	for (int i = 0; i < tablero.contTablero; i++) {
		cout << i + 1 << ": ";
		mostrar(tablero.jugadas[i]);

		cout << endl;
	}
	cout << endl;
}
