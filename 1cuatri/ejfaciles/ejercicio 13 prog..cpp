#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cout << "introduce tres numeros enteros: ";
	cin >> a >> b >> c;
	while (a == b or b == c or a == c)
	{
		cout << "hay dos numeros iguales,introduzca otra vez tres numeros: ";
		cin >> a >> b >> c;
	}

	if (a > b)
	{
		if (a > c)
		{
			if (b > c)
			{
				cout << a << ", " << b << ", " << c;
			}
			else
			{
				cout << a << ", " << c << ", " << b;
			}
		}
		else
		{
			cout << c << ", " << a << ", " << b;
		}
	}

	else
	{
		if (c > b)
		{
			cout << c << ", " << b << ", " << a;
		}
		else
		{
			if (a > c)
			{
				cout << b << ", " << a << ", " << c;
			}
			else
			{
				cout << b << ", " << c << ", " << a;
			}
		}
	}

	return 0;

}



	


	


