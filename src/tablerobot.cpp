#include "tablerobot.h"
#include "ajedrezbot.h"

Tablerobot::Tablerobot() : dimension(6), x_ojo(0), y_ojo(0), z_ojo(20)
{
    for (int fila = 0; fila < dimension; fila++)
    {
        for (int columna = 0; columna < dimension; columna++)
        {
            celda[fila][columna] = nullptr;
        }
    }

    celda[0][3] = new Rey(Pieza::BLANCA);
    celda[5][3] = new Rey(Pieza::NEGRA);
    celda[0][0] = new Torre(Pieza::BLANCA);
    celda[0][5] = new Torre(Pieza::BLANCA);
    celda[5][0] = new Torre(Pieza::NEGRA);
    celda[5][5] = new Torre(Pieza::NEGRA);
    celda[0][2] = new Reina(Pieza::BLANCA);
    celda[5][2] = new Reina(Pieza::NEGRA);
    celda[0][1] = new Caballo(Pieza::BLANCA);
    celda[0][4] = new Caballo(Pieza::BLANCA);
    celda[5][1] = new Caballo(Pieza::NEGRA);
    celda[5][4] = new Caballo(Pieza::NEGRA);
    for (int i = 0; i < 6; i++)
    {
        celda[1][i] = new Peon(Pieza::BLANCA);
        celda[4][i] = new Peon(Pieza::NEGRA);
    }
    for (int i = 0; i < 22; i++)
    {
        NumComidas[i] = nullptr;
    }

}

//Metodo encargado del movimiento de las piezas del tablero
void Tablerobot::cambiar_estado_tab(casilla inicio, casilla fin)
{
    //PIEZAS COMIDAS
    if (celda[fin.fila][fin.columna] != nullptr)
    {
        NumComidas[size_NumComidas++] = celda[fin.fila][fin.columna];
    }
    //CORONACIÓN PEÓN
    if ((fin.fila == 5 || fin.fila == 0) && celda[inicio.fila][inicio.columna]->getPieza() == Pieza::PEON)
        coronapeon(inicio, fin);

    //CAMBIAR ESTADO NORMAL 
    else
        mov_estado_tab(inicio, fin);
}

//Cambiar el estado del tablero 
void Tablerobot::mov_estado_tab(casilla inicio, casilla fin)
{
    celda[fin.fila][fin.columna] = celda[inicio.fila][inicio.columna];
    celda[inicio.fila][inicio.columna] = nullptr;
}

//Metodo que elimina todas las piezas del tablero (Utilizado al finalizar el juego)
void Tablerobot::limpiar_Tablero()
{
    for (int fila = 0; fila < NumFilas; fila++)
    {
        for (int columna = 0; columna < NumColumnas; columna++)
        {
            celda[fila][columna] = nullptr;
        }
    }
    for (int i = 0; i < size_NumComidas; i++)
    {
        NumComidas[i] = nullptr;
    }
    size_NumComidas = 0;
}

void Tablerobot::dibuja(Ajedrezbot& ajedrez)
{
    //Dibuja de un color verde las casillas a las que es posible mover la pieza seleccionada
    for (int i = 0; i < ajedrez.getLegalMoves(); i++)
    {
        glColor3ub(87, 204, 29);
        glBegin(GL_POLYGON);
        glVertex3d(ajedrez[i]->columna + 0.1, ajedrez[i]->fila + 0.1, 0.0);
        glVertex3d(ajedrez[i]->columna + 0.9, ajedrez[i]->fila + 0.1, 0.0);
        glVertex3d(ajedrez[i]->columna + 0.9, ajedrez[i]->fila + 0.9, 0.0);
        glVertex3d(ajedrez[i]->columna + 0.1, ajedrez[i]->fila + 0.9, 0.0);
        glEnd();
        glEnable(GL_LIGHTING);
    }
    //Dibuja el tablero por completo
    for (int fila = 0; fila < NumFilas; fila++)
    {
        for (int columna = 0; columna < NumColumnas; columna++)
        {
            glDisable(GL_LIGHTING);
            if ((fila + columna) % 2 == 0) glColor3ub(217, 230, 250);
            else glColor3ub(86, 107, 140);
            glBegin(GL_POLYGON);
            glVertex3d(columna, fila, 0.0);
            glVertex3d(columna + 1.0, fila, 0.0);
            glVertex3d(columna + 1.0, fila + 1.0, 0.0);
            glVertex3d(columna, fila + 1.0, 0.0);
            glEnd();
            glEnable(GL_LIGHTING);
        }
    }

    //Dibuja las piezas comidas
    int ColumnaB = -1, ColumnaN = 9, Columna = 0;
    int FilaB = NumFilas - 1, FilaN = NumFilas - 1, Fila = NumFilas - 1;
    int blancas = 0, negras = 0;
    for (int i = 0; i < 22; i++) {
        if (NumComidas[i] != nullptr) {
            if (NumComidas[i]->getColor() == Pieza::BLANCA) {
                if (blancas == NumFilas) {
                    FilaB = NumFilas - 1;
                    ColumnaB = -2;
                }
                Fila = FilaB--;
                Columna = ColumnaB;
                blancas++;
            }
            else {
                if (negras == NumFilas) {
                    FilaN = NumFilas - 1;
                    ColumnaN = 10;
                }
                Fila = FilaN--;
                Columna = ColumnaN;
                negras++;
            }
            glTranslatef(Columna, Fila, 0);
            NumComidas[i]->dibuja();
            glTranslatef(-Columna, -Fila, 0);
        }
    }

}

void Tablerobot::coronapeon(casilla inicio, casilla fin)
{
    int pieza;

    cout << "Por que pieza quiere cambiar su peon: " << endl;
    cout << "Torre(1)" << endl;
    cout << "Reina(2)" << endl;
    cout << "Caballo(3)" << endl;
    cin >> pieza;

    /* if (turno == Pieza::BLANCA) {
        puntuacionBlancas += 15;
    }
    else if (turno == Pieza::NEGRA) {
        puntuacionNegras += 15;
    }*/

    switch (pieza) {
    case 1:
        if (celda[inicio.fila][inicio.columna]->getColor() == Pieza::BLANCA)
        {
            celda[fin.fila][fin.columna] = new Torre(Pieza::BLANCA);
        }
        else  celda[fin.fila][fin.columna] = new Torre(Pieza::NEGRA);
        cout << "Torre nueva" << endl;
        break;
    case 2:
        if (celda[inicio.fila][inicio.columna]->getColor() == Pieza::BLANCA)
        {
            celda[fin.fila][fin.columna] = new Reina(Pieza::BLANCA);
        }
        else celda[fin.fila][fin.columna] = new Reina(Pieza::NEGRA);
        cout << "Reina nueva" << endl;
        break;
    case 3:
        if (celda[inicio.fila][inicio.columna]->getColor() == Pieza::BLANCA)
        {
            celda[fin.fila][fin.columna] = new Caballo(Pieza::BLANCA);
        }
        else celda[fin.fila][fin.columna] = new Caballo(Pieza::NEGRA);
        cout << "Caballo nuevo" << endl;
        break;
    }
    celda[inicio.fila][inicio.columna] = nullptr;
}