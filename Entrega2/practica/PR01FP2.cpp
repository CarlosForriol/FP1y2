// Autor/a: Nombre y apellidos Carlos Forriol Molina
// email:cforriol@ucm.es
// Compilador y S.O. utilizado VS2019 y W10
// Nombre del problema PR01
// Comentario general sobre la solución usamos modulos
// explicando como se resuelve el problema 

#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
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


// función que resuelve el problema
void resolver(tMatrizChar& mat) {
	string op;
	int cont, a, b;
	cin >> cont;
	for (int i = 0; i < cont; i++) {
		cin >> op >> a >> b;
		if (op == "SF") {
			if (a >= 0 && a <= mat.filas && b >= 0 && b <= mat.filas) {
				swapF(mat, a, b);
			}
			else {
				cout << "   DATOS INCORRECTOS" << endl;
			}

		}
		else if (op == "SC") {
			if (a >= 0 && a <= mat.columnas && b >= 0 && b <= mat.columnas) {
				swapC(mat, a, b);
			}
			else {
				cout << "   DATOS INCORRECTOS" << endl;
			}

		}
	}
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
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
	// escribir solución
	
}