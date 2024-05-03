#pragma once
#include <iostream>
#include <cmath>

class casilla
{
public:
	int fila = 0, columna = 0;
	casilla(){}
	casilla(int fila, int columna):fila(fila), columna(columna) {}
	static bool mLineal(casilla inicio, casilla fin);
	static bool mDiagonal(casilla inicio, casilla fin);
	static bool noSaltarDiagonal(casilla inicio, casilla fin);
	static bool mRey(casilla inicio, casilla fin);
	static bool mCaballo(casilla inicio, casilla fin);
	static bool mPrimeroPeonBlanco(casilla inicio, casilla origen);
    static bool mPeonBlanco(casilla inicio, casilla fin);
	static bool mPeonDiagonalBlanco(casilla inicio, casilla fin);
	static bool mPrimeroPeonNegro(casilla inicio, casilla fin);
	static bool mPeonNegro(casilla inicio, casilla fin);
	static bool mPeonDiagonalNegro(casilla inicio, casilla fin);

};

