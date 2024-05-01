#pragma once
#include <string>
#include <iostream>
#include "ETSIDI.h"
using namespace ETSIDI;
class Pieza
{	
public:
	//color de la pieza
	enum COLOR { NS = -1, BLANCA, NEGRA };
	//tipo de la pieza
	enum TIPO { NF = -1, PEON, CABALLO, REINA, REY, TORRE };

	Pieza(){tipo = NF; color = NS; posx = -1; posy = -1;}
	Pieza(TIPO t, COLOR c, int x, int y):tipo(t),color(c),posx(x),posy(y){}
	Pieza(COLOR c, TIPO p, const char* im_b, const char* im_n) :
		color(c),
		tipo(p),
		imagen(c == BLANCA ? im_b : im_n) {}

	TIPO getPieza() { return tipo; }
	COLOR getColor() { return color; }
private:
	int posx;
	int posy;
	TIPO tipo = NF;
	COLOR color = NS;
	Sprite imagen;

};



