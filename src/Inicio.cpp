#include "Inicio.h"

//Dibujo y musica de la pantalla de Inicio 
void Inicio::dibuja()
{
	gluLookAt(4, 4, 15,				// posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			   // definimos hacia arriba (eje Y)

	playMusica("musica_inicio.mp3");
	portada.setCenter(3.6, 1.45);
	portada.setSize(14.9, 11.175);
	portada.draw();
}