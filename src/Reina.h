#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:
	Reina(COLOR color) :Pieza(color, REINA, "ReinaBlanca.png", "ReinaNegra.png") {}
};

