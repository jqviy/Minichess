#pragma once
#include "tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

#define MAX_MOVES 20

using ETSIDI::Sprite;

//CLASE PARA GESTI�N DE LAS REGLAS Y COMPROBACIONES DEL AJEDREZ 6X6
class Ajedrez
{
	
public:

	Tablero tablero;

	int puntuacionBlancas=0;
	int puntuacionNegras=0;
	bool turno, jaque, jaque_mate, click;

	casilla* movimientos_legales[MAX_MOVES];
	int num_movimientos_legales;
	casilla raton, raton_sel;
	Sprite jaquemateB{ "imagenes/jaquemateB.png" }, jaquemateN{ "imagenes/jaquemateN.png" }, Jaque{ "imagenes/jaque.png" }, Instru{"imagenes/instru.png"};
	Sprite fondo1{ "imagenes/fondo1.png" };

public:
	Ajedrez() : turno(0), jaque(0), jaque_mate(0), click(0), num_movimientos_legales(0)
	{
		for (int i = 0; i < MAX_MOVES; i++)
			movimientos_legales[i] = nullptr;
	}
	casilla Click_inicio();
	void Click_fin(casilla o);
	;
	
	void detectaClick(int x, int y, int button, bool down);
	void cambio_turno() { turno = !turno; }

	bool compruebaJaque(Tablero& tablero, Pieza::COLOR color);
	bool compruebaJaqueMate(Pieza::COLOR color);

	void calcularMovimientos_legales(casilla o, Pieza::COLOR color);
	void vaciarMovimientos_legales();

	casilla* operator[](int pos) const { return movimientos_legales[pos]; }
	int getMovimientos_legales() { return num_movimientos_legales; }
	void dibuja();

};


