#ifndef TABLERO_H
#define TABLERO_H
#include "jugadas.h"

typedef tJugada * tListaJugadas[NUMFICHAS * 2];

struct tTablero {
	int contTablero = 0;
	tListaJugadas jugadas;
};
void mostrarIndices(int num);
void nuevaJugada(tTablero& tablero, tJugada jugada);
bool jugar(tTablero& tablero, tSoporte& soporte);
void mostrar(tTablero tablero);
void delTablero( tTablero& tablero);
#endif
