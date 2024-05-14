#pragma once
#define JUGADORESMAX 500
#define NOMBREMAX 25
#include "Jugador.h"

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
