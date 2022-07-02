#ifndef BOLSA_H
#define BOLSA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

#include"Fichas.h"
#include"Soportes.h"
using namespace std;
const int MAXFICHAS = 50;
const int NUMJUGADORES = 2;
const int NUMFICHAS = 8;
const int INIFICHAS = 8;

typedef tFicha tMatBolsa[NUMFICHAS][NUMFICHAS];

struct tBolsa {
	int numFichas = 0;
	tMatBolsa * bolsa;
};
void inicializarBolsa(tBolsa& bolsa);
tFicha robar(tBolsa& bolsa);
void mostrar(tBolsa& bolsa);
void repartir(tBolsa& bolsa, tSoportes& soportes);
void delBolsa(tBolsa& bolsa);
#endif
