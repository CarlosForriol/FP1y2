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
 
void intColumnas(tMatriz& mat, int numFilas,int  numCol,int a, int b) {
	int aux;
	for (int i = 0; i < numFilas; i++) {
		aux = mat.matriz[i][a - 1];
		mat.matriz[i][a - 1] = mat.matriz[i][b - 1];
		mat.matriz[i][b - 1] = aux;
	}
}
void intFilas(tMatriz& mat, int numFilas, int  numCol, int a, int b) {
	int aux;
	for (int i = 0; i < numFilas; i++) {
		aux = mat.matriz[a - 1][i];
		mat.matriz[a - 1][i] = mat.matriz[b - 1][i];
		mat.matriz[b - 1][i] = aux;
	}
}
void abajoDer(tMatriz& mat, int numFilas, int  numCol, int f, int c, int d) {
	
	while (f <numFilas || c  < numCol) {
		
		f++;
		c++;
		if (mat.matriz[f][c] != d)mat.matriz[f][c] = d;
	}
}
void abajoIzq(tMatriz& mat, int numFilas, int  numCol, int f, int c, int d) {

	while (f < numFilas || c >= 0) {
		
		f++;
		c--;
		if (mat.matriz[f][c] != d)mat.matriz[f][c] = d;
	}
}
void arribaDer(tMatriz& mat, int numFilas, int  numCol, int f, int c, int d) {

	while (f >=0 || c < numCol) {
		
		f--;
		c++;
		if(mat.matriz[f][c]!= d)mat.matriz[f][c] = d;
	
	}
}
void arribaIzq(tMatriz& mat, int numFilas, int  numCol, int f, int c, int d) {

	while (f >= 0 || c >=0) {
		
		f--;
		c--;
		if (mat.matriz[f][c] != d)mat.matriz[f][c] = d;
	}
}
void rellDiagonales(tMatriz& mat, int numFilas, int  numCol, int f, int c,int d) {
	mat.matriz[f - 1][c - 1] = d;
	abajoDer(mat,  numFilas,   numCol, f-1,  c-1,  d);
	abajoIzq(mat, numFilas, numCol, f-1, c-1, d);
	arribaDer(mat, numFilas, numCol, f - 1, c - 1, d);
	arribaIzq(mat, numFilas, numCol, f - 1, c - 1, d);
	
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int numFilas, numCol,numTrans,a,b,c,d,f;
	string tipo;
	tMatriz matriz;

	cin >> numFilas >> numCol;
	if (numFilas==0 && numCol ==0)return false;
	for (int i = 0; i < numFilas; i++) {
		for (int j = 0; j < numCol; j++) {
			cin >> matriz.matriz[i][j];
		}
	}
	cin >> numTrans;
	for (int i = 0; i < numTrans; i++) {
		cin >> tipo;
		if (tipo == "cruz") {
			cin >> f >> c >> d;
			rellDiagonales(matriz, numFilas, numCol, f, c, d);
		}
		else if (tipo == "columnas"){
			cin >> a >> b;
			intColumnas(matriz, numFilas, numCol, a, b);
		}
		else if (tipo == "filas") {
			cin >> a >> b;
			intFilas(matriz, numFilas, numCol, a, b);
		}
	}
	for (int i = 0; i < numFilas; i++) {
		for (int j = 0; j < numCol; j++) {
			cout << matriz.matriz[i][j]<<" ";
			
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