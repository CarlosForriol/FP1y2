// Autor/a: Nombre y apellidos Carlos Forriol Molina y Ruben G�mez Escalonilla
// email:cforriol@ucm.es y rubgom05@ucm.es
// Compilador y S.O. utilizado VS2019 y W10
// Nombre del problema PR01
// Comentario general sobre la soluci�n usamos modulos
// explicando como se resuelve el problema 

#include <iostream>
#include <fstream>
// Introduce m�s librer�as si son necesarias
using namespace std;
#include "MatrizChar.h";
void resuelveCaso();
void resolver(tMatrizChar& m);


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datossal.txt");
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


// funci�n que resuelve el problema
void resolver(tMatrizChar& mat) {
	string op;
	int cont, a;
	cin >> cont;
	for (int i = 0; i < cont; i++) {
		cin >> op;
		if (op == "RD") {
			if (i == 0) {
				RotarD(mat);
			}
			else {
				cout << "DATOS INCORRECTOS" << endl;
			}

		}

	}
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
void resuelveCaso() {
	tMatrizChar mat;
	// leer los datos de la entrada
	if (cargar(mat, cin)) {
		resolver(mat);
		cout << mat;
		//mostrar(m);//cout << m;
	}
	else {
		cout << "DATOS INCORRECTOS" << endl;
	}
	// escribir soluci�n

}