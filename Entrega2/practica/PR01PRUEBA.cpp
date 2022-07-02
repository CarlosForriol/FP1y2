// Autor/a: Nombre y apellidos Carlos Forriol Molina
// email:cforriol@ucm.es
// Compilador y S.O. utilizado VS2019 y W10
// Nombre del problema PR01
// Comentario general sobre la solución usamos modulos
// explicando como se resuelve el problema 

#include <iostream>
#include <fstream>
#include <iomanip>
// Introduce más librerías si son necesarias
using namespace std;

void resuelveCaso();
void resolver(tMatrizChar& m);
void mostrar(ofstream& ent, tMatrizChar& mat);
bool cargar(tMatrizChar& mat, istream& ent);
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool swapF(tMatrizChar& mat, int f1, int f2);
bool swapC(tMatrizChar mat, int c1, int c2);

struct tCoor {
	int x, y;
};
const int DIM_MAX = 64;
typedef unsigned char uint8;
struct tMatrizChar
{
	int filas, columnas;
	uint8 matriz[DIM_MAX][DIM_MAX];
};

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.txt");
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
bool cargar(tMatrizChar& mat, istream& ent) {
	int numCasos;
	int fila = 0;
	int intercambio;
	string cambio;
	char fila1[68];
	char columna1[68];
	int p = 0;
	int q = 0;
	bool ok = true;
	ent >> numCasos;
	ent >> mat.filas >> mat.columnas;
	for (int i = 0; i < numCasos; i++) {
		while (fila < mat.filas && ok) {
			int col = 0;
			while (col < mat.columnas && ok) {

				ent >> mat.matriz[fila][col];
				if (ent.fail()) ok = false;
				else ++col;
			}
			if (ok) ++fila;
		}
		ent >> intercambio;
		for (int z = 0; z < intercambio; z++) {
			ent >> cambio;
			if (cambio == "SF") {
				ent >> fila1[p];
				p++;
				ent >> fila1[p];
				p++;
			}
			if (cambio == "SC") {
				ent >> columna1[q];
				q++;
				ent >> columna1[q];
				q++;
			}

		}
	}

	return ok;
}
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	/*if (pos1.x > DIM_MAX || pos1.x> DIM_MAX) {
		if (pos2.y > DIM_MAX || pos2.y > DIM_MAX) {
			return false;
		}
	}
	else {
		for (int f = 0; f < mat.filas; ++f) {
			for (int c = 0; c < mat.columnas; ++c) {
				pos1.x[f] = pos2.y[c];
			}
		}
	}
	return true;*/
	
}
bool swapF(tMatrizChar& mat, int f1, int f2) {
	if (f1 < 0 || f1 >= mat.filas || f2 < 0 || f2 >= mat.filas)
		return false;
	else {
		if (f1 != f2)
			for (int i = 0; i < mat.columnas; ++i)
				swap(mat[f1][i], mat[f2][i]);
		return true;
	}
}
bool swapC(tMatrizChar mat, int c1, int c2) {
	if (c1 < 0 || c1 >= mat.columnas || c2 < 0 || c2 >= mat.columnas)
		return false;
	else {
		if (c1 != c2)
			for (int i = 0; i < mat.filas; ++i)
				swap(mat[c1][i], mat[c2][i]);
		return true;
	}
}


void mostrar(ofstream& sal, tMatrizChar& mat) {
	sal << mat.filas << ' ' << mat.columnas << '\n';
	for (int f = 0; f < mat.filas; ++f) {
		for (int c = 0; c < mat.columnas; ++c)
			sal << setw(4) << mat.matriz[f][c] << ' ';
		sal << '\n';
	}
	/*for (int i = 0; i < mat.filas;i++) {
		for (int j = 0; j < mat.columnas;j++) {
			cout << mat.matriz[i][j];
		}

	}
	cout << endl;
	cout << "---" << endl;*/
}

// función que resuelve el problema
void resolver(tMatrizChar& m) {
	string op;
	int cont = 0, a, b;// contados y las dos filas
	cin >> cont;
	for (int i = 0; i < cont; i++) {
		cin >> op;
		switch (op){
		
		case "SF":
			swapF(a, b);
			break;
		case "SC":
			swapC(a, b);
			break;
		default:
			break;
		}
	}
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	tMatrizChar m;
	// leer los datos de la entrada
	if (cargar(m, cin)) {
		resolver(m);
		mostrar(m);//cout << m;
	}
	else {
		cout << "DATOS INCORRECTOS" << endl;
	}
	// escribir solución

}