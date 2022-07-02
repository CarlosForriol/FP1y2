// Autor/a: Nombre y apellidos Carlos Forriol Molina y Ruben Gómez Escalonilla
// email:cforriol@ucm.es y rubgom05@ucm.es
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "MatrizChar.h"


bool cargar(tMatrizChar& mat, istream& ent) { // revisar
	int fila = 0;
	bool ok = true;
	ent >> mat.filas;
	ent >> mat.columnas;
	while (fila < mat.filas && ok) {
		int col = 0;
		while (col < mat.columnas && ok) {

			ent >> mat.matriz[fila][col];
			if (ent.fail()) ok = false;
			else ++col;
		}
		if (ok) ++fila;
	}
	return ok;
}
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2) {
	bool igual = true;
	int i = 0, j = 0;
	while (i < mat1.filas && igual) {
		while (i < mat1.columnas && igual) {
			if (mat1.matriz[i][j] != mat2.matriz[i][j]) {
				igual = false;
			}
			i++;
			j++;
		}
	}
	return igual;
}
void mostrar(tMatrizChar const& mat) {
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {
			//mostar numero de filas y columnas

			colorCTA(0, int(mat.matriz[i][j]) - int('0'));
			cout << "  ";

		}
		colorCTA(15, 0);
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
ostream& operator<< (ostream& out, tMatrizChar mat) { //Mostrar

	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {
			out << mat.matriz[i][j] << " ";
		}
		out << endl;
	}
	out << "---" << endl;
	return out;
}
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool ok = pos1.fila < mat.filas&&
		pos1.fila > -1 &&
		pos1.columna < mat.columnas&&
		pos1.fila > -1 &&
		pos2.fila < mat.filas&&
		pos2.fila > -1 &&
		pos2.columna < mat.columnas&&
		pos2.fila > -1;
	if (ok) {
		uint8 aux;
		aux = mat.matriz[pos1.fila][pos1.columna];
		mat.matriz[pos1.fila][pos1.columna] = mat.matriz[pos2.fila][pos2.columna];
		mat.matriz[pos2.fila][pos2.columna] = aux;
	}
	return ok;
}
bool swapF(tMatrizChar& mat, int f1, int f2) {
	int aux;

	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {
			if (i == f1) {
				aux = mat.matriz[i][j];
				mat.matriz[i][j] = mat.matriz[f2][j];
				mat.matriz[f2][j] = aux;
			}
		}
		swap(mat, {}, {});
	}
	return true;
}
bool swapC(tMatrizChar& mat, int c1, int c2) {
	int aux;
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {

			if (j == c1) {
				aux = mat.matriz[i][j];
				mat.matriz[i][j] = mat.matriz[i][c2];
				mat.matriz[i][c2] = aux;
			}
		}
		swap(mat, {}, {});
	}


	return true;
}
bool voltearF(tMatrizChar& mat, int f) {
	int aux;
	int ini = 0;
	int fin = mat.columnas - 1;
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {

			if (i == f) {
				while (ini < fin) {
					aux = mat.matriz[i][ini];
					mat.matriz[i][ini] = mat.matriz[i][fin];
					mat.matriz[i][fin] = aux;
					ini++;
					fin--;
				}

			}
		}
		swap(mat, {}, {});
	}
	return true;
}
bool voltearC(tMatrizChar& mat, int c) {
	int aux;
	int ini = 0;
	int fin = mat.filas - 1;
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {

			if (j == c) {
				while (ini < fin) {
					aux = mat.matriz[ini][j];
					mat.matriz[ini][j] = mat.matriz[fin][j];
					mat.matriz[fin][j] = aux;
					ini++;
					fin--;
				}

			}
		}
		swap(mat, {}, {});
	}
	return true;
}
bool swapD(tMatrizChar& mat, int d) {
	int aux;
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {

			if (j == d) {
				aux = mat.matriz[i][j];
				mat.matriz[i][j] = mat.matriz[j][i];
				mat.matriz[j][i] = aux;
			}
		}
		d++;
		swap(mat, {}, {});
	}
	return true;
}
bool voltearD(tMatrizChar& mat, int d) {
	int aux;
	int fin = mat.columnas - 1;
	int ini = mat.filas - 1;
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {
			if (j == d) {
				if (i < ini - j) {
					aux = mat.matriz[i][j];
					mat.matriz[i][j] = mat.matriz[ini - j][fin - i];
					mat.matriz[ini - j][fin - i] = aux;
				}
			}
		}
		d++;
		swap(mat, {}, {});
	}
	return true;
}
void voltearV(tMatrizChar& mat) {
	for (int i = 0; i < mat.filas; i++) {
		voltearF(mat, i);
	}
}
void voltearH(tMatrizChar& mat) {
	for (int i = 0; i < mat.columnas; i++) {
		voltearC(mat, i);
	}
}
bool voltearID(tMatrizChar& mat) {
	for (int i = 0; i < mat.columnas; i++) {
		swapD(mat, i);
	}
	return true;
}
void RotarD(tMatrizChar& mat) {
	tMatrizChar aux;
	int aux1;
	aux.filas = mat.columnas;
	aux.columnas = mat.filas;
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.columnas; j++) {

			aux.matriz[j][aux.columnas - 1 - i] = mat.matriz[i][j];
		}
	}
	mat.columnas = aux.columnas;
	mat.filas = aux.filas;
	for (int i = 0; i < aux.filas; i++) {
		for (int j = 0; j < aux.columnas; j++) {
			mat.matriz[i][j] = aux.matriz[i][j];
		}
	}
}
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	const int incF[] = { 1,1,0,-1,-1,-1,0,1 };
	const int incC[] = { 0,1,1,1,0,-1,-1,-1 };
	int aux;
	for (int dir = 0; dir < 8; dir++) {

		int aux = mat.matriz[pos1.fila + incF[dir]][pos1.columna + incC[dir]];
		mat.matriz[pos1.fila + incF[dir]][pos1.columna + incC[dir]] = mat.matriz[pos2.fila + incF[dir]][pos2.columna + incC[dir]];
		mat.matriz[pos2.fila + incF[dir]][pos2.columna + incC[dir]] = aux;
	}
	return 0;
}
