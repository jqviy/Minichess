#include "tablero.h"
#include "ajedrez.h"

Tablero::Tablero() : dimension(6), x_ojo(0), y_ojo(0), z_ojo(20)
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
void Tablero::cambiar_estado_tab(casilla inicio, casilla fin)
{
    //PIEZAS COMIDAS
    if (celda[fin.fila][fin.columna] != nullptr)
    {
        NumComidas[size_NumComidas++] = celda[fin.fila][fin.columna];
    }

    //CAMBIAR ESTADO NORMAL 
    
        mov_estado_tab(inicio, fin);
}

//Cambiar el estado del tablero 
void Tablero::mov_estado_tab(casilla inicio, casilla fin)
{
    celda[fin.fila][fin.columna] = celda[inicio.fila][inicio.columna];
    celda[inicio.fila][inicio.columna] = nullptr;
}

//Metodo que elimina todas las piezas del tablero (Utilizado al finalizar el juego)
void Tablero::limpiar_Tablero()
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

/*void Tablero::dibuja()

{
    if (dimension == 6) {
        double centro_x = -5.0 + (dimension - 1) / 2.0 * 2.0;
        double centro_y = -5.0 + (dimension - 1) / 2.0 * 2.0;
        double centro_z = 0.0;

        gluLookAt(x_ojo, y_ojo, z_ojo,  // posición del observador
            centro_x, centro_y, centro_z,// hacia qué punto mira (el centro del tablero)
            0.0, 1.0, 0.0);       // definimos hacia arriba (eje Y)

    }
    else {
        double centro_x = -3.0 + (dimension - 1) / 2.0 * 2.0;
        double centro_y = -3.0 + (dimension - 1) / 2.0 * 2.0;
        double centro_z = 0.0;

        gluLookAt(x_ojo, y_ojo, z_ojo,  // posición del observador
            centro_x, centro_y, centro_z,// hacia qué punto mira (el centro del tablero)
            0.0, 1.0, 0.0);       // definimos hacia arriba (eje Y)

    }


    glDisable(GL_LIGHTING);  // Desactivamos la iluminación para dibujar las casillas
    glColor3ub(255, 255, 255);  // Establecemos el color blanco para las casillas

    // Dibujar el tablero de ajedrez
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if ((i + j) % 2 == 0) {
                // Las casillas pares serán blancas
                glColor3ub(217, 230, 250);
            }
            else {
                // Las casillas impares serán de un color diferente
                glColor3ub(86, 107, 140);
            }
            // Calcular las coordenadas de la esquina superior izquierda de la casilla
            double x1 = -5.0 + j * 2.0;
            double y1 = -5.0 + i * 2.0;
            // Calcular las coordenadas de la esquina inferior derecha de la casilla
            double x2 = x1 + 2.0;
            double y2 = y1 + 2.0;

            // Dibujar la casilla como un cuadrado
            glBegin(GL_POLYGON);
            glVertex2d(x1, y1);
            glVertex2d(x1, y2);
            glVertex2d(x2, y2);
            glVertex2d(x2, y1);
            glEnd();
        }
    }

    glEnable(GL_LIGHTING);  // Volver a activar la iluminación
}

void Tablero::inicializa()
{
    x_ojo = 0;
    y_ojo = 0;
    z_ojo = 20;
}

void Tablero::setDimension(int dim)
{
    dimension = dim;
}*/

void Tablero::dibuja(Ajedrez& ajedrez)
{
    //Dibuja de un color amarillo las casillas a las que es posible mover la pieza seleccionada
    for (int i = 0; i < ajedrez.getLegalMoves(); i++)
    {
        glColor3ub(255, 255, 0);
        glBegin(GL_POLYGON);
        glVertex3d(ajedrez[i]->columna, ajedrez[i]->fila, 0.0);
        glVertex3d(ajedrez[i]->columna + 1.0, ajedrez[i]->fila, 0.0);
        glVertex3d(ajedrez[i]->columna + 1.0, ajedrez[i]->fila + 1.0, 0.0);
        glVertex3d(ajedrez[i]->columna, ajedrez[i]->fila + 1.0, 0.0);
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

void Tablero::coronapeon(casilla inicio, casilla fin)
{
    int pieza;

    cout << "Por que pieza quiere cambiar su peon: " << endl;
    cout << "Torre(1)" << endl;
    cout << "Reina(2)" << endl;
    cout << "Caballo(3)" << endl;
    cin >> pieza;

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