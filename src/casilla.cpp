#include "casilla.h"


bool casilla::mLineal(casilla inicio, casilla fin)
{
	if ((fin.fila != inicio.fila && fin.columna == inicio.columna) || (fin.columna != inicio.columna && fin.fila == inicio.fila)) return true;
	return false;
}


bool casilla::mDiagonal(casilla inicio, casilla fin)
{
	if (((abs(fin.fila - inicio.fila) + abs(fin.columna - fin.columna)) % 2 == 0) && (abs(fin.fila - inicio.fila) == abs(fin.columna - inicio.columna))) return true;
	return false;
}
