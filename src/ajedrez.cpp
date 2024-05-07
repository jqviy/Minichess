#include "ajedrez.h"

//Método para comprobar que el primer click para seleccionar una pieza es válido.
casilla Ajedrez::Click_inicio()
{
	casilla primer = raton;

	if (tablero[primer] == nullptr)
		cout << "Casilla vacia" << endl;

	else if (tablero[primer]->getColor() != (Pieza::COLOR)turno)
		cout << "No es tu turno" << endl;

	//Al seleccionar una pieza clacula todos sus movimientos legales, en caso de no haber, se elimina la selección
	//y no se puede jugar esa pieza. Esta función devuelve las coordenadas seleccionadas
	else
	{
		calcularMovimientos_legales(primer, (Pieza::COLOR)turno);
		if (num_movimientos_legales == 0)
		{
			cout << "No se puede jugar esta pieza " << endl;
			vaciarMovimientos_legales();
			click = 0;
		}

		else
		{
			cout << "Se puede jugar esta pieza " << endl;
			click = 1;
		}
	}

	return primer;
}

void Ajedrez::Click_fin(casilla o)
{
	casilla seg = raton;
	bool encontrar = false;

	//Si las coordenadas del segundo click coinciden con coordenadas válidas para esa pieza, esta se puede mover.
	for (int i = 0; i < num_movimientos_legales; i++)
	{
		if (seg.fila == movimientos_legales[i]->fila && seg.columna == movimientos_legales[i]->columna)
			encontrar = true;
	}

	if (encontrar == true)
	{
		//Se añade sonido al movimiento de las piezas
		if (tablero[seg] != nullptr)
		{
			cout << "Pieza comida " << endl;
	
		}

		//Se imprime en consola el movimiento realizado y se le pasa la información del nuevo estado al tablero
		//o.print() << "->";
		//seg.print() << endl;
		tablero.cambiar_estado_tab(o, seg);

		//Comprobaciones y acciones que se realizan al cambiar el estado de tablero
		if (compruebaJaqueMate((Pieza::COLOR)!turno))
		{
			cout << "JAQUE MATE" << endl;
			jaque_mate = 1;
			//tablero.limpiar_Tablero();
		}
		else
		{
			jaque = compruebaJaque(tablero, (Pieza::COLOR)!turno);
			if (jaque == 1) cout << "JAQUE" << endl;
			vaciarMovimientos_legales();
			cambio_turno();
			click = 0;
		}
	}
	else
	{
		cout << "Movimiento no valido" << endl;
		vaciarMovimientos_legales();
		click = 0;
	}
}

bool Ajedrez::compruebaJaque(Tablero& tablero, Pieza::COLOR color)
{
	for (int f = 0; f < NumFilas; f++)
	{
		for (int c = 0; c < NumColumnas; c++)
		{
			casilla daux(f, c);
			if (tablero[daux] != nullptr && tablero[daux]->getPieza() == Pieza::REY && tablero[daux]->getColor() == color)
			{
				for (int f = 0; f < NumFilas; f++)
				{
					for (int c = 0; c < NumColumnas; c++)
					{
						casilla oaux(f, c);
						if (tablero[oaux] != nullptr && tablero[oaux]->getColor() == !color && tablero[oaux]->movimiento_valido(oaux, daux, tablero))
							return true;
					}
				}
			}
		}
	}
	return false;
}


bool Ajedrez::compruebaJaqueMate(Pieza::COLOR color)
{
	vaciarMovimientos_legales();
	for (int f = 0; f < NumFilas; f++)
	{
		for (int c = 0; c < NumColumnas; c++)
		{
			casilla oaux(f, c);
			if (tablero[oaux] != nullptr && tablero[oaux]->getColor() == color)
			{
				calcularMovimientos_legales(oaux, color);
				if (num_movimientos_legales != 0) return false;
			}
		}
	}
	return true;
}

void Ajedrez::calcularMovimientos_legales(casilla o, Pieza::COLOR color)
{
	Pieza* pieza = tablero[o];
	casilla auxiliar;
	for (auxiliar.fila = 0; auxiliar.fila < NumFilas; auxiliar.fila++)
	{
		for (auxiliar.columna = 0; auxiliar.columna < NumColumnas; auxiliar.columna++)
		{
			if (pieza->movimiento_valido(o, auxiliar, tablero) == true)
			{
				Tablero tablero_aux = tablero;
				tablero_aux.mov_estado_tab(o, auxiliar);
				if (compruebaJaque(tablero_aux, color) == false)
				{
					movimientos_legales[num_movimientos_legales++] = new casilla(auxiliar.fila, auxiliar.columna);
				}
			}
		}
	}
}


//Función para vaciar los movimientos legales calculados cada vez que una pieza es pulsada con el ratón.
void Ajedrez::vaciarMovimientos_legales()
{
	for (int i = 0; i < num_movimientos_legales; i++)
	{
		delete movimientos_legales[i];
		movimientos_legales[i] = nullptr;
	}
	num_movimientos_legales = 0;
}


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
	if(jaque_mate == 1 && turno == Pieza::NEGRA) {
		jaquemateN.setCenter(-2.75, -8.2);
		jaquemateN.setSize(2.64, 1.16);
		jaquemateN.draw();

	}

	else if (jaque_mate == 1 && turno == Pieza::BLANCA) {
		jaquemateB.setCenter(-2.75, -8.2);
		jaquemateB.setSize(2.64, 1.16);
		jaquemateB.draw();

		}

		if (jaque == 1) {
			Jaque.setCenter(-2.75, -8.2);
			Jaque.setSize(2.64, 1.16);
			Jaque.draw();
		}
	tablero.dibuja(*this);

}
/*void Ajedrez::detectaClick(int button, bool state, int x, int y)
{
	int altura = glutGet(GLUT_WINDOW_HEIGHT);
	// Verificamos si se ha hecho clic con el botón izquierdo del ratón
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
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
	if (state)
	{
		if (casilla::fueraTablero(raton) == true) cout << "Fuera del tablero" << endl;
		else if (click == 0) raton_sel = Click_inicio();
		else if (click == 1) Click_fin(raton_sel);
	}
}*/

void Ajedrez::detectaClick(int x, int y, int button, bool down)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	raton.fila = (int)(abs(posY));
	raton.columna = (int)(posX);

	/* Imprimimos las coordenadas y la casilla correspondiente por pantalla
	std::cout << "Coordenadas del raton: (" << x << ", " << y << ")" << std::endl; // Imprimimos las coordenadas del ratón
	std::cout << "Casilla: (" << raton.fila << ", " << raton.columna << ")" << std::endl; // Imprimimos las coordenadas de la casilla del tablero
	*/
	//Permite distinguir entre el primer y segundo click (Primer click seleccionar, segundo mover).
	if (down)
	{
		if (casilla::fueraTablero(raton) == true) cout << "Fuera del tablero" << endl;
		else if (click == 0) raton_sel = Click_inicio();
		else if (click == 1) Click_fin(raton_sel);
	}
}