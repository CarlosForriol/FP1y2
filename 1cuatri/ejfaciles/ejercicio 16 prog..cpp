#include <iostream>
using namespace std;

int main()
{
	int num;
		cout << "dime un numero:";
	cin >> num;
	while (num != 0) {
		if (num > 0)
		{
			if (num % 2 == 0) {
				cout << num << "es par" << endl;
			}
			else {
				cout << num << "es impar" << endl;
			}
		}
		else
		{
		}
		cout << "vuelva a introducir un numero: ";
		cin >> num;
	}
	return 0;

}