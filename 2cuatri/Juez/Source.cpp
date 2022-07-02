// Autor/a: Nombre y apellidos carlos forriol y javier de hoyos pino
// email: cforriol@ucm.es
// Compilador y S.O. utilizado visual studio 2019 Y windows 10
// Nombre del problema papa noel





#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;

typedef struct
{

	int matriz[40][40]{ {0}, {0} };
	int columnas = 0;
	int filas = 0;


}tMatriz;



istream& operator>> (istream& in, tMatriz& m)
{

	in >> m.columnas;
	in >> m.filas;

	for (int i = 0; i < m.columnas; ++i)
	{
		for (int j = 0; j < m.filas; ++j)
		{
			in >> m.matriz[i][j];
		}
	}

	return in;
}
bool Solucion_resolver(const tMatriz imagen, const tMatriz patron, tMatriz& comparar)
{

	bool resultado = false;

	int numc = 0, numf = 0, c, f, q, w;

	c = patron.columnas;
	f = patron.filas;

	while (resultado != true && numc != imagen.columnas - patron.columnas + 1)
	{

		for (int i = numc; i < c; i++)
		{
			for (int j = numf; j < f; j++)
			{
				w = j - numf;
				q = i - numc;

				comparar.matriz[q][w] = imagen.matriz[i][j];
			}
		}

		for (int i = 0; i < patron.columnas; ++i)
		{
			for (int j = 0; j < patron.filas; ++j)
			{
				if (patron.matriz[i][j] == comparar.matriz[i][j])
				{
					resultado = true;
				}
				else
				{
					resultado = false;
					break;
				}
			}
			if (resultado == false)
			{
				break;
			}
		}

		comparar.columnas = numc;
		comparar.filas = numf;

		if (numf != imagen.filas - patron.filas + 1)
		{
			numf++;
			f++;
		}
		else
		{
			numf = 0;
			++numc;
			++c;
			f = patron.filas;
		}

		if (imagen.columnas > 40 || imagen.filas > 40)
		{
			resultado = false;
		}
		if (patron.columnas > imagen.columnas || patron.filas > imagen.filas)
		{
			resultado = false;
		}



	}

	return resultado;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	bool caso = true;
	tMatriz imagen, patron, comparar;
	int solucion;


	// leer los datos de la entrada

	cin >> imagen;
	cin >> patron;

	if (imagen.columnas == 0)
	{
		caso = false;
	}
	else
	{
		caso = true;
		if (Solucion_resolver(imagen, patron, comparar) == true)
		{

			cout << comparar.columnas << " " << comparar.filas << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return caso;

}

int main()
{

#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	while (resuelveCaso() == true);

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif
	return 0;

}

