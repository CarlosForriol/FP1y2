#include<iostream>
#include<string>
#include<fstream>
using namespace std;

typedef struct {
	//tArea area 
	string area;
	int numPaginas = 0;
	string titulo;
}tLibro;
 //typedef enum {Mat,Fis,Inf} tArea;
const int MAX_LIBROS = 100;
typedef tLibro tArray[MAX_LIBROS];

typedef struct {
	tArray libros;
	int contador = 0;

}tListaLibros;

typedef struct {
	string area;
	tListaLibros listaLibros;
	int capacidad = 0;
	int numDisponibles = 0;

}tEstanteria;
const int MAX_ESTANTERIAS = 15;
typedef tEstanteria tArray2 [MAX_ESTANTERIAS ];
typedef struct {
	tArray2 estanteria;
	int contador = 0;
}tBiblioteca;


bool cargarEstanterias(tBiblioteca& biblioteca);
bool cargarLibros(tListaLibros& listaLibros);
void borrarLibro(tListaLibros& listaLibros, int indice);
int endgame();
tLibro mayor(tListaLibros& listaLibros);
int buscarEstanteria(const tBiblioteca& biblioteca, tLibro libro);
void asignar(tBiblioteca& biblioteca, tListaLibros listaLibros, tListaLibros& sinColocar);
void mostrarLibros(const tListaLibros& listaLibros);
void mostrarBiblioteca(const tBiblioteca& biblioteca);


int main() {

}
bool cargarEstanterias(tBiblioteca& biblioteca) {
	bool errorEst = false;
	string str;
	ifstream archivo;
	int numLibrerias = 0;
	archivo.open("Estanteria.txt");
	if (archivo.is_open()) {
		archivo >> numLibrerias;
		biblioteca.contador = numLibrerias;
		for (int i = 0; i < numLibrerias; i++) {
			archivo >> str;
			biblioteca.estanteria[i].area = str;
			archivo >> biblioteca.estanteria[i].capacidad;
			biblioteca.estanteria[i].numDisponibles = biblioteca.estanteria[i].capacidad;

		}
	}
	else {
		cout << "ERROR, no se ha podido abrir el archivo" << endl;
		errorEst = true;
	}
	return errorEst;
}
bool cargarLibros(tListaLibros& listaLibros) {
	bool errorLib = false;
	ifstream archivo;
	string str;
	int numLibrerias = 0;
	int i = 0;
	archivo.open("libros.txt");
	if (archivo.is_open()) {
		archivo >> str;
		while (str != "XXX") {
			listaLibros.libros[i].area = str;
			archivo >> listaLibros.libros[i].numPaginas;
			getline(archivo, listaLibros.libros[i].titulo);
			listaLibros.contador++;
			i++;
			archivo >> str;
		}
	}
	else
	{
		cout << "ERROR, no se ha podido abrir el archivo" << endl;
		errorLib = true;
	}
	return errorLib;

}
void borrarLibro(tListaLibros& listaLibros, int indice) {
	for (int i = 0; i < indice; i++) {
		listaLibros.libros[i].numPaginas = 0;
		listaLibros.libros[i].titulo = "X";
		listaLibros.libros[i] = listaLibros.libros[i + 1];
		listaLibros.contador--;
	}
}
tLibro mayor(tListaLibros& listaLibros) {
	int max = 0;
	int indice = 0;
	tLibro libro;
	for (int i = 0; i < listaLibros.contador; i++) {
		if (listaLibros.libros[i].numPaginas > max) {
			max = listaLibros.libros[i].numPaginas;
			indice = i;
		}

	}
	libro.area = listaLibros.libros[indice].area;
	libro.numPaginas = listaLibros.libros[indice].numPaginas;
	libro.titulo = listaLibros.libros[indice].titulo;

	borrarLibro(listaLibros, indice);

	return libro;
}
int buscarEstanteria(const tBiblioteca& biblioteca, tLibro libro) {
	int posicion = -1;
	for (int i = 0; i < biblioteca.contador; i++) {
		if ((biblioteca.estanteria[i].area == libro.area) && (libro.numPaginas <= biblioteca.estanteria[i].numDisponibles)) {
			i = posicion;
		}
	}
	return posicion;
}
void asignar(tBiblioteca& biblioteca, tListaLibros listaLibros, tListaLibros& sinColocar) {
	tLibro libro;
	int posicion = -1;
	int i = 0;
	int j = 0;
	while (listaLibros.libros != 0) {
		mayor(listaLibros);
		buscarEstanteria(biblioteca, libro);
		if(posicion == -1){
			libro = sinColocar.libros[i];
			biblioteca.estanteria[i].numDisponibles--;
			i++;
		}
		else
		{
			libro = biblioteca.estanteria[posicion].listaLibros.libros[i];
			j++;
		}
		
	}
}
void mostrarLibros(const tListaLibros& sinColocar) {
	cout << "Libros que no pudieron ser colocados..." << endl << endl;
	for (int i = 0; i < sinColocar.contador; i++)
	{
		cout << sinColocar.libros[i].titulo << " (" << sinColocar.libros[i].numPaginas << " paginas)" << endl << endl;
	}
}
void mostrarBiblioteca(const tBiblioteca& biblioteca)
{
	string str;
	for (int i = 0; i < biblioteca.contador; i++)
	{
		//areaToStr(biblioteca.estanteria[i].area);
		cout << str << " (" << biblioteca.estanteria[i].capacidad << "/" << biblioteca.estanteria[i].numDisponibles << ")" << endl;
		cout << " " << biblioteca.estanteria[i].listaLibros.libros[i].titulo << " (" << biblioteca.estanteria[i].listaLibros.libros[i].numPaginas << " paginas) " << endl;
	}

}
