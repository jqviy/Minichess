#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Reina.h"
#include "Caballo.h"
#include "Peon.h"
#include "ETSIDI.h"

#define NumFilas 6
#define NumColumnas 6

class Ajedrezbot;
class Tablerobot
{
    int dimension;
    double x_ojo;
    double y_ojo;
    double z_ojo;

public:
    Pieza* celda[NumFilas][NumColumnas];
    Pieza* NumComidas[22];
    int size_NumComidas = 0;
    Tablerobot();

    Pieza* operator[](casilla pos) const { return celda[pos.fila][pos.columna]; }

    void cambiar_estado_tab(casilla inicio, casilla fin);
    void mov_estado_tab(casilla inicio, casilla fin);

    void limpiar_Tablero();

    void dibuja(Ajedrezbot& ajedrez);
    /*void inicializa();
    void setDimension(int dim);*/
    void coronapeon(casilla inicio, casilla fin);
};
