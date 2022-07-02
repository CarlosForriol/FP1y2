#ifndef LISTAPUZZLES_H
#define  LISTAPUZZLES_H
// Autor/a: Nombre y apellidos Carlos Forriol Molina y Ruben Gómez Escalonilla
// email:cforriol@ucm.es y rubgom05@ucm.es
#include <iostream>
#include "Puzzle.h"
using namespace std;



const int MAXPUZZLE = 100;
typedef  tPuzzle* punt;

struct tListaPuzzles {
	int cont = 0;
	punt lista[MAXPUZZLE];


};

typedef tListaPuzzles tPuzzlesReunidos[2];

//Prototipos;
//bool operator == (const tPuzzle& puzzle1, const tPuzzle& puzzle2);
void ordenarCreciente(tListaPuzzles& lp);
void ordenarDeCreciente(tListaPuzzles& lp);
void inicializar(tPuzzlesReunidos& jr);
bool cargar(tPuzzlesReunidos& jr);
void guardar(const tPuzzlesReunidos& jr);
void guardarLista(const tListaPuzzles& lp, ofstream& archivo);
int elegirPuzzle(tListaPuzzles& lp);
bool insertarOrdenado(tListaPuzzles& lp, tPuzzle* p);
bool buscar(const tListaPuzzles& lp, tPuzzle* p, int& pos);
#endif