#pragma once
#include "Caballo.h"
#include "tablero.h"

bool Caballo::movimiento_valido(casilla inicio, casilla fin, Tablero& celda) {

	if(celda[fin] != nullptr && celda[fin]->getColor() == color) {
		return false;
	}
		
	if (casilla::mCaballo(inicio, fin) == true) return true;

	return false;
}
