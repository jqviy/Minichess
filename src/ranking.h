#pragma once
#define JUGADORESMAX 500
#define NOMBREMAX 25
#include "Jugador.h"

//CLASE ENCARGADA DE LA GESTIÓN DE JUGADORES Y PUNTUACIONES DEL ARCHIVO DEL RANKING
class Ranking
{
public:

	int numJugadores = 0;
	Jugador jugadores[JUGADORESMAX];


	int leerNumero();
	void creaJugador(Jugador nuevoJugador);
	int buscaJugador(const string& nombre);
	void muestraPuntuacion();
	int extraePuntuacion(const string& nombre);
	void borrarJugador(const string& nombre);
};
