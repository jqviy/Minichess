#pragma once
#include "Pieza.h"
#include "tablero2.h"

class Reina:public Pieza
{
public:
	Reina(COLOR color) :Pieza(color, REINA, "imagenes/ReinaBlanca.png", "imagenes/ReinaNegra.png") {}
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero& celda);
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero2& celda);
};


