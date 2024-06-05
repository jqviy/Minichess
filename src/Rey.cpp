#include "Rey.h"
#include "Tablero.h"
#include "tablero2.h"

//MOVIMIENTOS V�LIDOS PARA TABLERO 6x6
bool Rey::movimiento_valido(casilla inicio, casilla fin, Tablero& celda)
{
	if (casilla::mRey(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}

//MOVIMIENTOS V�LIDOS PARA TABLERO 4x4
bool Rey::movimiento_valido(casilla inicio, casilla fin, Tablero2& celda)
{
	if (casilla::mRey(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}