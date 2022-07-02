#include <iomanip>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Fichas.h"
using namespace std;

bool operator==(tFicha izq, tFicha der) {
	return izq.numFicha == der.numFicha && izq.color == der.color;
}
void mostrar(tFicha ficha) {
	cout << ficha.numFicha << "  " << ficha.color << "  ";
}
