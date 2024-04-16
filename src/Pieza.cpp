#include "Pieza.h"
Pieza::Pieza()
{
	tipo = NF;
	color = NS;
	posx = -1;
	posy = -1;
}

Pieza::Pieza(TIPO t, COLOR c, int x, int y)
{
	tipo = t;
	color = c;
	posx = x;
	posy = y;
}



bool Pieza::mLineal(Pieza inicio, Pieza fin)
{
	if ((fin.fila != inicio.fila && fin.columna == inicio.columna) || (fin.columna != inicio.columna && fin.fila == inicio.fila)) return true;
	return false;
}


bool Pieza::mDiagonal(Pieza inicio, Pieza fin)
{
	if (((abs(fin.fila - inicio.fila) + abs(fin.columna - fin.columna)) % 2 == 0) && (abs(fin.fila - inicio.fila) == abs(fin.columna - inicio.columna))) return true;
	return false;
}

