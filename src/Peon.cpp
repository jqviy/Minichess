#pragma once
#include "Peon.h"
#include "tablero.h"

bool Peon::movimiento_valido(casilla inicio, casilla fin, Tablero& celda) {

		if (color == BLANCA)
		{
			if (inicio.fila == 1)
			{
				if ((casilla::mPeonBlanco(inicio, fin) == true && celda[fin] == nullptr) || ((casilla::mPeonDiagonalBlanco(inicio, fin) == true) && celda[fin] != nullptr && celda[fin]->getColor() != color))
					return Pieza::movimiento_valido(inicio, fin, celda);

			}

			else if (inicio.fila != 1)
			{
				if ((casilla::mPeonBlanco(inicio, fin) == true) && celda[fin] == nullptr)
					return Pieza::movimiento_valido(inicio, fin, celda);

				else if ((casilla::mPeonDiagonalBlanco(inicio, fin) == true) && celda[fin] != nullptr)
					return Pieza::movimiento_valido(inicio, fin, celda);
			}
		}

		else if (color == NEGRA)
		{
			if (inicio.fila == 4)
			{
				if ((casilla::mPeonNegro(inicio, fin) == true && celda[fin] == nullptr) || ((casilla::mPeonDiagonalNegro(inicio, fin) == true) && celda[fin] != nullptr && celda[fin]->getColor() != color))
					return Pieza::movimiento_valido(inicio, fin, celda);
			}

			else if (inicio.fila != 4)
			{
				if ((casilla::mPeonNegro(inicio, fin) == true) && celda[fin] == nullptr)
					return Pieza::movimiento_valido(inicio, fin, celda);

				else if ((casilla::mPeonDiagonalNegro(inicio, fin) == true) && celda[fin] != nullptr)
					return Pieza::movimiento_valido(inicio, fin, celda);
			}
		}

		return false;
}