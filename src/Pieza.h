#pragma once
#include <string>
#include <iostream>


class Pieza
{	
public:
	//color de la pieza
	enum COLOR { NS = -1, BLANCA, NEGRA };
	//tipo de la pieza
	enum TIPO { NF = -1, PEON, CABALLO, REINA, REY, TORRE };

	Pieza(){tipo = NF; color = NS; posx = -1; posy = -1;}
	Pieza(TIPO t, COLOR c, int x, int y):tipo(t),color(c),posx(x),posy(y){}
	
	TIPO getPieza() { return tipo; }
	COLOR getColor() { return color; }
private:
	int posx;
	int posy;
	TIPO tipo = NF;
	COLOR color = NS;

};



