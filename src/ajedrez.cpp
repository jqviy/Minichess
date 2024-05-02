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
