#include "fichas.h"

bool operator==(tFicha izq, tFicha der) {
	return izq.numFicha == der.numFicha && izq.color == der.color;
}
void mostrar(tFicha ficha) {
	cout << ficha.numFicha << "  " << ficha.color << "  ";
}