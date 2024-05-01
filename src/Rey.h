#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:
	Rey(COLOR color) :Pieza(color, REY, "Reyblanco.png", "Rey.png") {}
};

