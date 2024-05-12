#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "freeglut.h"
#include "ETSIDI.h"

//********************************************************************************
//Clase destinada a la creacion de la pantalla inicial previa al tablero de Ajedrez
//********************************************************************************

using ETSIDI::Sprite;
using ETSIDI::playMusica;
using ETSIDI::stopMusica;

class Inicio
{
public:
	Sprite portada{ "imagenes/Inicio_Juego.png" };
	Sprite final{ "imagenes/pantalla_final.png" };
	virtual void dibuja_portada();
	virtual void dibuja_final();
};
