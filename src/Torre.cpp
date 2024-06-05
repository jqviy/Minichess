#pragma once
#include "Torre.h"
#include "tablero.h"
#include "tablero2.h"

//MOVIMIENTOS V�LIDOS PARA TABLERO 6x6
bool Torre::movimiento_valido(casilla inicio, casilla fin, Tablero& celda)
{
	if (casilla::mLineal(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}

//MOVIMIENTOS V�LIDOS PARA TABLERO 4x4
bool Torre::movimiento_valido(casilla inicio, casilla fin, Tablero2& celda)
{
	if (casilla::mLineal(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}