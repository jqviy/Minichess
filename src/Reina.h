#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:
	Reina(COLOR color) :Pieza(color, REINA, "Reinablanca.png", "Reina.png") {}
};

