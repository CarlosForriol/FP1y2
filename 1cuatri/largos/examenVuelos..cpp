#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int MAX_VUELOS = 50;

typedef enum  {embarcando, operado, retrasado, suspendido}tEstado;
 
typedef struct {

	string numVuelo;
	string destino;
	char terminal;
	int puerta;
	tEstado estado;

}tVuelo;
typedef tVuelo tarrayVuelos[MAX_VUELOS];

typedef struct {
	tarrayVuelos vuelos;
	int cont;
}tListaVuelos;

string enum2string(tEstado estado);
tEstado string2enum(string estado_string);
bool cargar(tListaVuelos& listaVuelos);
void mostrar(tListaVuelos listaVuelos);
int menu();
bool guardar(tListaVuelos listavuelos);
int buscarVuelo(tListaVuelos listavuelos,const string numVuelo );
void mostrarVuelo(tListaVuelos listavuelos, string numVuelo);
void actualizarVuelo(tListaVuelos listavuelos, int pos, string estado);





int main() {
	int opcion;
	tListaVuelos listaVuelos;
	string numvuelo;
	string estado;
	int pos;
	if (cargar(listaVuelos) == true) {


		cout << "1. Obtener informacion de un vuelo" << endl;
		cout << "2. Actualizar el estado de un vuelo" << endl;
		cout << "3. Salir" << endl;
		opcion = menu();

		while (opcion != 3) {
			if (opcion == 1) {
				cout << "Introduce numero de vuelo:" << endl;
				cin >> numvuelo;
				mostrarVuelo(listaVuelos, numvuelo);
			}
			else if (opcion ==  2) {
				cout << "Introduce numero de vuelo:" << endl;
				cin >> numvuelo;
				pos = buscarVuelo(listaVuelos, numvuelo);
				cout << "Introduce actualizacion de estado: ";
				cin >> estado;
				cout << endl;
				actualizarVuelo(listaVuelos, pos, estado);
				guardar(listaVuelos);
			}
			cin >> opcion;
		}
	}

	system("pause");
	return 0;
}










string enum2string(tEstado estado)
{
	string estado_cadena;

	if (estado == embarcando)
	{
		estado_cadena = "embarcando";
	}
	else if (estado == operado)
	{
		estado_cadena = "operado";
	}
	else if (estado == retrasado)
	{
		estado_cadena = "retrasado";
	}
	else
	{
		estado_cadena = "suspendido";
	}

	return estado_cadena;
}

tEstado string2enum(string estado_string)
{
	tEstado estado;

	if (estado_string == "embarcando")
	{
		estado = embarcando;
	}
	else if (estado_string == "operado")
	{
		estado = operado;
	}
	else if (estado_string == "retrasado")
	{
		estado = retrasado;
	}
	else
	{
		estado = suspendido;
	}

	return estado;
}

bool cargar(tListaVuelos & listaVuelos) {
	bool caso = false;
	ifstream archivo;
	int i = 0;
	string estado;

	archivo.open("pendientes.txt");
	if (archivo.is_open() == true) {
		caso = true;
		listaVuelos.cont = 0;

		while (i < MAX_VUELOS && !archivo.eof()) {

			getline(archivo, listaVuelos.vuelos[i].numVuelo);
			getline(archivo, listaVuelos.vuelos[i].destino);
			archivo >> listaVuelos.vuelos[i].terminal;
			archivo >> listaVuelos.vuelos[i].puerta;
			archivo >> estado;
			listaVuelos.vuelos[i].estado = string2enum(estado);
			listaVuelos.cont++;
			i++;
		}
	}
	return caso;

}

void mostrar(tListaVuelos listaVuelos) {

	for (int i = 0; i <listaVuelos.cont; i++) {
		cout << listaVuelos.vuelos[i].numVuelo;
		cout << listaVuelos.vuelos[i].destino;
		cout << listaVuelos.vuelos[i].terminal;
		cout << listaVuelos.vuelos[i].puerta;
		cout << enum2string(listaVuelos.vuelos[i].estado);
	}

}

int menu(){

	int opcion = -1;
	while (opcion < 1 || opcion > 3)
	{
		cin >> opcion;
	}

	return opcion;
}

bool guardar(tListaVuelos listavuelos) {
	ofstream salida;
	bool caso = false;
	int i = 0;
	salida.open("pendientes.txt");

	if (salida.is_open()) {
		caso = true;
		while (i < listavuelos.cont)
		{
			if (enum2string(listavuelos.vuelos[i].estado) == "retrasado" || enum2string(listavuelos.vuelos[i].estado) == "suspendido")
			{
				salida << listavuelos.vuelos[i].numVuelo << endl;
				salida << listavuelos.vuelos[i].destino << endl;
				salida << listavuelos.vuelos[i].terminal << endl;
				salida << listavuelos.vuelos[i].puerta << endl;
				salida << enum2string(listavuelos.vuelos[i].estado) << endl;

			}

			i++;
		}
	}
	return caso;

}
int buscarVuelo(tListaVuelos listavuelos, const string numVuelo) {
	int pos = -1;
	for (int i = 0; i < listavuelos.cont; i++) {
		if (listavuelos.vuelos[i].numVuelo == numVuelo) {
			pos = i;
		}
	}
	return pos;
}

void mostrarVuelo(tListaVuelos listavuelos,  string numVuelo) {
	int pos = buscarVuelo(listavuelos, numVuelo);
	
	
	if (pos != -1 ) {
			cout << listavuelos.vuelos[pos].numVuelo << endl;
			cout << listavuelos.vuelos[pos].destino << endl;
			cout << listavuelos.vuelos[pos].terminal << endl;
			cout <<  listavuelos.vuelos[pos].puerta << endl;
			cout << enum2string(listavuelos.vuelos[pos].estado) << endl;
    }


}
void actualizarVuelo(tListaVuelos listavuelos,int pos, string estado) {
	listavuelos.vuelos[pos].estado = string2enum(estado);
}
