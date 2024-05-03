#pragma once
#include "Pieza.h"
class Torre:public Pieza
{
public:
	Torre(COLOR color) :Pieza(color, TORRE, "imagenes/TorreBlanca.png", "imagenes/TorreNegra.png") {}
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero& celda);
};

