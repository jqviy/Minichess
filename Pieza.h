#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pieza
{
public:
	//color de la pieza
	enum COLOR { NS = -1, BLANCA, NEGRA };
	//tipo de la pieza
	enum TIPO { NF = -1, PEON, CABALLO, REINA, REY, TORRE };
	int fila = 0, columna = 0;

protected:
	bool seleccionado;
	int posx;
	int posy;
	TIPO tipo = NF;
	COLOR color = NS;
public:
	Pieza();
	Pieza(TIPO t, COLOR c, int x, int y);
	Pieza(int fila, int columna) :fila(fila), columna(columna) {}

	TIPO getPieza() { return tipo; }
	COLOR getColor() { return color; }


	static bool mLineal(Pieza inicio, Pieza fin);
	static bool mDiagonal(Pieza inicio, Pieza fin);

};


