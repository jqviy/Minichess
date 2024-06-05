#pragma once
#include "Pieza.h"

//CLASE ENCARGADA DE MOVIMIENTOS E IM�GENES DE LA PIEZA TORRE
class Torre:public Pieza
{
public:
	Torre(COLOR color) :Pieza(color, TORRE, "imagenes/TorreBlanca.png", "imagenes/TorreNegra.png") {}
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero& celda);
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero2& celda);
};

