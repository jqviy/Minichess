#pragma once
#include "Pieza.h"
class Torre:public Pieza
{
public:
	Torre(COLOR color) :Pieza(color, TORRE, "TorreBlanca.png", "TorreNegra.png") {}
};
