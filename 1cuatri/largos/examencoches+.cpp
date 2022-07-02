#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int MAX_COCHES = 200;
const int MAX_ZONAS=10;
const int MAX_PLAZAS = 25;

typedef enum {Mini, Medio, Suv, Grande}tTipo;

typedef struct {
	tTipo tipo;
	string matricula;
	string hora;
}tCoche;

typedef tCoche arraycoche[MAX_COCHES];

typedef struct {
	arraycoche coche;
	int cont=0;
}tListaCoches;

typedef struct {
	string matricula;
	string hora;
}tPlaza;
typedef tPlaza tListaPlaza[MAX_PLAZAS];




typedef struct {
	char letra;
	tTipo tipo;
	int capacidad;
	int ocupadas = 0;
	tListaPlaza plaza;
}tZona;

typedef tZona tParking[MAX_ZONAS];

bool cargarZonas(tParking& parking);
bool cargarCoches(tListaCoches& listaCoches);
tTipo numToTip(int num);
int siguiente(const tListaCoches& listaCoches);
int buscarZona(const tParking& parking, tCoche coche);
void asigna(tParking& parking, tListaCoches& listaCoches, tListaCoches& desatenidos);
void elimina(tListaCoches& listaCoches, int indice);
void muestra(const tParking& parking);
void graba(const tListaCoches& listaCoches);
string TipToStr(tTipo tipo);

int main(){
	tParking parking;
	tListaCoches listaCoches;
	tListaCoches desatenidos;
	tCoche coche;

	cargarZonas(parking);

	cargarCoches(listaCoches);

	asigna(parking, listaCoches, desatenidos);

	muestra(parking);

	graba(desatenidos);
}
tTipo numToTip(int num)
{
	tTipo tipo = Suv;

	switch (num)
	{
	case 0:
	{
		tipo = Mini;
	}
	break;
	case 1:
	{
		tipo = Medio;
	}
	break;

	case 2:
	{
		tipo = Suv;
	}
	break;
	case 3:
	{
		tipo = Grande;
	}
	}

	return tipo;
}
string TipToStr(tTipo tipo)
{
	string tip;

	switch (tipo)
	{
	case Mini:
	{
		tip = "Mini";
	}

	break;

	case Medio:
	{
		tip = "Medio";
	}

	break;

	case Suv:
	{
		tip = "SUB";
	}

	break;

	case Grande:
	{
		tip = "Grande";
	}
	}

	return tip;
}

bool cargarZonas(tParking& parking) {
	bool caso = false;
	ifstream archivo;
	archivo.open("zonas.txt");
	int num;
	if (archivo.is_open()) {
		caso = true;
		for (int i = 0; i < MAX_ZONAS; i++) {
			archivo >> parking[i].letra;
			archivo >> num;
			parking[i].tipo = numToTip(num);
			archivo >> parking[i].capacidad;
				
			
		}
	}
	return caso;
}
bool cargarCoches(tListaCoches& listaCoches) {
	bool caso = false;
	ifstream archivo;
	archivo.open("coches.txt");
	int num;
	
	int i = 0;
	if (archivo.is_open()) {
		caso = true;
		archivo >> num;
		while (num != -1) {
			listaCoches.coche[i].tipo = numToTip(num);
			archivo >> listaCoches.coche[i].matricula;
			archivo >> listaCoches.coche[i].hora;
			archivo >> num;
			i++;
		}
		listaCoches.cont = i;
	}
	return caso;
}
int siguiente(const tListaCoches& listaCoches) {
	string hora = listaCoches.coche[0].hora;
	int indice = 0;
	for (int i = 0; i < listaCoches.cont; i++) {

		if (hora > listaCoches.coche[0].hora) {
			hora = listaCoches.coche[i].hora;
			indice = i;
		}
	}
	return indice;
}
int buscarZona(const tParking& parking, tCoche coche)
{
	int i = 0;
	int ind = 11;

	while (i < ind)
	{
		if (parking[i].tipo == coche.tipo && parking[i].capacidad != parking[i].ocupadas)
		{
			ind = i;
		}
		i++;
	}

	return ind;
}
void asigna(tParking& parking, tListaCoches& listaCoches, tListaCoches& desatenidos) {
	tCoche coche;
	int indC;
	int indZ;
	int i = 0;
	while (listaCoches.cont != 0) {

		indC = siguiente(listaCoches);

		coche = listaCoches.coche[indC];

		elimina(listaCoches, indC);



		indZ = buscarZona(parking, coche);
		if (indZ == -1)
		{
			desatenidos.coche[desatenidos.cont].hora= coche.hora;
			desatenidos.coche[desatenidos.cont].matricula = coche.matricula;
			desatenidos.coche[desatenidos.cont].tipo = coche.tipo;

			desatenidos.cont++;
		}
		else
		{
			parking[indZ].plaza[parking[indZ].ocupadas].hora = coche.hora;
			parking[indZ].plaza[parking[indZ].ocupadas].matricula = coche.matricula;
			parking[indZ].ocupadas++;
		}

	}
}

void elimina(tListaCoches& listaCoches, int indice)
{
	for (int i = indice; i < listaCoches.cont; i++)
	{
		listaCoches.coche[i] = listaCoches.coche[i + 1];
	}

	listaCoches.cont--;
}
void muestra(const tParking& parking) {
	for (int i = 0; i < 10; i++) {
		cout<< "zona"<< parking[i].letra << "-"<< TipToStr(parking[i].tipo)<< "-"<< " - Ocupadas " << parking[i].ocupadas << " de " << parking[i].capacidad << endl;
		for (int j = 0; j < parking[i].ocupadas; j++) {
			cout << parking[i].plaza[j].matricula << " " << parking[i].plaza[j].hora << endl;
		}
		cout << endl << endl;
	}
}
void graba(const tListaCoches& listaCoches) {
	ofstream archivo;
	archivo.open("desantendidos.txt");
	if (archivo.is_open()) {

		for (int i = 0; i < listaCoches.cont; i++) {
			archivo << listaCoches.coche[i].matricula << " " << listaCoches.coche[i].matricula << endl;
		}
		archivo << "-1" << endl;
	}
}