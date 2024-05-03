#pragma once
#include "Torre.h"
#include "tablero.h"


bool Torre::movimiento_valido(casilla inicio, casilla fin, Tablero& celda)
{
	if (casilla::mLineal(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}