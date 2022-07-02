#ifndef PUZZLE_H
#define PUZZLE_H

// Autor/a: Nombre y apellidos Carlos Forriol Molina y Ruben Gómez Escalonilla
// email:cforriol@ucm.es y rubgom05@ucm.es
#include <iostream>
#include <string>

#include "MatrizChar.h"
using namespace std;

typedef struct {
	string nomPuzle, nomFichero, modo;
	int nummaxacciones;
	tMatrizChar  imagen1, imagen2;
}tPuzzle;

void mainPuzzle(tPuzzle& jpm);
bool cargarPuzzle(tPuzzle& jpm, string tipo);
void mostrar2(const tPuzzle& jpm);
bool jugar(tPuzzle& jpm);
void accion(tPuzzle& jpm);
#endif
