#ifndef JUGADAS_H
#define JUGADAS_H
#include"Bolsa.h"
struct tJugada {
	tFicha * fichas[NUMFICHAS + 1];
	int numFichas = 0;
};
//En el resto del programa simplemente se usará delete
//para eliminar las jugadas auxiliares una vez que ya no se necesiten(pero no las que se
	//añadan al tablero).
int buscar(const tJugada jugada, tFicha ficha);
void iniJugada(tJugada jugada);
bool ponerFicha(tJugada& jugada, tFicha * ficha);
void mostrar(const tJugada jugada);
#endif
