#ifndef FICHAS_H
#define FICHAS_H

#include "colores.h"
const int MAXFICHAS = 50;
const int INIFICHAS = 8;
const int NUMFICHAS = 8;
struct tFicha {
	int numFicha = -1;
	tColor color = libre;
};

bool operator==(tFicha izq, tFicha der);
void mostrar(tFicha ficha);

#endif
