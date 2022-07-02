#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

const int MAX_APUNTES = 500;

typedef struct
{
	int dia;
	int mes;
	int anio;
}tFecha;

typedef struct 
{
	tFecha fecha;
	float importe;
	string concepto;
}tApunte;

typedef tApunte tCuenta[MAX_APUNTES];

int cargar(const string &nombre_fichero, tCuenta &mi_cuenta);
float primeraNomina(const tCuenta mi_cuenta, int num);
void mostrar(const tCuenta mi_cuenta, int num);
float gastoMedio(const tCuenta mi_cuenta, int anio, int num);
int menu();

int main()
{
	tCuenta cuenta;
	string mifichero;
	int op;
	int num = cargar("mifichero.txt", cuenta);
	while (op = menu()!= 0)
	{
		op = menu();

		switch (op)
		{
		case 1: 
			cargar("mifichero.txt", cuenta);
			break;
		case 2:
			int importe;
			importe = primeraNomina(cuenta, num);
			cout << importe;
			break;
		case 3:
			mostrar(cuenta, num);
			break;
		default:
			int anio;
			int gasto;
			cin >> anio;
			gasto = gastoMedio(cuenta, anio, num);
			cout << gasto;
			break;
		}

		
	}
	
	system("pause");
}

int cargar(const string &nombre_fichero, tCuenta &mi_cuenta)
{
	ifstream archivo;							//Declaramos las variables
	tApunte aux;
	int i = 0;

	archivo.open(nombre_fichero);				//Abrimos el archivo	

	if (archivo.is_open() == true)
	{
		while (!archivo.eof() && i<MAX_APUNTES)  //Si no es fin del fichero y la posicion del array es menor que el numero máximo, obtener elementos
		{
			archivo >> aux.fecha.dia;			//Metemos uno a uno los elementos a un tApunte auxiliar
			archivo >> aux.fecha.mes;
			archivo >> aux.fecha.anio;
			archivo >> aux.importe;
			archivo >> aux.concepto;

			mi_cuenta[i] = aux;				 //Vamos pasando ese tApunte al array de tApuntes
			i++;							//Pasamos a la siguiente posición del array
		}

		archivo.close();					//Cerramos el archivo

	}

	return i;								//Devolvemos número de elementos cargados
}

void mostrar(const tCuenta mi_cuenta, int num)
{
	for (int i = 0; i < num; i++) //recorremos el array
	{
		cout << mi_cuenta[i].fecha.dia << " ";
		cout << mi_cuenta[i].fecha.mes << " ";
		cout << mi_cuenta[i].fecha.anio << " ";
		cout << mi_cuenta[i].importe << " ";
		cout << mi_cuenta[i].concepto << " " << endl; //mostramos los datos de cada posicion
	}
}

float primeraNomina(const tCuenta mi_cuenta, int num)
{
	float importe=0;

	int i = 0;
	while (i< num && (mi_cuenta[i].concepto != "Salario"))
	{
		i++;
	}

	if (mi_cuenta[i].concepto == "Salario")
	{
		importe = mi_cuenta[i].importe;
	}
	
	return importe;

}

float gastoMedio(const tCuenta mi_cuenta, int anio, int num)
{
	float gasto_medio = 0;
	float contador_luz = 0;
	float importe = 0;

	for (int i = 0; i < num; i++)
	{
		if (mi_cuenta[i].fecha.anio == anio)
		{
			if (mi_cuenta[i].concepto == "Luz")
			{
				importe += mi_cuenta[i].importe;
				contador_luz++;
			}
		}
	}

	if(contador_luz != 0)
	{
		gasto_medio = importe / contador_luz;
	}

	gasto_medio = abs(gasto_medio);
	


	return gasto_medio;
}

int menu()
{
	
	int opcion=-1;
	

	while (opcion < 0 || opcion > 4)
	{
		cin >> opcion;
	}

	return opcion;
}
