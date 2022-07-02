
#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include"jugadas.h"
#include "soporte.h"
#include"Bolsa.h"
typedef tJugada  tListaJugadas[NUMFICHAS * 2];

using namespace std;
struct tTablero {
	int contTablero = 0;
	tListaJugadas *jugadas;

};
typedef tTablero tablero[NUMFICHAS+1];
void delTablero(tTablero& tablero);
void nuevaJugada(tTablero& tablero, tJugada jugada);
bool jugar(tTablero& tablero, tSoporte& soporte);
void mostrar(tTablero tablero);
void mostrarIndices(int num);
#endif
