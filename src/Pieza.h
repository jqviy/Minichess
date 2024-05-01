#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pieza
{
public:
	//color de la pieza
	enum COLOR { NS = -1, BLANCA, NEGRA };
	//tipo de la pieza
	enum TIPO { NF = -1, PEON, CABALLO, REINA, REY, TORRE };

	Pieza();
	Pieza(TIPO t, COLOR c, int x, int y);
	
	TIPO getPieza() { return tipo; }
	COLOR getColor() { return color; }
protected:
	bool seleccionado;
	int posx;
	int posy;
	TIPO tipo = NF;
	COLOR color = NS;

	

};



