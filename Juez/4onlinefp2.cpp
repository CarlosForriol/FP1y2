// Autor/a: Nombre y apellidos Carlos Forriol Molina
// email: cforriol@ucm.es
// Compilador y S.O. utilizado VS2019 windows
// Nombre del problema 4 en linea
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;

const int incF[8] = { 1,1,0,-1,-1,-1,0,1 };
const int incC[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef struct {
	int tablero[6][7]{ {0}, {0} };
	int numfichas = 0;
	int ultfila = 0;
	int ultcolumna = 0;
}tJuego;

// función que resuelve el problema
istream& operator>> (istream& in, tJuego& juego) {
	int columnas = 0, x = 0;

	in >> juego.numfichas;
	if (juego.numfichas > 42) {
		juego.numfichas = 42;//Se quedan ahi movimientos
	}
	for (int i = 0; i < juego.numfichas; i++) {
		in >> columnas;
		while (juego.tablero[x + 1][columnas] == 0 && x != 5) { // mientras posicion vacia y distinta de 5(filas)
			x++;//se van sumando movs
		}
		if (i % 2 ==0) { //Jugador amarillo
			juego.tablero[x][columnas] = 1; // posicion ocupada por el 1
			juego.ultcolumna = columnas; // su ultima columna
			juego.ultfila = x;// su ultima fila
		}
		else {
			juego.tablero[x][columnas] = 2;// posicion ocupada por el 2
			juego.ultcolumna = columnas;
			juego.ultfila = x;
		}
		x = 0;//termina
	}
	return in;
}
int Solucion_resolver(tJuego& juego) {
	int f = 0, c = 0, x =0, sol =0;
	bool res = true;
	for (int i = 0; i < 6; i++) {//recorre tablero
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 8; k++) {//recorre alrededores
				f = incF[k] + i;//explorar casillas alrededor i j
				c = incC[k] + j;

				if (juego.tablero[i][j] !=0) { // si esta ocupado
					while (x !=3) {
						if (f > 5 || f < 0 || c < 0 || c > 6) {// esta fuera tablero
							res = false;
						}
						else{
						    if (juego.tablero[i][j] != juego.tablero[f][c]) {
							      res = false;
							      x = 2;
						    }
							else {
								f += incF[k];
								c += incC[k];
							}
						}
						x++;
					}
					x = 0;
					if (res == true) {
						if (juego.tablero[i][j] ==2) {//Si el ultimo colocado es 2
							sol = 2;
						}
						else {
							sol = 1;
						}
						k = 8;
						i = 5;
						j = 6;
					}
					else {
						res = true;
					}
					
				}

			}
		}
	}
	return sol;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	tJuego juego;
	int sol = 0;
	// leer los datos de la entrada
	bool ok;
	cin >> juego;//llama a cargar
	if (juego.numfichas == 0) {
		ok = false;
	}
	else {
		ok = true;
		sol= Solucion_resolver(juego);
		if (sol == 2) {
			cout << "Gana B" << endl;
		}
		else if (sol == 1) {
			cout << "Gana A" << endl;
		}
		else if (sol == 0) {
			cout << "Empate" << endl;
		}
	}
		
	return ok;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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