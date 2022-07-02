#include "soportes.h"

int menor(const tSoportes soportes) {
	int jugMenor = -1;
	int contActual = 0;
	int ContMenor = 500;
	for (int i = 0; i < NUMJUGADORES; i++) {
		for (int j = 0; j < soportes.soportes[i].cont; j++) {
			contActual += soportes.soportes[i].ficha[j].numFicha;
		}
		if (contActual < ContMenor) {
			ContMenor = contActual;
			jugMenor = i;
		}
		contActual = 0;
	}
	return jugMenor;
}
void delSoportes(tSoportes& soportes) {
	for (int i = 0; i < soportes.numJugadores; i++) {
		delete[] soportes.soportes[i].ficha;
		soportes.soportes[i].ficha = nullptr;
		soportes.soportes[i].cont = 0;
	}
	//delete[] soportes.soportes; //borra la memoria
	//soportes.soportes = nullptr;
	/*for (int i = 0; i < soportes.numJugadores; i++) {
		for (int j = 0; j < soportes.soportes[i].cont; j++) {
			delete[] soportes.soportes[i].ficha;
			soportes.soportes[i].ficha = nullptr;
		}
		
		soportes.soportes[i].capacidad = 0;
		soportes.soportes[i].cont = 0;
	}*/
}