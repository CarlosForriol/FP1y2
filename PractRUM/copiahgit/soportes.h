#ifndef SOPORTES_H
#define SOPORTES_H
#include "soporte.h"
const int NUMJUGADORES = 2;
typedef tSoporte tListaSoportes[NUMJUGADORES];

struct tSoportes {
	int numJugadores = 0;
	tListaSoportes soportes;
};
int menor(const tSoportes soportes);
void delSoportes(tSoportes& soportes);
#endif