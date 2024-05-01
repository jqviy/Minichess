#pragma once
class Tablero
{
    int dimension;
    double x_ojo;
    double y_ojo;
    double z_ojo;

public:
    Tablero(); // Constructor
    void dibuja();
    void inicializa();
    void setDimension(int dim);
};
