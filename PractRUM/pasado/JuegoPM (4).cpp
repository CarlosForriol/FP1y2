// Nombre del problema Practica1
// Comentario general sobre la solución: usamos modulos
// explicando como se resuelve el problema 

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

// Introduce más librerías si son necesarias


#include "JuegoPM.h"


using namespace std;
// carga los
//datos de entrada, muestra el menú y gestiona las opciones seleccionadas por
//el usuario.Cuando el usuario pide salir del programa guarda en el fichero el
//catálogo de puzzles y libera la memoria dinámica que se haya utilizado.
//string nomfichero, nombpuzle;
void  mainPuzzlesReunidos() {
	tPuzzlesReunidos jr;
	tListaPuzzles lp;
	tPuzzle* p;//da error si no inicicaliza
	int op, elegirop;
	//Aqui llama a cargar
	inicializar(jr);
	op = menu();
	while (op != 0) {
		if (op == 1) {//si no llamar a elegir Puzzle 2 times
			elegirop = elegirPuzzle(jr[0]);
			while (elegirop == -1 || elegirop == -2) {
				if (elegirop == -1) {
					elegirop = elegirPuzzle(jr[0]);
				}
				else if (elegirop == -2) {
					elegirop = elegirPuzzle(jr[0]);
				}
			}
			if (elegirop != 0) {
				mainPuzzle(*(jr[0].lista[elegirop - 1]));
				system("pause");
			}

		}
		else if (op == 2) {

			elegirop = elegirPuzzle(jr[1]);
			while (elegirop == -1 || elegirop == -2) {
				if (elegirop == -1) {
					elegirop = elegirPuzzle(jr[1]);
				}
				else if (elegirop == -2) {
					elegirop = elegirPuzzle(jr[1]);
				}
			}
			if (elegirop != 0) {
				mainPuzzle(*(jr[1].lista[elegirop - 1]));
				system("pause");
			}
		}
		else if (op == 3) {
			p = new tPuzzle;
			cout << "Escriba el nombre del puzzle:" << endl;

			char aux;
			cin.get(aux);
			getline(cin, p->nomPuzle);

			cout << "Escriba el nombre del fichero:" << endl;

			getline(cin, p->nomFichero);

			int pos = 0;
			string modo = "";
			pos = p->nomFichero.length();


			if (p->nomFichero[pos - 6] == '1')
			{
				modo = "1D";
			}
			if (p->nomFichero[pos - 6] == '2')
			{
				modo = "2D";
			}

			p->modo = modo;

			cargarPuzzle(*p, p->modo);

			if (modo == "1D") {
				insertarOrdenado(jr[0], p);
				cout << "Puzzle anyadido correctamente."<<endl;
				system("pause");
			}

			if (modo == "2D") {
				insertarOrdenado(jr[1], p);
				cout << "Puzzle anyadido correctamente." << endl;
				system("pause");
			}
		}
		op = menu();
	}
	guardar(jr);
	liberar(lp);
}
int menu() {
	system("cls");
	int op;

	cout << "1. Puzzle 1D" << endl;
	cout << "2. Puzzle 2D" << endl;
	cout << "3. Anyadir un puzzle al catalogo" << endl;
	cout << "0. Salir" << endl;
	cin >> op;

	while ((op < 0) || (op > 3)) {
		cout << "Opcion no valida. Introduce otra opcion: ";
		cin >> op;
	}
	return op;
}
void liberar(tListaPuzzles& arraypunt1) {
	for (int i = 0; i < arraypunt1.cont; i++) {
		delete arraypunt1.lista[i]; // liberar
		arraypunt1.lista[i] = nullptr; // para q no apunte a nada

	}

	arraypunt1.cont = 0;
}