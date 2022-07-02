#pragma once
#include <iostream>
using namespace std;
#include "Coordenada.h";
#ifndef MATRIZCHAR_H
#define  MATRIZCHAR_H

const int DIM_MAX = 64;
typedef unsigned char uint8;
struct tMatrizChar
{
	int filas, columnas;
	uint8 matriz[DIM_MAX][DIM_MAX];
};
//Prototipos;
bool cargar(tMatrizChar& mat, istream& ent);
ostream& operator<< (ostream& out, tMatrizChar mat);
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool swapF(tMatrizChar& mat, int f1, int f2);
bool swapC(tMatrizChar& mat, int c1, int c2);
#endif
