#ifndef COORDENADA_H
#define  COORDENADA_H
#pragma once
#include <iomanip>
#include <fstream>
#include <iomanip>
using namespace std;

//#ifndef COORDENADA_H
//#define  COORDENADA_H
struct tCoor {
	int fila = 0, columna = 0;
};

bool operator != (tCoor c1, tCoor c2);
bool operator == (tCoor c1, tCoor c2);
//tCoor operator + (tCoor c1, tCoor c2);

#endif
