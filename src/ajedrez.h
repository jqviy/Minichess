#pragma once
#include "tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Ajedrez
{
	Tablero tablero;
	
public:

	void dibuja();
};

