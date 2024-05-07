#pragma once
#include "Reina.h"
#include "tablero.h"
#include "tablero2.h"


 
bool Reina::movimiento_valido(casilla inicio, casilla fin, Tablero& celda)
{
	if (casilla::mLineal(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	else if (casilla::mDiagonal(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}

bool Reina::movimiento_valido(casilla inicio, casilla fin, Tablero2& celda)
{
	if (casilla::mLineal(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	else if (casilla::mDiagonal(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}