#include<iostream>
using namespace std;
#include"jugadas.h"
#include "Fichas.h"
int buscar(const tJugada jugada, tFicha ficha) {
	int pos = -1;
	for (int i = 0; i < jugada.numFichas; i++) {//Size Jugada
		if (jugada.fichas[i]->numFicha == ficha.numFicha && jugada.fichas[i]->color == ficha.color) {
			pos = i;
		}
	}
	return pos;
}
void iniJugada(tJugada jugada) {
	for (int i = 0; i < INIFICHAS + 1; i++) {
		jugada.fichas[i]->color = libre;
		jugada.fichas[i]->numFicha= -1;
	}
}
bool ponerFicha(tJugada& jugada, tFicha* ficha) {
	bool escalera = false;
	bool ok = false;
	if (jugada.numFichas >= 2) {
		if (jugada.fichas[0]->color== jugada.fichas[1]->color) {
			escalera = true;
		}
	}
	if (escalera) {
		if (jugada.fichas[0]->numFicha == ficha->numFicha + 1) {

			for (int i = 0; i < jugada.numFichas - 1; i++) {
				jugada.fichas[i + 1]->numFicha= jugada.fichas[i]->numFicha;
				jugada.fichas[i + 1]->color = jugada.fichas[i]->color;
			}

			jugada.fichas[0] = ficha;
			jugada.numFichas++;
			ok = true;
		}
		else if (jugada.fichas[jugada.numFichas - 1]->numFicha+ 1 == ficha->numFicha) {
			jugada.fichas[jugada.numFichas] = ficha;
			jugada.numFichas++;
			ok = true;
		}
	}
	else {
		jugada.fichas[jugada.numFichas] = ficha;
		jugada.numFichas++;
		ok = true;
	}
	return ok;
}
void mostrar(const tJugada jugada) {

	for (int i = 0; i < jugada.numFichas; i++) {
		colorTexto(jugada.fichas[i]->color);
		cout << " " << jugada.fichas[i]->numFicha << " ";
		colorTexto(blanco);

	}
}