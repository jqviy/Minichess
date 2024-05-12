#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Reina.h"
#include "Caballo.h"
#include "Peon.h"
#include "ETSIDI.h"

#define NumFilas 6
#define NumColumnas 6

class Ajedrez; 
class Tablero
{
    int dimension;
    double x_ojo;
    double y_ojo;
    double z_ojo;

public:
    Pieza* celda[NumFilas][NumColumnas];
    Pieza* NumComidas[22];
    int size_NumComidas = 0;
    Tablero();
    
    Pieza* operator[](casilla pos) const { return celda[pos.fila][pos.columna]; }

    void cambiar_estado_tab(casilla inicio, casilla fin, Ajedrez& a);
    void mov_estado_tab(casilla inicio, casilla fin);

    void limpiar_Tablero();

    void dibuja(Ajedrez& ajedrez);
    
    void coronapeon(casilla inicio, casilla fin, Ajedrez& a);
};
