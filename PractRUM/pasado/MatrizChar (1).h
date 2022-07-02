#ifndef MATRIZCHAR_H
#define  MATRIZCHAR_H
#pragma once
// Autor/a: Nombre y apellidos Carlos Forriol Molina y Ruben Gómez Escalonilla
// email:cforriol@ucm.es y rubgom05@ucm.es
#include <iomanip>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Coordenada.h"
#include "UtilidadesSys.h"
//#ifndef MATRIZCHAR_H
//#define  MATRIZCHAR_H

const int DIM_MAX = 64;
typedef unsigned char uint8;
struct tMatrizChar
{
	int filas, columnas;
	uint8 matriz[DIM_MAX][DIM_MAX];
};
//Prototipos;
bool cargar(tMatrizChar& mat, istream& ent);
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2);
void mostrar(tMatrizChar const& mat);
ostream& operator<< (ostream& out, tMatrizChar mat);
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool swapF(tMatrizChar& mat, int f1, int f2);
bool swapC(tMatrizChar& mat, int c1, int c2);
bool voltearF(tMatrizChar& mat, int f);
bool voltearC(tMatrizChar& mat, int c);
bool swapD(tMatrizChar& mat, int d);
bool voltearD(tMatrizChar& mat, int d);
void voltearV(tMatrizChar& mat);
void voltearH(tMatrizChar& mat);
bool voltearID(tMatrizChar& mat);
void RotarD(tMatrizChar& mat);
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2);
#endif