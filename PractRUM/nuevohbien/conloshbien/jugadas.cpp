#include "jugadas.h"
void eliminaFichas(tSoporte& soporte, const tJugada jugada) {
	for (int i = 0; i < soporte.cont; i++) {
		for (int j = 0; j < jugada.numFichas; j++) {
			if (soporte.ficha[i].color == jugada.fichas[j].color && soporte.ficha[i].numFicha == jugada.fichas[j].numFicha) {

				for (int x = i; x < soporte.cont - 1; x++) {
					soporte.ficha[x].color = soporte.ficha[x + 1].color;
					soporte.ficha[x].numFicha = soporte.ficha[x + 1].numFicha;
				}

			}
		}

	}
	soporte.cont -= jugada.numFichas;
	int cont = 0;
	for (int i = 0; i < soporte.cont; i++) {
		if (soporte.ficha[i].numFicha == -1)cont++;
	}
	if (cont == 8) {
		soporte.capacidad -= 4;
	}
}
int buscar(const tJugada jugada, tFicha ficha) {
	int pos = -1;
	for (int i = 0; i < jugada.numFichas; i++) {//Size Jugada
		if (jugada.fichas[i].numFicha == ficha.numFicha && jugada.fichas[i].color == ficha.color) {
			pos = i;
		}
	}
	return pos;
}
void iniJugada(tJugada& jugada) {
	jugada.fichas = new tFicha[MAXFICHAS + 1];
	jugada.numFichas = 0;
	for (int i = 0; i < INIFICHAS + 1; i++) {
		jugada.fichas[i].color = libre;
		jugada.fichas[i].numFicha = -1;
	}
}

int nuevaJugada(tSoporte& soporte, tJugada jugada) {
	bool okSerie = true;
	bool okEsc = true;
	int cont = 0;
	for (int i = 1; jugada.fichas[i].numFicha != -1 && i < NUMFICHAS && (okSerie || okEsc); i++) {
		if (jugada.fichas[i].numFicha != jugada.fichas[0].numFicha) okSerie = false;
		if (jugada.fichas[i - 1].numFicha + 1 != jugada.fichas[i].numFicha) okEsc = false;
		cont = i;
	}
	if ((okSerie || okEsc) && cont >= 2) {
		cout << "Jugada: ";
		mostrar(jugada);
		if (okSerie)cout << " Serie Correcta ";
		else cout << " Escalera Correcta ";

		eliminaFichas(soporte, jugada);
	}
	else {
		cout << "Jugada Incorrecta" << endl;
		cont = -1;
	}
	cout << endl;
	return cont;
}
bool ponerFicha(tJugada& jugada, tFicha ficha) {
	bool escalera = false;
	bool ok = false;
	if (jugada.numFichas >= 2) {
		if (jugada.fichas[0].color == jugada.fichas[1].color) {
			escalera = true;
		}
	}
	if (escalera) {
		if (jugada.fichas[0].numFicha == ficha.numFicha + 1) {

			for (int i = 0; i < jugada.numFichas - 1; i++) {
				jugada.fichas[i + 1].numFicha= jugada.fichas[i].numFicha;
				jugada.fichas[i + 1].color= jugada.fichas[i].color;
			}

			jugada.fichas[0] = ficha;

			jugada.numFichas++;
			ok = true;
		}
		else if (jugada.fichas[jugada.numFichas - 1].numFicha + 1 == ficha.numFicha) {
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
		colorTexto(jugada.fichas[i].color);
		cout << " " << jugada.fichas[i].numFicha << " ";
		colorTexto(blanco);

	}
}