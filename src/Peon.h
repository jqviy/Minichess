#pragma once
#include "Pieza.h"

//CLASE ENCARGADA DE MOVIMIENTOS E IM�GENES DE LA PIEZA PE�N
class Peon : public Pieza
{
public:
	Peon(COLOR color) :Pieza(color, PEON, "imagenes/PeonBlanco.png", "imagenes/PeonNegro.png") {}
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero & celda);
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero2& celda);
	
};

