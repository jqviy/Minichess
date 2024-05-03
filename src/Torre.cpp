#pragma once
#include "Torre.h"
#include "tablero.h"


bool Torre::movimiento_valido(casilla origen, casilla destino, Tablero& tablero)
{
	if (casilla::mLineal(origen, destino) == true)
		return Pieza::movimiento_valido(origen, destino, tablero);

	return false;
}