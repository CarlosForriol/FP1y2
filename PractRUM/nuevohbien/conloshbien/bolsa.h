#ifndef BOLSA_H
#define BOLSA_H

#include "fichas.h"
#include "soportes.h"
typedef tFicha tMatBolsa[NUMFICHAS][NUMFICHAS];
struct tBolsa {
	int numFichas = 0;
	tMatBolsa * bolsa;
};
void repartir(tBolsa& bolsa, tSoportes& soportes);
void inicializarBolsa(tBolsa& bolsa);
tFicha robar(tBolsa& bolsa);
void mostrar(tBolsa& bolsa);
void delBolsa(tBolsa& bolsa);
#endif