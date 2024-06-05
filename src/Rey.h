#pragma once
#include "Pieza.h"

//CLASE ENCARGADA DE MOVIMIENTOS E IMÁGENES DE LA PIEZA REY
class Rey:public Pieza
{
public:
	Rey(COLOR color) :Pieza(color, REY, "imagenes/ReyBlanco.png", "imagenes/ReyNegro.png") {}
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero& celda);
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero2& celda);
};

