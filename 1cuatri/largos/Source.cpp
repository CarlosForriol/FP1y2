#include<iostream>
#include <string>
#include<fstream>
#include<cmath>
using namespace std;

const int MAX_LIBROS = 20;

typedef struct {
	int isbn;
	string titulo;
	string autor;
	int numEjemPosee;
	int numEjemPrestados;
}tLibro;

typedef tLibro tArrayLibros[MAX_LIBROS];

typedef struct {
	int cont;
	tArrayLibros arrayLibros;
}tBiblioteca;

typedef int tAutores[MAX_LIBROS];

bool cargar(tBiblioteca biblioteca);
void insertarEjemplares(tBiblioteca& biblioteca, int isbn);
void mostrarBiblioteca(tBiblioteca& biblioteca);
bool buscarAutor(tBiblioteca& biblioteca, tAutores& arrayAutor, int& a);
void mostrarAutor(tBiblioteca& biblioteca);
bool buscarprestamo(tBiblioteca& biblioteca, int &pos);
void mostarPrestamo(tBiblioteca& biblioteca);
int menu();
int leerOpcion();

int main() {
	int opcion;
	tBiblioteca biblioteca;
	tLibro libro;
	if (!cargar(biblioteca)) {
		cout << "Error al cargar biblioteca" << endl;
	}
	else {
		cout << "Exito" << endl;
		opcion = menu();
		while (opcion != 0) {

		}
	}
}

bool cargar(tBiblioteca biblioteca) {
	bool error = false;
	string str;
	ifstream archivo;
	int isbn = 0;
	tLibro libro;
	int cont = 0;
	char basura;
	archivo.open("biblioteca.txt");
	if (archivo.is_open()) {
		archivo >> isbn;
		libro.isbn = isbn;
		while (str != "<EOF>"  && cont < MAX_LIBROS  ) {
			for (int i = 0; i < cont;i++) {
				archivo >> biblioteca.arrayLibros[i].isbn;
				archivo.get(basura);
				getline(archivo, biblioteca.arrayLibros[i].titulo);
				archivo >> biblioteca.arrayLibros[i].autor;
				archivo >> biblioteca.arrayLibros[i].numEjemPosee >> biblioteca.arrayLibros[i].numEjemPrestados;
				biblioteca.cont++;
				archivo >> str;
			}

		}
		
	}
	else {
		cout << "ERROR, no se ha podido abrir el archivo" << endl;
		error = true;
	}
	return error;

}

int leerOpcion() {
	int opcion;
	cout << "1.Insertar ejemplares de un libro" << endl;
	cout << "2. Mostrar Biblioteca" << endl;
	cout << "3. Mostar libros de un autor" << endl;
	cout << "4. Prestamo " << endl;
	cout << "0. salir" << endl;
	cin >> opcion;
	return opcion;
}
int menu() {
	int opcion;
	opcion = leerOpcion();
	while (opcion < 0 || opcion > 4) {
		cout << "Opcion erronea" << endl;
		opcion = leerOpcion();

	}
	return opcion;
}
void ejecutarOpcion(tBiblioteca biblioteca, int opcion) {
	int isbn, pos;
}
void insertarEjemplares(tBiblioteca& biblioteca,int isbn) {
	
	if (biblioteca.cont < MAX_LIBROS) {
		string basura;
		biblioteca.arrayLibros[biblioteca.cont].isbn = isbn;
		biblioteca.arrayLibros[biblioteca.cont].numEjemPrestados = 0;

		cout << "Introduzca los datos del libro:" << endl;
		cout << "Titulo:";
		getline(cin, basura);
		getline(cin, biblioteca.arrayLibros[biblioteca.cont].titulo);
		cout << "Autor:";
		cin >> biblioteca.arrayLibros[biblioteca.cont].autor;
		cout << "Numero de ejemplares:";
		cin >> biblioteca.arrayLibros[biblioteca.cont].numEjemPosee;
		cout << endl;
		biblioteca.cont = biblioteca.cont + 1;
		cout << biblioteca.cont << endl;
	}
	else {
		cout << "Biblioteca llena" << endl;
	}
}

void mostrarBiblioteca(tBiblioteca &biblioteca) {
	cout << "Biblioteca:" << endl;

	for (int i = 0; i < biblioteca.cont; i++) {
		cout << ">" << biblioteca.arrayLibros[i].isbn << " " << biblioteca.arrayLibros[i].titulo << endl;
		cout << ">" << biblioteca.arrayLibros[i].autor << " " << biblioteca.arrayLibros[i].numEjemPosee << " " << biblioteca.arrayLibros[i].numEjemPrestados << endl;

	}


}


bool buscarAutor(tBiblioteca &biblioteca,tAutores &arrayAutor, int &a) {
	bool encontrado = false;
	string autor;
	int i = 0;
	while (i < biblioteca.cont) {
		if (biblioteca.arrayLibros[i].autor == autor) {
			encontrado = true;
			arrayAutor[a] = i;
			a++;
		}
		i++;
	}
}
void mostrarAutor(tBiblioteca& biblioteca) {
	string autor,autorP;
	tAutores arrayAutor;
	int a = 0;
	cout << "Introduzca el autor:" << endl;
	cin >> autor;
	if (buscarAutor(biblioteca, arrayAutor, a)  ) {
		cout << "Titulos:" << endl;
		for (int i = 0; i < a; i++) {
			autorP = arrayAutor[i];
			cout << biblioteca.arrayLibros[i].titulo << " " << biblioteca.arrayLibros[i].numEjemPosee << endl;
		}
	}
	else {
		cout << "No existe" << endl;
	}

}

bool buscarprestamo(tBiblioteca& biblioteca,int &pos) {
	bool encontrado = false;
	int i = 0;
	int isbn;
	while (!encontrado && i < biblioteca.cont) {
		if (biblioteca.arrayLibros[i].isbn== isbn) {
			pos = i;
			encontrado = true;
		}
		i++;
	}
	return encontrado;
}



void mostarPrestamo(tBiblioteca& biblioteca) {
	int isbn, pos = 0;
	 
	cout << "Introduzca el isbn:" << endl;
	cin >> isbn;

	if (buscarprestamo(biblioteca,isbn) && biblioteca.arrayLibros[pos].numEjemPosee> 0) {
		biblioteca.arrayLibros[pos].numEjemPrestados = biblioteca.arrayLibros[pos].numEjemPrestados + 1;
		biblioteca.arrayLibros[pos].numEjemPosee = biblioteca.arrayLibros[pos].numEjemPosee - 1;
		cout << "El prestamo se hizo correctamente" << endl;
	}

}