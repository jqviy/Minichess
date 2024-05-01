#pragma once
#include "Pieza.h"
class Torre:public Pieza
{
public:
	Torre(COLOR color) :Pieza(color, TORRE, "Torreblanca.png", "Torre.png") {}
};

