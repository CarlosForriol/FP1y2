#ifndef SOPORTE_H
#define SOPORTE_H

#include <iostream>
#include "Fichas.h"
#include"Jugadas.h"
#include"Bolsa.h"
struct tSoporte {
	int cont = 0;
	int capacidad = 8;
	tFicha * ficha;
};
void nuevaFicha(tSoporte& soporte, tFicha& ficha);
void iniSoporte(tSoporte& soporte);
void mostrar(const tSoporte& soporte);
void ordenarPorColor(tSoporte& soporte);
void ordenarPorNum(tSoporte& soporte);
void mostrarSeries(tSoporte soporte);
void mostrarEscaleras(tSoporte soporte);
void eliminaFichas(tSoporte& soporte, const tJugada jugada);
int nuevaJugada(tSoporte& soporte, tJugada jugada);
void eliminaFichas(tSoporte& soporte, const tJugada jugada);
#endif