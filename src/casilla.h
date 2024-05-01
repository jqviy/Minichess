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
	static bool noMoverDiagonal(casilla inicio, casilla fin);
	static bool mPrimeroPeonBlanco(casilla inicio, casilla origen);
    static bool mPeonBlanco(casilla inicio, casilla fin);
	static bool mPeonDiagonalBlanco(casilla inicio, casilla fin);
	static bool mPrimeroPeonNegro(casilla inicio, casilla fin);
	static bool mPeonNegro(casilla inicio, casilla fin);
	static bool mPeonDiagonalNegro(casilla inicio, casilla fin);

};

