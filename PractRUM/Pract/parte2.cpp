// Autor/a: Nombre y apellidos Carlos Forriol Molina
// email: cforriol@ucm.es
// Compilador y S.O. utilizado W y VS2019
// Nombre del problema Diversion con matrices p1
// Comentario general sobre la solución
// explicando cómo se resuelve el problema

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
const int MAX = 20;
typedef struct {
	int matriz[MAX][MAX];
}tMatriz;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void rotarFila(tMatriz& mat, int numFilas, int  numCol, int c) {
	
	if (c > 0) {
		c--;
		int aux = mat.matriz[c][numFilas];
		for (int i = numCol; i >= 0; i--) {
			mat.matriz[c][i] = mat.matriz[c][i - 1];
		}
		mat.matriz[c][0] = aux;
	}
	else {
		c= abs(c);
		c--;
		int aux = mat.matriz[c][0];
		for (int i = 0; i < numCol;i++) {
			mat.matriz[c][i] = mat.matriz[c][i + 1];
		}
		mat.matriz[c][numFilas] = aux;
	}
}
void rotarCol(tMatriz& mat, int numFilas, int  numCol, int c) {
	if (c > 0) {
		c--;
		int aux = mat.matriz[numFilas-1][c];
		for (int i = numFilas; i >= 0; i--) {
			mat.matriz[i][c] = mat.matriz[i - 1][c];
		}
		mat.matriz[0][c] = aux;
	}
	else {
		c = abs(c);
		c--;
		int aux = mat.matriz[0][c];
		for (int i = 0; i < numFilas; i++) {
			mat.matriz[i][c] = mat.matriz[i + 1][c];
		}
		mat.matriz[numFilas][c] = aux;
	}
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int numFilas, numCol, numTrans,c;
	string tipo;
	tMatriz matriz;
	cin >> numFilas >> numCol;
	if (numFilas == 0 && numCol == 0)return false;
	for (int i = 0; i < numFilas; i++) {
		for (int j = 0; j < numCol; j++) {
			cin >> matriz.matriz[i][j];
		}
	}
	cin >> numTrans;
	for (int i = 0; i < numTrans; i++) {
		cin >> tipo;
		if (tipo == "rotarFila") {
			cin >> c;
			rotarFila(matriz,numFilas, numCol,c);
		}if (tipo == "rotarCol") {
			cin >> c;
			rotarCol(matriz, numFilas, numCol, c);
		}
	}
	for (int i = 0; i < numFilas; i++) {
		for (int j = 0; j < numCol; j++) {
			cout << matriz.matriz[i][j] << " ";

		}
		cout << endl;
	}
	cout << "---";
	// escribir sol

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif
	return 0;
}
