#pragma once
#include <iostream>
#include <cmath>

class casilla
{

	int fila = 0, columna = 0;
public:
	casilla(int fila, int columna):fila(fila), columna(columna) {}
	static bool mLineal(casilla inicio, casilla fin);
	static bool mDiagonal(casilla inicio, casilla fin);
	static bool mRey(casilla inicio, casilla fin);
	static bool mCaballo(casilla inicio, casilla fin);

};

