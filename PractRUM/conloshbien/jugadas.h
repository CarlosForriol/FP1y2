#ifndef JUGADAS_H
#define JUGADAS_H
#include "fichas.h"
#include "soporte.h"
struct tJugada {
	tFicha * fichas[NUMFICHAS + 1];
	int numFichas = 0;
};
int buscar(const tJugada jugada, tFicha ficha);
void iniJugada(tJugada jugada);
bool ponerFicha(tJugada& jugada, tFicha ficha);
void mostrar(const tJugada jugada);

int nuevaJugada(tSoporte& soporte, tJugada jugada);

#endif
