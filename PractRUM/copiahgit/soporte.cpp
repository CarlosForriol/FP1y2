
#include "soporte.h"
void iniSoporte(tSoporte& soporte) {
	soporte.ficha = new tFicha[8];
	soporte.capacidad = 8;
	soporte.cont = 0;
}
void nuevaFicha(tSoporte& soporte, tFicha ficha) {
	if (soporte.cont == soporte.capacidad) {
		soporte.capacidad += 8;
		tFicha* aux = new tFicha[soporte.capacidad]; // Definimos la nueva capacidad

		for (int i = 0; i < soporte.cont; i++) {
			aux[i] = soporte.ficha[i];
		}
		aux[soporte.cont] = ficha;
		soporte.cont++;
		delete[] soporte.ficha;
		soporte.ficha = nullptr;
		soporte.ficha = aux;
	}
	else {
		soporte.ficha[soporte.cont] = ficha;
		soporte.cont++;
	}
}
void mostrar(const tSoporte& soporte) {
	cout << "Soporte: ";
	for (int i = 0; i < soporte.cont; i++) {
		colorTexto(soporte.ficha[i].color);
		cout << " " << soporte.ficha[i].numFicha << " ";
		colorTexto(blanco);

	}
	cout << endl;
}
void ordenarPorColor(tSoporte& soporte) {
	int pos;
	int tmpNum;
	tColor tmpCol;
	for (int i = 1; i < INIFICHAS; i++) {
		pos = i;
		while (pos > 0) {
			if (soporte.ficha[pos - 1].color > soporte.ficha[pos].color) {
				tmpNum = soporte.ficha[pos].numFicha;
				tmpCol = soporte.ficha[pos].color;
				soporte.ficha[pos].numFicha = soporte.ficha[pos - 1].numFicha;
				soporte.ficha[pos].color = soporte.ficha[pos - 1].color;
				soporte.ficha[pos - 1].numFicha = tmpNum;
				soporte.ficha[pos - 1].color = tmpCol;
			}
			else if (soporte.ficha[pos - 1].color == soporte.ficha[pos].color) {
				if (soporte.ficha[pos - 1].numFicha > soporte.ficha[pos].numFicha) {
					tmpNum = soporte.ficha[pos].numFicha;
					tmpCol = soporte.ficha[pos].color;
					soporte.ficha[pos].numFicha = soporte.ficha[pos - 1].numFicha;
					soporte.ficha[pos].color = soporte.ficha[pos - 1].color;
					soporte.ficha[pos - 1].numFicha = tmpNum;
					soporte.ficha[pos - 1].color = tmpCol;
				}
			}
			pos--;
		}
	}
}
void ordenarPorNum(tSoporte& soporte) {
	int pos;
	int tmpNum;
	tColor tmpCol;
	for (int i = 1; i < INIFICHAS; i++) {
		pos = i;
		while (pos > 0) {
			if (soporte.ficha[pos - 1].numFicha > soporte.ficha[pos].numFicha) {
				tmpNum = soporte.ficha[pos].numFicha;
				tmpCol = soporte.ficha[pos].color;
				soporte.ficha[pos].numFicha = soporte.ficha[pos - 1].numFicha;
				soporte.ficha[pos].color = soporte.ficha[pos - 1].color;
				soporte.ficha[pos - 1].numFicha = tmpNum;
				soporte.ficha[pos - 1].color = tmpCol;
			}
			else if (soporte.ficha[pos - 1].numFicha == soporte.ficha[pos].numFicha) {
				if (soporte.ficha[pos - 1].color > soporte.ficha[pos].color) {
					tmpNum = soporte.ficha[pos].numFicha;
					tmpCol = soporte.ficha[pos].color;
					soporte.ficha[pos].numFicha = soporte.ficha[pos - 1].numFicha;
					soporte.ficha[pos].color = soporte.ficha[pos - 1].color;
					soporte.ficha[pos - 1].numFicha = tmpNum;
					soporte.ficha[pos - 1].color = tmpCol;
				}
			}
			pos--;
		}
	}
}
void mostrarSeries(tSoporte soporte) {
	int cont = 0;
	ordenarPorNum(soporte);
	for (int i = 0; i < soporte.cont; i++) {

		if (soporte.ficha[i].numFicha == soporte.ficha[i + 1].numFicha && soporte.ficha[i].color != soporte.ficha[i + 1].color)cont++;
		else cont = 0;

		if (cont == 2) {
			colorTexto(soporte.ficha[i - 1].color);
			cout << " " << soporte.ficha[i - 1].numFicha << " ";
			colorTexto(blanco);
			colorTexto(soporte.ficha[i].color);
			cout << " " << soporte.ficha[i].numFicha << " ";
			colorTexto(blanco);
			colorTexto(soporte.ficha[i + 1].color);
			cout << " " << soporte.ficha[i + 1].numFicha << " ";
			colorTexto(blanco);
		}
		if (cont == 3) {
			colorTexto(soporte.ficha[i + 1].color);
			cout << " " << soporte.ficha[i + 1].numFicha << " ";
			colorTexto(blanco);

			cont = 0;
		}
	}
	cout << endl;
}
void mostrarEscaleras(tSoporte soporte) {
	int cont = 0;
	ordenarPorColor(soporte);
	for (int i = 0; i < soporte.cont; i++) {
		if (soporte.ficha[i].color == soporte.ficha[i + 1].color && soporte.ficha[i].numFicha + 1 == soporte.ficha[i + 1].numFicha)cont++;
		else cont = 0;
		if (cont == 2) {
			colorTexto(soporte.ficha[i - 1].color);
			cout << " " << soporte.ficha[i - 1].numFicha << " ";
			colorTexto(blanco);
			colorTexto(soporte.ficha[i].color);
			cout << " " << soporte.ficha[i].numFicha << " ";
			colorTexto(blanco);
			colorTexto(soporte.ficha[i + 1].color);
			cout << " " << soporte.ficha[i + 1].numFicha << " ";
			colorTexto(blanco);
		}
		if (cont > 2 && cont <= 12) {
			colorTexto(soporte.ficha[i + 1].color);
			cout << " " << soporte.ficha[i + 1].numFicha << " ";
			colorTexto(blanco);
		}

		if (cont == 12)cont = 0;
	}
	cout << endl;
}