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

//comprobar haber pulsado la misma casilla en movimiento diagonal
bool casilla::noSaltarDiagonal(casilla inicio, casilla fin)
{
	if ((fin.columna - inicio.columna == fin.fila - inicio.fila) && fin.columna != inicio.columna && fin.fila != inicio.fila) return true;
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


//primer movimiento peon blanco
bool casilla::mPrimeroPeonBlanco(casilla inicio, casilla fin)
{
	if (fin.fila == inicio.fila + 2 && fin.columna == inicio.columna) return true;
	return false;
}

//movimiento peon blanco
bool casilla::mPeonBlanco(casilla inicio, casilla fin)
{
	if (fin.fila == inicio.fila + 1 && fin.columna == inicio.columna) return true;
	return false;
}

//movimiento diagonal del peon blanco
bool casilla::mPeonDiagonalBlanco(casilla inicio, casilla fin)
{
	if ((abs(fin.columna - inicio.columna) == 1) && (fin.fila == inicio.fila + 1)) return true;
	return false;
}

//primer movimiento peon negro
bool casilla::mPrimeroPeonNegro(casilla inicio, casilla fin)
{
	if (fin.fila == inicio.fila - 2 && fin.columna == inicio.columna) return true;
	return false;
}
//movimiento peon negro
bool casilla::mPeonNegro(casilla inicio, casilla fin)
{
	if (fin.fila == inicio.fila - 1 && fin.columna == inicio.columna) return true;
	return false;
}

//movimiento para comer del peon negro
bool casilla::mPeonDiagonalNegro(casilla inicio, casilla fin)
{
	if ((abs(fin.columna - inicio.columna) == 1) && (fin.fila == inicio.fila - 1)) return true;
	return false;
}
