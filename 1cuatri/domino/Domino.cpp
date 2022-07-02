#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;
int main()
{
	srand(time(NULL));
	int i, n, aleatorio, DESDE = 0, HASTA = 6;
	cout << "Numeros aleatorios entre " << DESDE << " y " << HASTA << endl;
	cout << "Cuantos numeros aleatorios quiere generar? ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		aleatorio = rand() % (HASTA - DESDE + 1) + DESDE;
		cout << aleatorio << " ";
	}
	cout << endl;
	{
		int mostrarMenu();
		{
			int opcionMenu;

			cout << "----------------------" << endl;

			cout << "  MENU DE OPCIONES" << endl;

			cout << "----------------------" << endl;

			cout << "1. Poner ficha nueva por la izquierda" << endl;
			cout << "2. Poner ficha nueva por la derecha" << endl;
			cout << "3. Robar ficha nueva" << endl;
			cout << "0. Salir" << endl;

			cout << "Elija opcion: ";
			cin >> opcionMenu;
			while (opcionMenu < 0 || opcionMenu > 3)
			{
				cout << "Elija opcion: "; // selecciona la opcion del menu
				cin >> opcionMenu;
			}
			return opcionMenu;
		}
	}
	string fichaToStr(short int izquierda, short int derecha);
	{

	}
	void mostrarTablero(short int fichaN1, short int fichaN2, string tablero, int numColocadas, int numRobadas);
	{
		int mostrarTablero, fcolocadas, frobadas, fjugador;
		cout << "----------------------" << endl;
		cout << "        TABLERO       " << endl;
		cout << "----------------------" << endl;

		cin >> mostrarTablero;
		cout << "Fichas colocadas: " << endl;
		cin >> fcolocadas;
		cout << "Fichas robadas: " << endl;
		cin >> frobadas;
		cout << "Ficha jugador: " << endl;
		cin >> fjugador;


	}
	short int aleat();
	{	
		int n, a;

		n = 0 + rand() % 7;

		return n;
	}
	string toStr(int n);
	{
		char cadena1[] = "1";
		int numero1;
		numero1 = atoi(cadena1);
		cout << numero1 << endl;
		getch();

		char cadena2[] = "2";
		int numero2;
		numero2 = atoi(cadena2);
		cout << numero2 << endl;
		getch();

		char cadena3[] = "3";
		int numero3;
		numero3 = atoi(cadena3);
		cout << numero3 << endl;
		getch();

		char cadena4[] = "4";
		int numero4;
		numero4 = atoi(cadena4);
		cout << numero4 << endl;
		getch();

		char cadena5[] = "5";
		int numero5;
		numero5 = atoi(cadena5);
		cout << numero5 << endl;
		getch();

		char cadena6[] = "6";
		int numero6;
		numero6 = atoi(cadena6);
		cout << numero6 << endl;
		getch();

		return 0;

	}
	bool puedePonerIzq(string tablero, short int fichaN1, short int fichaN2);
	{

	}
	bool puedePonerDer(string tablero, short int fichaN1, short int fichaN2);
	{

	}
	string ponerFichaIzq(string tablero, short int fichaN1, short int fichaN2);
	{
		
	}
	string ponerFichaDer(string tablero, short int fichaN1, short int fichaN2);
	{

	}
}