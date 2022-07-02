// Autor/a: Nombre y apellidos Carlos Forriol Molina
// email: cforriol@ucm.es
// Compilador y S.O. utilizado Windows
// Nombre del problema EL Burro y las alforjas
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;
const int MAX = 20;
typedef int tLista[1000];
typedef int  tPesos[1000];



// función que resuelve el problema
void resolver(tLista lista, tPesos pesos, int resultado) {//ordenacion x seleccion
	for (int i = 0; i < lista[1] - 1;++i) {
		int menor = i;
		for (int j = i + 1; j < lista[1]; ++j) {
			if (pesos[j] < pesos[menor]) menor = j;
			if (i < menor) {
				int tmp = pesos[i];
				pesos[i] = pesos[menor];
				pesos[menor] = tmp;
		     }
		}
	}
	
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	tLista lista;
	tPesos pesos;

	int num, resultado = 0;
	for (int i = 0; i <= 1; i++)
	{
		cin >> num;
		lista[i] = num;
	}
	for (int j = 0; j < lista[1]; ++j) {
		cin >> num;
		pesos[j] = num;
	}
	resolver(lista, pesos, resultado);
	for (int i = 0; i < lista[1];i++) {
		if (pesos[i]== pesos[i+1]) {
			resultado++;
			i++;
		}
	}
	if (resultado > lista[0]) {
		resultado = lista[0];
	}
	cout << resultado<<endl;

	
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
