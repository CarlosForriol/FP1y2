#pragma once
#ifndef SOPORTES_H
#define SOPORTES_H

#include <iostream>
#include"soporte.h"
#include"Bolsa.h"
typedef tSoporte tListaSoportes[NUMJUGADORES];

struct tSoportes {
	int numJugadores = 0;
	tListaSoportes  *soportes;
};
int menor(const tSoportes soportes);
void delSoportes(tSoportes& soportes);

#endif
