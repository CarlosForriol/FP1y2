#include <iostream>
using namespace std;
int main()
{
	double final, obligatoria, voluntaria, media, adicional;
	cout << "nota del examen final: ";
	cin >> final;
	cout << "nota de practicas obligatorias: ";
	cin >> obligatoria;
	cout << "nota de practica voluntaria: ";
	cin >> voluntaria;
	cout << "nota de la practica adicional:";
	cin >> adicional;
	if (final < 4 or obligatoria < 5 or voluntaria < 5 or adicional < 5)
	{
		cout << "estas suspenso" << endl;
	}
	else
	{
		media = (final * 0.65 + obligatoria * 0.2 + voluntaria * 0.15 + adicional * 0.15);
		cout << "media final: ";
		cout << media;
	}
	return 0;
}