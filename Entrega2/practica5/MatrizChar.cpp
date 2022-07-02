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