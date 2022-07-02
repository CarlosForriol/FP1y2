// Autor/a: Nombre y apellidos Carlos Forriol Molina
// email:cforriol@ucm.es
// Compilador y S.O. utilizado VS windows
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;

const int MAX = 50;// 25

const int incF[8] = { 1,1,0,-1,-1,-1,0,1 };
const int incC[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef struct {
	char casilla;
	bool sol = false;
}tCasilla;

typedef struct {
	tCasilla matriz [MAX][MAX];
	int filas = 0, columnas = 0, numCasos = 0;
	string palabra[MAX];

}tMatriz;
istream& operator>> (istream& in, tMatriz& matriz) { 

		in >> matriz.filas >> matriz.columnas;

		for (int i = 0; i < matriz.filas; i++) {

			for (int j = 0; j < matriz.columnas; j++) {
				in >> matriz.matriz[i][j].casilla;

			}
		}
	
	in >> matriz.numCasos; //num palabras
	return in;
}
ostream& operator<< (ostream& out, tMatriz const& matriz) {
	for (int i = 0; i < matriz.columnas; i++) {
		cout << "-" << " ";
	}
	cout << endl;
	for (int i = 0; i < matriz.filas; i++) {
		for (int j = 0; j < matriz.columnas; j++) {
			if (matriz.matriz[i][j].sol == true) { // si es solucion  escribirla
				cout << matriz.matriz[i][j].casilla << " ";
			}
			else {
				cout << " " << " ";

			}
		}
		cout << endl;
	}
	for (int i = 0; i < matriz.columnas; i++){ // barras al fial
	
		cout << "-" << " ";
	}
	cout << endl << endl;
	return out;
}
// función que resuelve el problema
void Solucion_resolver(tMatriz& matriz, string palabra) {
	int pos = 0,f =0, c =0;

	for (int i = 0; i < matriz.filas; i++) {//recorremos matriz
		for (int j = 0; j < matriz.columnas; j++) {

			if (matriz.matriz[i][j].casilla == palabra[pos]) { // si la casilla tiene a primera letra biscada
				pos++; // buscamos la segunda
				for (int k = 0; k < 8; k++) { // recorrer alrededores
					f = incF[k] + i;//explorar casillas alrededor i j
					c = incC[k] + j;

					if (f >= 0 && c >=0 && f < matriz.filas && c < matriz.columnas) { // si lo buscado esta dentro del tablero
						while (matriz.matriz[f][c].casilla == palabra[pos] && pos != palabra.length()) { // mientras que sigan coincidiendo
							f+= incF[k];
							c+= incC[k];
							++pos; // avanzan juntos
						}
						if (pos == palabra.length()) { // ultima letra
							while (pos !=0){
								f -=incF[k];//avanza
								c -=incC[k];
								matriz.matriz[f][c].sol = true; // es solucion
								pos--;
						
							}
						}
						else {
							pos = 1;
						}
					}

				}
				pos = 0;
			}	
		}
	}
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	tMatriz matriz;
	string palabra;
	cin >> matriz; //llamas a cargar
	for (int i = 0; i < matriz.numCasos; i++ ) {
		cin >> palabra;
		Solucion_resolver(matriz, palabra);
	}
	cout << matriz;
	
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif
	return 0;
}