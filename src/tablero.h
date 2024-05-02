#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Reina.h"
#include "Caballo.h"
#include "Peon.h"
#include "ETSIDI.h"

#define NumFilas 6
#define NumColumnas 6


class Tablero
{
    int dimension;
    double x_ojo;
    double y_ojo;
    double z_ojo;

public:
    Pieza* celda[NumFilas][NumColumnas];
    Pieza* NumComidas[22];
    Tablero();
    

    Pieza* operator[](casilla pos) const { return celda[pos.fila][pos.columna]; }
    void dibuja();
    /*void inicializa();
    void setDimension(int dim);*/
};
