#include "ajedrez.h"

void Ajedrez::dibuja()
{
	gluLookAt(4, 4, 15,			    // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			   // definimos hacia arriba (eje Y)

	casilla coord;
	for (coord.fila = 0; coord.fila < NumFilas; coord.fila++)
	{
		for (coord.columna = 0; coord.columna < NumColumnas; coord.columna++)
		{
			if (tablero[coord] != nullptr)
			{
				glTranslatef(coord.columna + 0.5, coord.fila + 0.5, 0);
				tablero[coord]->dibuja();
				glTranslatef(-coord.columna - 0.5, -coord.fila - 0.5, 0);
			}
		}
	}

	tablero.dibuja();  

}
void Ajedrez::detectaClick(int button, int state, int x, int y)
{
    int altura = glutGet(GLUT_WINDOW_HEIGHT);

    // Verificamos si se ha hecho clic con el botón izquierdo del ratón
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    { 

        // Convertimos las coordenadas de la ventana a las coordenadas del mundo
        double winX = (double)x; // Coordenada x de la ventana
        double winY = (double)(altura - y); // Coordenada y de la ventana (invertida debido a la coordenada y de la ventana)

        // Definimos variables para almacenar las coordenadas en el mundo tridimensional
        GLint viewport[4]; // Parámetros del viewport (x, y, ancho, alto)
        GLdouble modelview[16], projection[16]; // Matrices de modelo y proyección
        GLfloat winZ; // Coordenada z del punto seleccionado en el z-buffer
        GLdouble posX, posY, posZ; // Coordenadas en el espacio tridimensional

        // Obtenemos los parámetros actuales del viewport, modelo de vista y proyección
        glGetIntegerv(GL_VIEWPORT, viewport); // Obtenemos los parámetros del viewport
        glGetDoublev(GL_MODELVIEW_MATRIX, modelview); // Obtenemos la matriz de modelo de vista
        glGetDoublev(GL_PROJECTION_MATRIX, projection); // Obtenemos la matriz de proyección

        // Obtenemos la profundidad (z-buffer) del punto de la ventana
        glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ); // Leemos el z-buffer

        // Convertimos las coordenadas de la ventana a las coordenadas del mundo
        gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ); // Convertimos las coordenadas de la ventana a las del mundo

        // Convertimos las coordenadas del mundo a las coordenadas del tablero
        int row = (int)(posY + 1); // Fila del tablero (ajustada según la coordenada y)
        int col = (int)(posX + 1); // Columna del tablero (ajustada según la coordenada x)

        // Imprimimos las coordenadas y la casilla correspondiente por pantalla
        std::cout << "Coordenadas del raton: (" << x << ", " << y << ")" << std::endl; // Imprimimos las coordenadas del ratón
        std::cout << "Casilla: (" << row << ", " << col << ")" << std::endl; // Imprimimos las coordenadas de la casilla del tablero
    }
}
