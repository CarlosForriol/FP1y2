#include <iostream>
using namespace std;
int main()
{
	double num1, num2;
	char operador;

	cout << "Operacion que quiera realizar: ";
	cin >> num1 >> operador >> num2;

	while (num1 != 0)
	{
		switch (operador)
		{
		case '+': cout << num1 << "+" << num2 << "=" << num1 + num2;
			break;
		case '-': cout << num1 << "-" << num2 << "=" << num1 - num2;
			break;
		case '*': cout << num1 << "*" << num2 << "=" << num1 * num2;
			break;
		case '/': cout << num1 << "/" << num2 << "=" << num1 / num2;
			break;
		default: cout << "Esa operacion no se puede realizar";
		}
		break;
	}
	return 0
}