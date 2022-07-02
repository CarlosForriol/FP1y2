#include <iostream>
using namespace std;

int main()
{
	double num;
	double medida;
	cout << "Introduzca un numero: ";
	cin >> num;
	cin >> medida;

	if (medida == 1)
	{
		cout << num * 2.54 << "cm";
	}
	else
	{
		if (medida == 2)
		{
			cout << num * 1609.334 << "m";
		}
		else
		{
			if (medida == 3)
			{
				cout << (num - 32) * (5.0 / 9) << "c";
			}
			else
			{
				if (medida == 4)
				{
					cout << num * 3.79 << "l";
				}
				else
				{
					if (medida == 5)
					{
						cout << num *28.35 << "gr";
					}
					else
					{
						cout << num * 0.45 << "kg";
					}
				}
			}
		}
	}
	return 0;
}