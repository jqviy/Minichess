#include "casilla.h"

//movimiento recto
bool casilla::mLineal(casilla inicio, casilla fin)
{
	if ((fin.fila != inicio.fila && fin.columna == inicio.columna) || (fin.columna != inicio.columna && fin.fila == inicio.fila)) return true;
	return false;
}

//movimiento diagonal
bool casilla::mDiagonal(casilla inicio, casilla fin)
{
	if (((abs(fin.fila - inicio.fila) + abs(fin.columna - fin.columna)) % 2 == 0) && (abs(fin.fila - inicio.fila) == abs(fin.columna - inicio.columna))) return true;
	return false;
}

//movimiento del rey
bool casilla::mRey(casilla inicio, casilla fin)
{
	if (abs(inicio.fila - fin.fila) <= 1 && abs(fin.columna - inicio.columna) <= 1) return true;
	return false;
}

//movimiendo del caballo
bool casilla::mCaballo(casilla inicio, casilla fin)
{
	if (((abs(fin.fila - inicio.fila) == 1) && (abs(fin.columna - inicio.columna) == 2)) || ((abs(fin.fila - inicio.fila) == 2) && (abs(fin.columna - inicio.columna) == 1))) return true;
	return false;
}

//caso de pulsar misma casilla en movimiento diagonal
bool casilla::noMoverDiagonal(casilla inicio, casilla fin)
{
	if ((fin.columna - inicio.columna == fin.fila - inicio.fila) && fin.columna != inicio.columna && fin.fila != inicio.fila) return true;
	return false;
}

//movimiento peon blanco
bool casilla::mPeonBlanco(casilla inicio, casilla fin)
{
	if (fin.fila == inicio.fila + 1 && fin.columna == inicio.columna) return true;
	return false;
}