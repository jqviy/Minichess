#pragma once
#include "Pieza.h"

class Caballo : public Pieza

{
public:
	Caballo(COLOR color) :Pieza(color, CABALLO, "imagenes/CaballoBlanco.png", "imagenes/CaballoNegro.png") {}
};

