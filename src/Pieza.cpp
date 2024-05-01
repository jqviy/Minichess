#include "Pieza.h"
Pieza::Pieza()
{
	tipo = NF;
	color = NS;
	posx = -1;
	posy = -1;
}

Pieza::Pieza(TIPO t, COLOR c, int x, int y)
{
	tipo = t;
	color = c;
	posx = x;
	posy = y;
}



