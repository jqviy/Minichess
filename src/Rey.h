#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:
	Rey(COLOR color) :Pieza(color, REY, "imagenes/ReyBlanco.png", "imagenes/ReyNegro.png") {}
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero& celda);
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero2& celda);
};

