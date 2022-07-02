// Nombre del problema Practica1
// Comentario general sobre la solución: usamos modulos
// explicando como se resuelve el problema 

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

// Introduce más librerías si son necesarias

#include "MatrizChar.h"

#include "Puzzle.h"

using namespace std;



void mainPuzzle(tPuzzle& jpm) {

	//string modo;

	if (jpm.modo == "1D") {
		//modo = "_1D.txt";
		//iniciar(pm, modo);
		//cargarPuzzle(pm, modo);
		jugar(jpm);

	}
	else if (jpm.modo == "2D") {
		//modo = "_2D.txt";
		//iniciar(jpm, modo);
		//cargarPuzzle(pm, modo);
		jugar(jpm);

	}


}

bool cargarPuzzle(tPuzzle& jpm, string tipo) {


	bool puede = false;
	string nombre;
	ifstream archivo;

	jpm.modo = tipo;
	archivo.open(jpm.nomFichero);
	if (!archivo.is_open()) {
		cout << "Ingrese nuevo nombre(Recuerde que es nombre_1D.txt)" << endl;
	}
	else {
		//char aux;
		cargar(jpm.imagen1, archivo);//nummaxacciones // mat
		cargar(jpm.imagen2, archivo);
		///cin.get(aux);
		archivo >> jpm.nummaxacciones;
		puede = true;
	}

	archivo.close();
	return puede;
}
void mostrar2(const tPuzzle& jpm) {
	mostrar(jpm.imagen1);
	mostrar(jpm.imagen2);
	cout << "Numero de intentos restantes:" << endl;
	cout << jpm.nummaxacciones << endl;

}
bool jugar(tPuzzle& jpm) {

	bool correcto = true;
	while (jpm.nummaxacciones != 0 && correcto) {
		mostrar2(jpm);
		accion(jpm);
		if (jpm.imagen1 == jpm.imagen2) {//llamamos al operador
			correcto = false;
			mostrar2(jpm);
			cout << "Has ganado, Fin del juego  " << endl;
		}
	}
	if (jpm.nummaxacciones == 0 && correcto != false) {
		mostrar2(jpm);
		cout << "Has perdido, Fin del juego " << endl;

	}
	return true;
}
void accion(tPuzzle& jpm) {
	string op;
	int a, b, c, d;
	tCoor pos1, pos2;
	if (jpm.modo == "1D") {
		cout << "1D:" << endl;
		cout << "SF a b" << endl;
		cout << "SC a b" << endl;
		cout << "SD a " << endl;
		cout << "VF a " << endl;
		cout << "VC a " << endl;
		cout << "VD a " << endl;
		cout << " Teclee una accion:" << endl;
		cin >> op;
		if (op == "SF") {
			cin >> a >> b;
			while (a < 0 || a >= jpm.imagen1.filas || b < 0 || b >= jpm.imagen1.filas) {
				cout << "Coordenadas incorrectas, introduzca SOLO otras coordenadas:" << endl;
				cin >> a >> b;
			}
			if (a >= 0 && a < jpm.imagen1.filas && b >= 0 && b < jpm.imagen1.filas) {
				swapF(jpm.imagen1, a, b);
			}
		}
		if (op == "SC") {
			cin >> a >> b;
			while (a < 0 || a >= jpm.imagen1.columnas || b < 0 || b >= jpm.imagen1.columnas) {
				cout << "Coordenadas incorrectas, introduzca SOLO otras coordenadas:" << endl;
				cin >> a >> b;
			}
			if (a >= 0 && a < jpm.imagen1.columnas && b >= 0 && b < jpm.imagen1.columnas) {
				swapC(jpm.imagen1, a, b);
			}
		}
		if (op == "SD") {
			cin >> a;
			if (jpm.imagen1.columnas != jpm.imagen1.filas) {
				cout << "Para usar esta funcion la matriz debe de ser cuadrada. Pulse enter para continuar" << endl;
				system("pause");
				jpm.nummaxacciones++;
			}
			else {
				while (a > jpm.imagen1.filas) {
					cout << "Coordenada incorrecta, introduzca SOLO otra coordenada:" << endl;
					cin >> a;
				}
				if (a < jpm.imagen1.filas) {
					swapD(jpm.imagen1, a);
				}
			}
		}
		if (op == "VF") {
			cin >> a;
			while (a < 0 || a >= jpm.imagen1.filas) {
				cout << "Coordenada incorrecta, introduzca SOLO otra coordenada:" << endl;
				cin >> a;
			}
			if (a >= 0 && a < jpm.imagen1.filas) {
				voltearF(jpm.imagen1, a);
			}
		}
		if (op == "VC") {
			cin >> a;
			while (a < 0 || a >= jpm.imagen1.columnas) {
				cout << "Coordenada incorrecta, introduzca SOLO otra coordenada:" << endl;
				cin >> a;
			}
			if (a >= 0 && a < jpm.imagen1.columnas) {
				voltearC(jpm.imagen1, a);
			}
		}
		if (op == "VD") {
			cin >> a;
			if (jpm.imagen1.columnas != jpm.imagen1.filas) {
				cout << "Para usar esta funcion la matriz debe de ser cuadrada. Pulse enter para continuar" << endl;
				system("pause");
				jpm.nummaxacciones++;
			}
			else {
				while (a >= jpm.imagen1.columnas || a <= -jpm.imagen1.columnas) {
					cout << "Coordenada incorrecta, introduzca SOLO otra coordenada:" << endl;
					cin >> a;
				}
				if (a < jpm.imagen1.columnas && a > -jpm.imagen1.columnas) {
					voltearD(jpm.imagen1, a);
				}
			}
		}
	}
	else {
		cout << "2D:" << endl;
		cout << "VV " << endl;
		cout << "VH" << endl;
		cout << "RD" << endl;
		cout << "ID" << endl;
		cout << "SA a b c d  " << endl;
		cout << " Teclee una accion:" << endl;
		cin >> op;
		if (op == "VV") {
			voltearV(jpm.imagen1);
			/*if (jpm.imagen1.filas >= 0) {
				voltearV(jpm.imagen1);
			}
			else {
				cout << "Coordenadas incorrectas,presione enter e introduzca otras coordenadas:" << endl;
				system("pause");
				jpm.nummaxacciones++;
			}*/
		}
		if (op == "VH") {
			voltearH(jpm.imagen1);
			/*if (jpm.imagen1.columnas >= 0) {
				voltearH(jpm.imagen1);
			}
			else {
				cout << "Coordenadas incorrectas,presione enter e introduzca otras coordenadas:" << endl;
				system("pause");
				jpm.nummaxacciones++;
			}*/
		}
		if (op == "RD") {
			RotarD(jpm.imagen1);
		}
		if (op == "ID") {
			voltearID(jpm.imagen1);
			/*if (jpm.imagen1.columnas == jpm.imagen1.filas) {
				voltearID(jpm.imagen1);
			}
			else {
				cout << "Coordenadas incorrectas,presione enter e introduzca otras coordenadas:" << endl;
				system("pause");
				jpm.nummaxacciones++;
			}*/
		}
		if (op == "SA") {

			cin >> a >> b >> c >> d;
			pos1.fila = a, pos1.columna = b, pos2.fila = c, pos2.columna = d;
			swapAdy(jpm.imagen1, pos1, pos2);

			cout << "Cuidado! La funcion SA no comprueba si los datos introducidos son correctos(No la tenemos completa)" << endl;
		}
	}
	jpm.nummaxacciones--;
}