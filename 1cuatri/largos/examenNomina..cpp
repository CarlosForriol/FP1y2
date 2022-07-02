#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

const int MAX_APUNTES = 500;

typedef struct {
	int dia=0;
	int mes=0;
	int ano=0;
}tFecha;

typedef struct {
	tFecha fecha;
	float importe=0;
	string concepto;
}tApunte;

typedef tApunte tCuenta[MAX_APUNTES];

bool cargar(const string &nombre_fichero, tCuenta &cuenta);
float importe(const tCuenta cuenta,int num);
float gastoMedioLuz(const tCuenta cuenta, int num, int ano);
void mostrar(const tCuenta cuenta, int num);
int menu(); 

int main() {
	tCuenta cuenta;
	string mifichero;
	int op;
	int num = cargar("fichero.txt", cuenta);
	while (op = menu() != 0)
	{
		op = menu();

		switch (op)
		{
		case 1:
			cargar("fichero.txt", cuenta);
			break;
		case 2:
			int importes;
			importes = importe(cuenta, num);
			cout << importes;
			break;
		case 3:
			mostrar(cuenta, num);
			break;
		default:
			int ano;
			int gasto;
			cin >> ano;
			gasto = gastoMedioLuz(cuenta, ano, num);
			cout << gasto;
			break;
		}


	}

	system("pause");


}


bool cargar(const string& nombre_fichero, tCuenta& cuenta){
	ifstream archivo;
	int i = 0;
	tApunte apunte;
	archivo.open(nombre_fichero);

	if (archivo.is_open() == true) {
		
		while ( i < MAX_APUNTES &&  !archivo.eof() ) {
			archivo >> apunte.fecha.dia;
			archivo >> apunte.fecha.mes;
			archivo >> apunte.fecha.ano;
			archivo >> apunte.importe;
			archivo >> apunte.concepto;

			cuenta[i] = apunte;
			i++;
		}
		archivo.close();
	}
	return i;


}
float importe(const tCuenta cuenta, int num) {
	
	float total = 0;
	int i = 0;

	while (i < num && cuenta[i].concepto != "Salario") {
		i++;
	}
	if (cuenta[i].concepto == "Salario") {
		total = cuenta[i].importe;
	}
	return total;

}

float gastoMedioLuz(const tCuenta cuenta, int num, int ano) {

	float gastoMedio = 0;
	float contadorLuz=0;
	float importe = 0;

	for (int i = 0; i < num; i++) {
		if (cuenta[i].fecha.ano == ano) {
			if (cuenta[i].concepto == "Luz") {
				importe += cuenta[i].importe;
				contadorLuz++;
			}
		}
	}
	if (contadorLuz != 0) {
		gastoMedio = importe / contadorLuz;
	}
	gastoMedio = abs(gastoMedio);
	return gastoMedio;

}
void mostrar(const tCuenta cuenta, int num){

	for (int i = 0; i < num; i++) {
		cout << cuenta[i].fecha.dia << " " << cuenta[i].fecha.mes << " " << cuenta[i].fecha.ano << " " << cuenta[i].importe << " " << cuenta[i].concepto << endl;
	}
}
int menu() {
	int opcion = -1;
	while (opcion < 0|| opcion > 4)
	{
		cin >> opcion;
	}

	return opcion;
}