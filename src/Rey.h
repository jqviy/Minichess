#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:
	Rey(COLOR color) :Pieza(color, REY, "imagenes/ReyBlanco.png", "imagenes/ReyNegro.png") {}
};

