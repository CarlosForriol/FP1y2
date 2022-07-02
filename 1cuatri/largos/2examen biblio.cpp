#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef enum { mat, fis, inf }tArea;

typedef struct {
	tArea area;
	int nPag = 0;
	string titulo;
}tLibro;

typedef tLibro arrayLibro[1000];
typedef struct {
	arrayLibro libro;
	int cont = 0;
}tListaLibros;

typedef struct {
	tArea area;
	tListaLibros listaLibros;
	int capacidad = 0;
	int disponibles = 0;
}tEstanteria;

typedef tEstanteria arrayestanteria[15];

typedef struct {
	arrayestanteria lista;
	int cont=0;
}tBiblioteca;

tArea strToArea(string str);

bool cargarEstanterias(tBiblioteca& biblioteca);

bool cargarLibros(tListaLibros& listaLibros);

void borrarLibro(tListaLibros& listaLibros, int indice);

tLibro mayor(tListaLibros& listaLibros);

int buscarEstanteria(const tBiblioteca& biblioteca, tLibro libro);

void asignar(tBiblioteca& biblioteca, tListaLibros listaLibros, tListaLibros& sinColocar);

string areatostr(tArea area);

void mostrarLibros(const tListaLibros& ListaLibros);

void mostrarBiblioteca(const tBiblioteca& biblioteca, const tListaLibros& sinColocar);

int main() {

}
tArea strToArea(string str) {
	tArea area;

	if (str == "Mat")
	{
		area = mat;
	}
	if (str == "Fis")
	{
		area = fis;
	}
	if (str == "Inf")
	{
		area = inf;
	}

	return area;
}
bool cargarEstanterias(tBiblioteca& biblioteca) {

	bool caso = false;
	ifstream archivo;
	archivo.open("biblioteca.txt");
	string str;
	int max;

	if (archivo.is_open()) {
		caso = true;
		archivo >> max;
		for (int i = 0; i < max; i++) {
			archivo >> str;
			biblioteca.lista[i].area = strToArea(str);
			archivo >> biblioteca.lista[i].capacidad;
			biblioteca.lista[i].disponibles = biblioteca.lista[i].capacidad;

			biblioteca.cont++;
			
		}
		
	}
	archivo.close();
	return caso;
}
bool cargarLibros(tListaLibros& listaLibros) {
	bool caso = false;
	ifstream archivo;
	archivo.open("libros.txt");
	string str;
	if (archivo.is_open()) {
		caso = true;
		
		for (int i = 0; i < 100; i++) {
			archivo >> str;
			while (str != "XXX") {
				
				listaLibros.libro[i].area = strToArea(str);
				archivo >> listaLibros.libro[i].nPag;
				getline(archivo, listaLibros.libro[i].titulo);
				listaLibros.cont++;
				archivo >> str;
				i++;

			}
		}

	}
	return caso;
}
void borrarLibro(tListaLibros& listaLibros, int indice) {

	for (int i = 0; i < listaLibros.cont; i++) {
		listaLibros.libro[i] = listaLibros.libro[i + 1];
	}
	listaLibros.cont--;
}
tLibro mayor(tListaLibros& listaLibros) {
	int indice = 0;
	tLibro libro;

	for (int i = 0; i < listaLibros.cont; i++) {
		if (listaLibros.libro[indice].nPag < listaLibros.libro[i].nPag) {
			indice = i;
		}
	}

	libro = listaLibros.libro[indice];
	borrarLibro(listaLibros, indice);
	return libro;
}
int buscarEstanteria(const tBiblioteca& biblioteca, tLibro libro) {
	int pos = -1;
	int i = 0;
	while (i != biblioteca.cont && pos == -1) {
		if (biblioteca.lista[i].area == libro.area && biblioteca.lista[i].disponibles >= libro.nPag) {
			pos = i;
		}
		i++;
	}
	return pos;
}
void asignar(tBiblioteca& biblioteca, tListaLibros listaLibros, tListaLibros& sinColocar) {
	tLibro libro;
	int ind;
	while (listaLibros.cont != 0) {
		libro = mayor(listaLibros);
		ind = buscarEstanteria(biblioteca, libro);
		if (ind == -1)
		{
			sinColocar.libro[sinColocar.cont].area = libro.area;
			sinColocar.libro[sinColocar.cont].nPag = libro.nPag;
			sinColocar.libro[sinColocar.cont].titulo = libro.titulo;

			sinColocar.cont++;
		}
		else
		{
			biblioteca.lista[ind].listaLibros.libro[biblioteca.lista[ind].listaLibros.cont].area = libro.area;
			biblioteca.lista[ind].listaLibros.libro[biblioteca.lista[ind].listaLibros.cont].nPag = libro.nPag;
			biblioteca.lista[ind].listaLibros.libro[biblioteca.lista[ind].listaLibros.cont].titulo = libro.titulo;

			biblioteca.lista[ind].disponibles = biblioteca.lista[ind].disponibles - libro.nPag;

			biblioteca.lista[ind].listaLibros.cont++;
		}

	}
}
string areatostr(tArea area)
{
	string str;

	if (area == mat)
	{
		str = "Matematicas";
	}
	if (area == fis)
	{
		str = "Fisica";
	}
	if (area == inf)
	{
		str = "Informatica";
	}

	return str;
}
void mostrarLibros(const tListaLibros& ListaLibros){
	
	for (int i = 0; i < ListaLibros.cont; i++) {
		cout << "     " << ListaLibros.libro[i].titulo << " (" << ListaLibros.libro[i].nPag << " paginas)" << endl;
	}
}
void mostrarBiblioteca(const tBiblioteca& biblioteca, const tListaLibros& sinColocar) {
	int cont = 1;
	for (int i = 0; i < biblioteca.cont; i++) {
		if (biblioteca.lista[i].area == mat) {
			cout << areatostr(biblioteca.lista[i].area) << " - " << cont << "(" << biblioteca.lista[i].capacidad << "/" << biblioteca.lista[i].disponibles << ")" << endl;
			if (biblioteca.lista[i].listaLibros.cont != 0)
			{
				mostrarLibros(biblioteca.lista[i].listaLibros);


			}
			cout << endl << endl;
			cont++;
		}

	}
	cont = 1;
	for (int i = 0; i < biblioteca.cont; i++)
	{
		if (biblioteca.lista[i].area == fis)
		{
			cout << areatostr(biblioteca.lista[i].area) << " - " << cont << "(" << biblioteca.lista[i].capacidad << "/" << biblioteca.lista[i].disponibles << ")" << endl;

			if (biblioteca.lista[i].listaLibros.cont != 0)
			{
				mostrarLibros(biblioteca.lista[i].listaLibros);


			}

			cout << endl << endl;
			cont++;
		}

	}

	cont = 1;
	for (int i = 0; i < biblioteca.cont; i++)
	{
		if (biblioteca.lista[i].area == inf)
		{
			cout << areatostr(biblioteca.lista[i].area) << " - " << cont << "(" << biblioteca.lista[i].capacidad << "/" << biblioteca.lista[i].disponibles << ")" << endl;

			if (biblioteca.lista[i].listaLibros.cont != 0)
			{
				mostrarLibros(biblioteca.lista[i].listaLibros);


			}
			cout << endl << endl;
			cont++;
		}
	}
	if (sinColocar.cont == 0)
	{
		cout << "Todos los libros se han colocado en la estanteria" << endl;
	}
	else
	{
		cout << "Libros que no pudieron ser colocados..." << endl;
		mostrarLibros(sinColocar);
	}



	cont = 1;

}