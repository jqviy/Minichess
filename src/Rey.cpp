#include "Rey.h"
#include "Tablero.h"
#include "tablero2.h"

//Definicion de movimientos validos unitarios + la definicion comun de Pieza 
bool Rey::movimiento_valido(casilla inicio, casilla fin, Tablero& celda)
{
	if (casilla::mRey(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}

bool Rey::movimiento_valido(casilla inicio, casilla fin, Tablero2& celda)
{
	if (casilla::mRey(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}