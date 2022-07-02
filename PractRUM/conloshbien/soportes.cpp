#include "soportes.h"

int menor(const tSoportes soportes) {
	int jugMenor = 0;
	int contActual = 0;
	int ContMenor = 500;
	for (int i = 0; i < NUMJUGADORES; i++) {
		for (int j = 0; j < soportes.soportes[i]->cont; j++) {
			contActual += soportes.soportes[i]->ficha[j].numFicha;
		}
		if (contActual < ContMenor) {
			ContMenor = contActual;
			jugMenor = i;
		}
		contActual = 0;
	}
	return jugMenor;
}