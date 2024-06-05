#pragma once
#include <string>
#include <iostream>
#include "ETSIDI.h"
#include <freeglut.h>
#include "casilla.h"

using namespace ETSIDI;

class Tablero;
class Tablero2;

//CLASE ENCARGADA DE LOS ATRIBUTOS Y MÉTODOS COMUNES A TODAS LAS PIEZAS
class Pieza
{	

public:
	//color de la pieza
	enum COLOR { NS = -1, BLANCA, NEGRA };
	//tipo de la pieza
	enum TIPO { NF = -1, PEON, CABALLO, REINA, REY, TORRE };
	
	Pieza(COLOR c, TIPO p, const char* im_b, const char* im_n) :
		color(c),
		tipo(p),
		imagen(c == BLANCA ? im_b : im_n)
	{
		imagen.setCenter(0.4, 0.4);
		imagen.setSize(0.8, 0.8);
		imagen.draw();
	};

	TIPO getPieza() { return tipo; }
	COLOR getColor() { return color; }
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero& celda);
	virtual bool movimiento_valido(casilla inicio, casilla fin, Tablero2& celda);

	virtual void dibuja() { imagen.draw(); }

protected:
	TIPO tipo = NF;
	COLOR color = NS;
	Sprite imagen;

};



