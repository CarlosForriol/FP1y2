#ifndef FICHAS_H
#define FICHAS_H

#include <iostream>

#include "Colores.h"
#include"Bolsa.h"
struct tFicha {
	int numFicha = NULL;
	tColor color = libre;
};
bool operator==(tFicha izq, tFicha der);
void mostrar(tFicha ficha);
#endif

