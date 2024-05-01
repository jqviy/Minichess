#include "tablero.h"
#include "freeglut.h"

Tablero::Tablero() : dimension(6), x_ojo(0), y_ojo(0), z_ojo(20) {}



void Tablero::dibuja()

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
}