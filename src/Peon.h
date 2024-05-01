#pragma once
#include "Pieza.h"
class Peon : public Pieza
{
public:
	Peon(COLOR color) :Pieza(color, PEON, "PeonBlanco.png", "PeonNegro.png") {}
};

