#include "MatrizChar.h";
#include <iomanip>
#include <fstream>
#include <iomanip>
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
	bool ok = pos1.fila < mat.filas &&
		pos1.fila > -1 &&
		pos1.columna < mat.columnas &&
		pos1.fila > -1 &&
		pos2.fila < mat.filas &&
		pos2.fila > -1 &&
		pos2.columna < mat.columnas &&
		pos2.fila > -1;
	if (ok) {
		uint8 aux;
		aux = mat.matriz[pos1.fila][pos1.columna];
		mat.matriz[pos1.fila][pos1.columna] = mat.matriz[pos2.fila][pos2.columna];
		mat.matriz[pos2.fila][pos2.columna] = aux;
	}
	return ok;
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

