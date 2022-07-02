#include <iostream>
using namespace std;
int main()
{
	double final, obligatoria, voluntaria, media;
	cout << "nota del examen final: ";
	cin >> final;
	cout << "nota de practicas obligatorias: ";
	cin >> obligatoria;
	cout << "nota de practica voluntaria: ";
	cin >> voluntaria;
	media = final * 0.65 + obligatoria * 0.2 + voluntaria * 0.15;
	cout << "media final: ";
	cout << media;
		return 0;
}