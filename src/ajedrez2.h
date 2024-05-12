#pragma once
#include "tablero2.h"
#include "freeglut.h"
#include "ETSIDI.h"

#define MAX_MOVES 20

using ETSIDI::Sprite;

class Ajedrez2
{

public:
    
    Tablero2 tablero;

    int puntuacionBlancas = 0;
    int puntuacionNegras = 0;
    bool turno, jaque, jaque_mate, click;

    casilla* movimientos_legales[MAX_MOVES];
    int num_movimientos_legales;
    casilla raton, raton_sel;
    Sprite jaquemateB{ "imagenes/jaquemateB.png" }, jaquemateN{ "imagenes/jaquemateN.png" }, Jaque{ "imagenes/jaque.png" };
    Sprite fondo2{ "imagenes/fondo2.png" };

public:
    Ajedrez2() : turno(0), jaque(0), jaque_mate(0), click(0), num_movimientos_legales(0)
    {
        for (int i = 0; i < MAX_MOVES; i++)
            movimientos_legales[i] = nullptr;
    }
    casilla Click_inicio();
    void Click_fin(casilla o);
    ;

    //void detectaClick(int button, bool state, int x, int y);
    void detectaClick(int x, int y, int button, bool down);
    void cambio_turno() { turno = !turno; }

    bool compruebaJaque(Tablero2& tablero, Pieza::COLOR color);
    bool compruebaJaqueMate(Pieza::COLOR color);

    void calcularMovimientos_legales(casilla o, Pieza::COLOR color);
    void vaciarMovimientos_legales();

    casilla* operator[](int pos) const { return movimientos_legales[pos]; }
    int getLegalMoves() { return num_movimientos_legales; }
    void dibuja();

};

