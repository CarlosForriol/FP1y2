#ifndef SOPORTE_H
#define SOPORTE_H
#include "fichas.h"
struct tSoporte {
	int cont = 0;
	int capacidad;
	tFicha * ficha;
};
void iniSoporte(tSoporte& soporte);
void mostrar(const tSoporte& soporte);
void ordenarPorColor(tSoporte& soporte);
void ordenarPorNum(tSoporte& soporte);
void mostrarSeries(tSoporte soporte);
void mostrarEscaleras(tSoporte soporte);
void nuevaFicha(tSoporte& soporte, tFicha ficha);
#endif

