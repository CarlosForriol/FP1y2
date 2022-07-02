//Carlos Forriol Molina y Ruen Gomez Escalonilla
//VS19 y W10
//cforriol@ucm.es y rubgom@ucm.es

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct
{
	string titulo;
	string tema;
	int matriz[50][50]{ 0 };
}tFoto;

typedef struct
{
	int numFotos = 0;
	tFoto* array_fotos[200]{0};
}tListafotos;



tFoto* leer(tListafotos& arrayPunt1, tListafotos& arrayPunt2)
{
	int numAux;
	char aux;

	cin >> numAux;

	arrayPunt1.numFotos = numAux;
	arrayPunt2.numFotos = numAux;

	cin.get(aux);

	tFoto* arraydin = new tFoto[200];

	for (int i = 0; i < numAux; i++)
	{
		getline(cin, arraydin[i].titulo);
		arrayPunt1.array_fotos[i] = &arraydin[i];
		arrayPunt2.array_fotos[i] = &arraydin[i];
	}
	for (int i = 0; i < numAux; i++)
	{
		getline(cin, arraydin[i].tema);
		arrayPunt1.array_fotos[i] = &arraydin[i];
		arrayPunt2.array_fotos[i] = &arraydin[i];
	}

	return arraydin;

}

void ordenar_titulo(tListafotos& arrayPunt1) {

	int pos;
	tFoto* tmp;

	// Desde el segundo elemento hasta el último...
	for (int i = 1; i < arrayPunt1.numFotos; i++) {
		pos = i;
		// Mientras no al principio y anterior mayor...
		while ((pos > 0) && (arrayPunt1.array_fotos[pos - 1]->titulo > arrayPunt1.array_fotos[pos]->titulo)) {
			// Intercambiar...
			tmp = arrayPunt1.array_fotos[pos];
			arrayPunt1.array_fotos[pos] = arrayPunt1.array_fotos[pos - 1];
			arrayPunt1.array_fotos[pos - 1] = tmp;

			pos--;
		}
	}
}

void ordenar_tema(tListafotos& arrayPunt2)
{

	int pos;
	tFoto* tmp;

	for (int i = 1; i < arrayPunt2.numFotos; i++) {
		pos = i;
		// Mientras no al principio y anterior mayor...
		while ((pos > 0) && (arrayPunt2.array_fotos[pos - 1]->titulo > arrayPunt2.array_fotos[pos]->titulo)) {
			// Intercambiar...
			tmp = arrayPunt2.array_fotos[pos];
			arrayPunt2.array_fotos[pos] = arrayPunt2.array_fotos[pos - 1];
			arrayPunt2.array_fotos[pos - 1] = tmp;

			pos--;
		}
	}

	// Desde el segundo elemento hasta el último...
	for (int i = 1; i < arrayPunt2.numFotos; i++) {
		pos = i;
		// Mientras no al principio y anterior mayor...
		while ((pos > 0) && (arrayPunt2.array_fotos[pos - 1]->tema > arrayPunt2.array_fotos[pos]->tema)) {
			// Intercambiar...
			tmp = arrayPunt2.array_fotos[pos];
			arrayPunt2.array_fotos[pos] = arrayPunt2.array_fotos[pos - 1];
			arrayPunt2.array_fotos[pos - 1] = tmp;

			pos--;
		}



	}

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	tListafotos arrayPunt1, arrayPunt2;

	bool fin = false;


	// leer los datos de la entrada

	tFoto* arraydin = leer(arrayPunt1, arrayPunt2);


	if (arrayPunt1.numFotos == 0)
	{
		fin = true;
	}
	else
	{
		ordenar_titulo(arrayPunt1);
		ordenar_tema(arrayPunt2);

		for (int i = 0; i < arrayPunt1.numFotos; i++)
		{
			cout << arrayPunt1.array_fotos[i]->titulo << endl;

		}
		cout << endl;

		for (int i = 0; i < arrayPunt2.numFotos; i++)
		{
			cout << arrayPunt2.array_fotos[i]->tema << " - " << arrayPunt2.array_fotos[i]->titulo << endl;

		}

		delete[] arraydin;

	}
	// escribir solución

	return fin;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	while (resuelveCaso() == false);

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif
	return 0;
}