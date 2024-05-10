#include "ajedrez2.h"

//Método para comprobar que el primer click para seleccionar una pieza es válido.
casilla Ajedrez2::Click_inicio()
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
void Ajedrez2::Click_fin(casilla o)
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
            playMusica("sonidos/comer.mp3");
        }
        
        playMusica("sonidos/mover");

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
bool Ajedrez2::compruebaJaque(Tablero2& tablero, Pieza::COLOR color)
{
    for (int f = 0; f < NumFilas2; f++)
    {
        for (int c = 0; c < NumColumnas2; c++)
        {
            casilla daux(f, c);
            if (tablero[daux] != nullptr && tablero[daux]->getPieza() == Pieza::REY && tablero[daux]->getColor() == color)
            {
                for (int f = 0; f < NumFilas2; f++)
                {
                    for (int c = 0; c < NumColumnas2; c++)
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
bool Ajedrez2::compruebaJaqueMate(Pieza::COLOR color)
{
    vaciarMovimientos_legales();
    for (int f = 0; f < NumFilas2; f++)
    {
        for (int c = 0; c < NumColumnas2; c++)
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

void Ajedrez2::calcularMovimientos_legales(casilla o, Pieza::COLOR color)
{
    Pieza* pieza = tablero[o];
    casilla auxiliar;
    for (auxiliar.fila = 0; auxiliar.fila < NumFilas2; auxiliar.fila++)
    {
        for (auxiliar.columna = 0; auxiliar.columna < NumColumnas2; auxiliar.columna++)
        {
            if (pieza->movimiento_valido(o, auxiliar, tablero) == true)
            {
                Tablero2 tablero_aux = tablero;
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
void Ajedrez2::vaciarMovimientos_legales()
{
    for (int i = 0; i < num_movimientos_legales; i++)
    {
        delete movimientos_legales[i];
        movimientos_legales[i] = nullptr;
    }
    num_movimientos_legales = 0;
}


void Ajedrez2::dibuja()
{
    gluLookAt(2, 2, 10,                // posicion del ojo
        2.0, 2.0, 0.0,      // hacia que punto mira  (0,0,0) 
        0.0, 1.0, 0.0);               // definimos hacia arriba (eje Y)

    casilla coord;
    for (coord.fila = 0; coord.fila < NumFilas2; coord.fila++)
    {
        for (coord.columna = 0; coord.columna < NumColumnas2; coord.columna++)
        {
            if (tablero[coord] != nullptr)
            {
                glTranslatef(coord.columna + 0.5, coord.fila + 0.5, 0);
                tablero[coord]->dibuja();
                glTranslatef(-coord.columna - 0.5, -coord.fila - 0.5, 0);
            }
        }
    }

    if (jaque_mate == 1 && turno == Pieza::NEGRA) {
        jaquemateN.setCenter(-0.8, -4.2);
        jaquemateN.setSize(2.64, 1.16);
        jaquemateN.draw();
        playMusica("sonidos/fin_juego.mp3");

    }

    else if (jaque_mate == 1 && turno == Pieza::BLANCA) {
        jaquemateB.setCenter(-0.8, -4.2);
        jaquemateB.setSize(2.64, 1.16);
        jaquemateB.draw();
        playMusica("sonidos/fin_juego.mp3");

    }

    if (jaque == 1) {
        Jaque.setCenter(-0.8, -4.2);
        Jaque.setSize(2.64, 1.16);
        Jaque.draw();
    }
    tablero.dibuja(*this);

    //Dibuja fonde de pantalla

    fondo2.setCenter(3.6, 1.45);
    fondo2.setSize(14.9, 11.175);
    fondo2.draw();


}
void Ajedrez2::detectaClick(int x, int y, int button, bool down)
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