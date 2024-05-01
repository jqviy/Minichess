#pragma once
#include "Pieza.h"

class Caballo : public Pieza

{
public:
	Caballo(COLOR color) :Pieza(color, CABALLO, "CaballoBlanco.png", "CaballoNegro.png") {}
};

