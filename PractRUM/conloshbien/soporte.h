#ifndef SOPORTE_H
#define SOPORTE_H
#include "fichas.h"
#include "jugadas.h"
struct tSoporte {
	int cont = 0;
	int capacidad = 8;
	tFicha * ficha;
};
void iniSoporte(tSoporte& soporte);
void mostrar(const tSoporte& soporte);
void ordenarPorColor(tSoporte& soporte);
void ordenarPorNum(tSoporte& soporte);
void mostrarSeries(tSoporte soporte);
void mostrarEscaleras(tSoporte soporte);
void eliminaFichas(tSoporte& soporte, const tJugada jugada);
#endif

