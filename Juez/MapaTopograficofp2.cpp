// Autor/a: Nombre y apellidos Calos Forriol Molina
// email:cforriol@ucm.es
// Compilador y S.O. utilizado Windows y VS
// Nombre del problema Mapa topografico
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;
const int MAX_FILAS = 500;
const int MAX_COL = 500;

typedef struct {
	int numfilas, numcol;
	int matriz[MAX_FILAS][MAX_COL];
}tMatriz;

typedef struct {
	int fila, col;
	
}tPos;

bool resuelveCaso();
int resolver(const tMatriz& m, tPos& p);
void cargarMatriz(tMatriz& m);
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.txt");
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

// función que resuelve el problema
int resolver(const tMatriz& m,tPos& p) {
	int max=m.matriz[0][0];//primer elem matriz
	p.fila = 0;
	p.col = 0;
	for (int i = 0; i < m.numfilas; i++) {
		for (int j = 0; j < m.numcol; j++) {
			if (m.matriz[i][j]> max) {
				max = m.matriz[i][j];
				p.fila = i;
				p.col = j;
			}
		}
	}
	return max;
}

 void cargarMatriz(tMatriz& m) {
	 cin >> m.numfilas >> m.numcol;
	 for (int i = 0; i < m.numfilas;i++) {
		 for (int j = 0; j < m.numcol; j++) {
			cin >>  m.matriz[i][j];
		 }
	 }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	tMatriz m;
	tPos p;

	cargarMatriz(m);
	if (!std::cin)  // fin de la entrada
		return false;
	
	int sol = resolver(m,p);

	// escribir sol
	cout << sol << " " << p.fila << " " << p.col << endl;
	return true;
}