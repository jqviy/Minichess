#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "freeglut.h"
#include "ETSIDI.h"
#include "ranking.h"


//********************************************************************************
//Clase destinada a la creacion de la pantalla inicial previa al tablero de Ajedrez
//********************************************************************************

using ETSIDI::Sprite;
using ETSIDI::playMusica;
using ETSIDI::stopMusica;

class Inicio
{

	Ranking ranke;
	char tecla;
	int op, gana;
	int puntuacionJugador1, puntuacionJugador2;
	int nueva_puntuacion, antigua_puntuacion;

public:
	Sprite portada{ "imagenes/Inicio_Juego.png" };
	Sprite final{ "imagenes/pantalla_final.png" };
	virtual void dibuja_portada();
	virtual void dibuja_final();
	int calcularNuevaPuntuacionElo(int puntuacionActual, int puntuacionOponente, int resultado);
	void gestorFicheros();
};
