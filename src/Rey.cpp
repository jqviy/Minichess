#include "Rey.h"
#include "Tablero.h"

//Definicion de movimientos validos unitarios + la definicion comun de Pieza 
bool Rey::movimiento_valido(casilla inicio, casilla fin, Tablero& celda)
{
	if (casilla::mRey(inicio, fin) == true)
		return Pieza::movimiento_valido(inicio, fin, celda);

	return false;
}