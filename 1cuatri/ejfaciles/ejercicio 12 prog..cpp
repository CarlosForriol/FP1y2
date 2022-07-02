#include <iostream>
using namespace std;
int main()
{
	{
		double capital, ratio, plazo, cuota;
		cout << "introduzca el capital prestado: ";
		cin >> capital;
		cout << "introduzca el interes anual: ";
		cin >> ratio;
		cout << "introduzca los años que dura el prestamo: ";
		cin >> plazo;
		cuota = ((capital) * (ratio / 12)) / (100 * (1 - pow(1 + (ratio / 100), -plazo / 12)));
		cout << cuota;
		return 0;
	}

}