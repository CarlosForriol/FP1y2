#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

const int MAX_SUB = 24;
typedef struct {
	int inicial;
	int final;
	string texto;

}tSub;

typedef tSub arraySub[MAX_SUB];

int menu();
void cargar(arraySub& arraySub, int& cont);
int toMilisegundos(int horas, int minutos, int segundos, int milisegundos);
void mostrar(arraySub& arraySub, int& cont);
int desajuste(int suma1, int suma2, string texto);
void cambiarTexto(arraySub &arraySub, int cont);

int main() {
	int opcion, cont = 0;
	arraySub arraySub;
	cargar(arraySub, cont);
	opcion = menu();
	while (opcion != 0) {
		if (opcion == 1)
			mostrar(arraySub, cont);
		else if (opcion == 2)
			cambiarTexto(arraySub ,cont);
		opcion = menu();
	}
	system("pause");
	return 0;


}
void cargar(arraySub& arraySub, int& cont) {
	int horas1, horas2, minutos1, minutos2, milisegundos1, milisegundos2, suma1 = 0, suma2 = 0;
	string texto;
	char basura;
	double segundos1, segundos2;
	ifstream entrada;
	entrada.open("Subtitulos.txt");
	if (entrada.is_open()) {
		entrada >> horas1;
		while (!entrada.eof() && cont < MAX_SUB) {
			entrada.ignore();
			entrada >> minutos1;
			entrada.get(basura);
			entrada >> segundos1;
			entrada.get(basura);
			entrada >> milisegundos1;
			entrada.get(basura);
			entrada >> horas2;
			entrada >> minutos2;
			entrada.get(basura);
			entrada >> segundos2;
			entrada.get(basura);
			entrada >> milisegundos2;
			entrada.get(basura);
			getline(entrada, texto);

			suma1 = toMilisegundos(horas1, minutos1, segundos1, milisegundos1);
			suma2 = toMilisegundos(horas2, minutos2, segundos2, milisegundos2);

			if ((suma1 - suma2) < texto.length() * 50) {
				arraySub[cont].inicial = suma1;
				arraySub[cont].final = suma2;
				arraySub[cont].texto = texto;

			}
			entrada >> horas1;

		}
	}
	else
		cout << "Error al abrir el archivo" << endl;
}
	
int toMilisegundos(int horas, int minutos, int segundos, int milisegundos) {
	int suma = 0;
	suma = horas * 3600 * pow(10, 3) + minutos * 60 * pow(10, 3) + segundos * pow(10, 3) + milisegundos;
		return suma;
}
int menu() {
	int opcion;
	cout << "0. Salir" << endl;
	cout << "1.Mostrar contenido de la lista" << endl;
	cout << "2. Dada posicion, cargar texto" << endl;
	cout << "3. Dado numero de milisegundos, buscar en la lista su posicion" << endl;
	cout << "4. Guardar cambios en el archivo" << endl;
	cin >> opcion;
	return opcion;

}
void mostrar(arraySub& arraySub, int& cont) {
	for (int i = 0; i < cont; i++) {
		cout << "Intervalo: " << arraySub[i].inicial << "--->" << arraySub[i].final << endl;
		cout << "Texto: " << arraySub[i].texto << endl;
		cout << endl;
	}

}
int desajuste(int suma1, int suma2, string texto) {
	int ajuste = 0, caracteres;
	ajuste = texto.length() - (suma2 - suma1);
	caracteres = ajuste / 50;
	return caracteres;
}
void cambiarTexto(arraySub& arraySub, int cont) {
	char basura;
	int pos;
	cout << "Introduzca la posicion a cambiar" << endl;
	cin >> pos;
	while (pos >= cont || pos < 0) {
		cout << "Posicion invalida" << endl;
		cin >> pos;
	}
	cout << arraySub[pos].texto << endl;
	cin.get(basura);
	cout << "Introduzca texto a cambiar" << endl;
	getline(cin, arraySub[pos].texto);


}

