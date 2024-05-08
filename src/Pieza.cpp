#include "Pieza.h"
#include "Tablero.h"
#include "tablero2.h"
#include "tablerobot.h"


bool Pieza::movimiento_valido(casilla inicio, casilla fin, Tablero& celda)
{
	int aux;

	//Se revisa si la casilla está ocupada por una pieza del mismo color que el turno 
	if (celda[fin] != nullptr && celda[fin]->getColor() == color) return false;

	//COMPROBACION DE TRAYECTORIA. Objetivo: no saltar entre piezas
	//LINEAL EN FILAS 
	if (fin.fila != inicio.fila && fin.columna == inicio.columna)
	{
		aux = (fin.fila - inicio.fila) / abs(fin.fila - inicio.fila);
		while (abs(fin.fila - inicio.fila) > 1)
		{
			inicio.fila = inicio.fila + aux;
			if (celda[inicio] != nullptr) return false;
		}
	}

	//LINEAL EN COLUMNAS
	else if (fin.columna != inicio.columna && fin.fila == inicio.fila)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			if (celda[inicio] != nullptr) return false;
		}
	}

	//DIAGONAL DE IZQUIERDA A DERECHA
	else if (casilla::noSaltarDiagonal(inicio, fin) == true)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			inicio.fila = inicio.fila + aux;
			if (celda[inicio] != nullptr) return false;
		}
	}

	//DIAGONAL DE DERECHA A IZQUIERDA
	else if (fin.columna != inicio.columna && fin.fila != inicio.fila)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			inicio.fila = inicio.fila - aux;
			if (celda[inicio] != nullptr) return false;
		}
	}

	return true;
}

bool Pieza::movimiento_valido(casilla inicio, casilla fin, Tablero2& celda)
{
    int aux;

    //Se revisa si la casilla está ocupada por una pieza del mismo color que el turno 
    if (celda[fin] != nullptr && celda[fin]->getColor() == color) return false;

    //COMPROBACION DE TRAYECTORIA. Objetivo: no saltar entre piezas
    //LINEAL EN FILAS 
    if (fin.fila != inicio.fila && fin.columna == inicio.columna)
    {
        aux = (fin.fila - inicio.fila) / abs(fin.fila - inicio.fila);
        while (abs(fin.fila - inicio.fila) > 1)
        {
            inicio.fila = inicio.fila + aux;
            if (celda[inicio] != nullptr) return false;
        }
    }

    //LINEAL EN COLUMNAS
    else if (fin.columna != inicio.columna && fin.fila == inicio.fila)
    {
        aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
        while (abs(fin.columna - inicio.columna) > 1)
        {
            inicio.columna = inicio.columna + aux;
            if (celda[inicio] != nullptr) return false;
        }
    }

    //DIAGONAL DE IZQUIERDA A DERECHA
    else if (casilla::noSaltarDiagonal(inicio, fin) == true)
    {
        aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
        while (abs(fin.columna - inicio.columna) > 1)
        {
            inicio.columna = inicio.columna + aux;
            inicio.fila = inicio.fila + aux;
            if (celda[inicio] != nullptr) return false;
        }
    }

    //DIAGONAL DE DERECHA A IZQUIERDA
    else if (fin.columna != inicio.columna && fin.fila != inicio.fila)
    {
        aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
        while (abs(fin.columna - inicio.columna) > 1)
        {
            inicio.columna = inicio.columna + aux;
            inicio.fila = inicio.fila - aux;
            if (celda[inicio] != nullptr) return false;
        }
    }

    return true;
}
bool Pieza::movimiento_valido(casilla inicio, casilla fin, Tablerobot& celda)
{
	int aux;

	//Se revisa si la casilla está ocupada por una pieza del mismo color que el turno 
	if (celda[fin] != nullptr && celda[fin]->getColor() == color) return false;

	//COMPROBACION DE TRAYECTORIA. Objetivo: no saltar entre piezas
	//LINEAL EN FILAS 
	if (fin.fila != inicio.fila && fin.columna == inicio.columna)
	{
		aux = (fin.fila - inicio.fila) / abs(fin.fila - inicio.fila);
		while (abs(fin.fila - inicio.fila) > 1)
		{
			inicio.fila = inicio.fila + aux;
			if (celda[inicio] != nullptr) return false;
		}
	}

	//LINEAL EN COLUMNAS
	else if (fin.columna != inicio.columna && fin.fila == inicio.fila)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			if (celda[inicio] != nullptr) return false;
		}
	}

	//DIAGONAL DE IZQUIERDA A DERECHA
	else if (casilla::noSaltarDiagonal(inicio, fin) == true)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			inicio.fila = inicio.fila + aux;
			if (celda[inicio] != nullptr) return false;
		}
	}

	//DIAGONAL DE DERECHA A IZQUIERDA
	else if (fin.columna != inicio.columna && fin.fila != inicio.fila)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			inicio.fila = inicio.fila - aux;
			if (celda[inicio] != nullptr) return false;
		}
	}

	return true;
}
