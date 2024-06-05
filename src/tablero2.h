#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Reina.h"
#include "Peon.h"
#include "ETSIDI.h"

#define NumFilas2 4
#define NumColumnas2 4

class Ajedrez2;

//CLASE PARA CREACIÓN Y MODIFICACIONES DEL TABLERO 4X4
class Tablero2
{
    int dimension;
    double x_ojo;
    double y_ojo;
    double z_ojo;

public:
    Pieza* celda[NumFilas2][NumColumnas2];
    Pieza* NumComidas[16];
    int size_NumComidas = 0;
    Tablero2();

    Pieza* operator[](casilla pos) const { return celda[pos.fila][pos.columna]; }

    void cambiar_estado_tab(casilla inicio, casilla fin, Ajedrez2& a);
    void mov_estado_tab(casilla inicio, casilla fin);

    void limpiar_Tablero();

    void dibuja(Ajedrez2& ajedrez);
  
        void coronapeon(casilla inicio, casilla fin, Ajedrez2& a);
};
