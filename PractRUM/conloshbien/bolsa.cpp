#include "bolsa.h"
#include "soporte.h"
void inicializarBolsa(tBolsa& bolsa) {
	int color = 0;
	for (int i = 0; i < NUMFICHAS; i++) {
		for (int j = 0; j < NUMFICHAS; j++) {
			if (color == 0) {
				bolsa.bolsa[i][j].color = rojo;
			}
			else if (color == 1) {
				bolsa.bolsa[i][j].color = verde;
			}
			else if (color == 2) {
				bolsa.bolsa[i][j].color = azul;
			}
			else if (color == 3) {
				bolsa.bolsa[i][j].color = amarillo;
			}
			bolsa.bolsa[i][j].numFicha = i + 1;
			color++;
			if (color == 4) color = 0;
		}
	}
}
tFicha robar(tBolsa& bolsa) {
	tFicha ficha;
	tSoporte soporte;

	bool encontrado = false;
	int aleat1 = rand() % NUMFICHAS;
	int aleat2 = rand() % NUMFICHAS;
	if (bolsa.bolsa[aleat1][aleat2].numFicha != -1 && bolsa.bolsa[aleat1][aleat2].color != libre) {
		ficha.numFicha = bolsa.bolsa[aleat1][aleat2].numFicha;
		ficha.color = bolsa.bolsa[aleat1][aleat2].color;


		bolsa.bolsa[aleat1][aleat2].numFicha = -1;
		bolsa.bolsa[aleat1][aleat2].color = libre;
	}
	else {
		for (int i = aleat1; i < NUMFICHAS; i++) {
			for (int j = aleat2; j < NUMFICHAS; j++) {
				if (bolsa.bolsa[i][j].numFicha != -1 && bolsa.bolsa[i][j].color != libre) {
					if (encontrado == false) {
						ficha.numFicha = bolsa.bolsa[i][j].numFicha;
						ficha.color = bolsa.bolsa[i][j].color;


						bolsa.bolsa[i][j].numFicha = -1;
						bolsa.bolsa[i][j].color = libre;
						encontrado = true;
					}

				}
			}
		}
		if (encontrado == false) {
			for (int i = 0; i < aleat1; i++) {
				for (int j = 0; j < aleat2; j++) {
					if (bolsa.bolsa[i][j].numFicha != -1 && bolsa.bolsa[i][j].color != libre) {
						if (encontrado == false) {
							ficha.numFicha = bolsa.bolsa[i][j].numFicha;
							ficha.color = bolsa.bolsa[i][j].color;


							bolsa.bolsa[i][j].numFicha = -1;
							bolsa.bolsa[i][j].color = libre;
							encontrado = true;
						}

					}
				}
			}

		}
	}
	return ficha;
}
void mostrar(tBolsa& bolsa) {
	cout << "Bolsa..." << endl;
	for (int i = 0; i < NUMFICHAS; i++) {
		for (int j = 0; j < NUMFICHAS; j++) {
			if (bolsa.bolsa[j][i].color == 0) {
				cout << "rojo" << " " << bolsa.bolsa[j][i].numFicha << "  ";
			}
			if (bolsa.bolsa[j][i].color == 1) {
				cout << "verd" << " " << bolsa.bolsa[j][i].numFicha << "  ";
			}
			if (bolsa.bolsa[j][i].color == 2) {
				cout << "azul" << " " << bolsa.bolsa[j][i].numFicha << "  ";
			}
			if (bolsa.bolsa[j][i].color == 3) {
				cout << "amar" << " " << bolsa.bolsa[j][i].numFicha << "  ";
			}
			if (bolsa.bolsa[j][i].color == 4) {
				cout << "    " << bolsa.bolsa[j][i].numFicha << "  ";
			}
		}
		cout << endl;
	}
}
void repartir(tBolsa& bolsa, tSoportes& soportes) {

	for (int i = 0; i < NUMJUGADORES; i++) {

		soportes.numJugadores++;
		for (int j = 0; j < INIFICHAS; j++) {
			soportes.soportes[i].ficha[j] = robar(bolsa);
			if (soportes.soportes[i].ficha[j].numFicha != -1)soportes.soportes[i].cont++;
		}
	}
}