#include <iostream>
using namespace std;
int main()
{
	double lado1, lado2, angulo, area;
	cout << " lado 1: ";
	cin >> lado1;
	cout << " lado 2: ";
	cin >> lado2;
	cout << " angulo: ";
	cin >> angulo;
	area = 0.5 * lado1 * lado2 * (angulo * 3.1415 / 180);
	cout << area;
	return 0;
}