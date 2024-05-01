#pragma once
#include "Pieza.h"
class Peon : public Pieza
{
public:
	Peon(COLOR color) :Pieza(color, PEON, "imagenes/PeonBlanco.png", "imagenes/PeonNegro.png") {}
};

