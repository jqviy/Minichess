#include "Inicio.h"

//Dibujo y musica de la pantalla de Inicio 
void Inicio::dibuja_portada()
{
	gluLookAt(4, 4, 15,				// posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			   // definimos hacia arriba (eje Y)

	playMusica("sonidos/musica_inicio.mp3",true); 
	portada.setCenter(3.6, 1.45);
	portada.setSize(14.9, 11.175);
	portada.draw();

}

//Dibujo y musica de la pantalla final
void Inicio::dibuja_final()
{
	gluLookAt(4, 4, 15,				// posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			   // definimos hacia arriba (eje Y)

	playMusica("sonidos/fin_partida.mp3", true);
	final.setCenter(3.6, 1.45);
	final.setSize(14.9, 11.175);
	final.draw();
}

//CÁLCULO DE PUNTACIONES ELO
int Inicio::calcularNuevaPuntuacionElo(int puntuacionActual, int puntuacionOponente, int resultado)
{
	const int K = 32;  // Constante K

	// Calcular la expectativa de victoria
	double expectativa = 1.0 / (1.0 + pow(10, (puntuacionOponente - puntuacionActual) / 400.0));

	// Calcular la nueva puntuación basada en el resultado
	int nuevaPuntuacion = puntuacionActual + K * (resultado - expectativa);

	return nuevaPuntuacion;
}

//FUNCIÓN ENCARGADA DE LA GESTIÓN DEL RANKING
void Inicio::gestorFicheros()
{
    do
    {
        system("cls");
        cout << "\t\t=====BIENVENIDO AL RANKING=====\n*SELECCIONE UNA OPCION*\n\n";
        cout << "1.JUGADORES\n";
        cout << "2.VER PUNTUACIONES\n";
        cout << "3.SALIR\n\n";
        op = ranke.leerNumero();
        string nombre, nombre1;
        string nombre_, nombre1_;
        int existe, existe2;

        switch (op)
        {
        case 1:
            system("cls");
            do
            {
                cout << "Introduzca el nombre del jugador 1: ";
                getline(cin, nombre);
                if (nombre.empty())
                {
                    cout << "Introduzca un nombre valido\n";
                    system("pause");
                    system("cls");
                }
            } while (nombre.empty());

            existe = ranke.buscaJugador(nombre);

            system("cls");
            do
            {
                cout << "Introduzca el nombre del jugador 2: ";
                getline(cin, nombre_);
                if (nombre_.empty())
                {
                    cout << "Introduzca un nombre valido\n";
                    system("pause");
                    system("cls");
                }
            } while (nombre_.empty());

            existe2 = ranke.buscaJugador(nombre_);

            if (existe == -1 || existe2 == -1)
            {
                if (existe == -1 && existe2 == 1)
                {
                    Jugador nuevoJugador;
                    nuevoJugador.nombre = nombre;
                    nuevoJugador.puntuacion = 1000;
                    ranke.creaJugador(nuevoJugador);
                    cout << nombre << endl;
                }
                else if (existe2 == -1 && existe == 1)
                {
                    Jugador nuevoJugador;
                    nuevoJugador.nombre = nombre_;
                    nuevoJugador.puntuacion = 1000;
                    ranke.creaJugador(nuevoJugador);
                    cout << nombre_ << endl;
                }
                else if (existe2 == -1 && existe == -1)
                {
                    Jugador nuevoJugador, nuevoJugador2;
                    nuevoJugador.nombre = nombre;
                    nuevoJugador2.nombre = nombre_;

                    nuevoJugador.puntuacion = 1000;
                    nuevoJugador2.puntuacion = 1000;
                    ranke.creaJugador(nuevoJugador);
                    ranke.creaJugador(nuevoJugador2);
                    cout << nombre << endl;
                    cout << nombre_ << endl;
                }


            }
            // Aquí es donde se juega la partida, asignar quién ha ganado
            cout << "Quien ha ganado la partida? (1: " << nombre << ", 2: " << nombre_ << "): ";
            cin >> gana;

            // Obtener las puntuaciones actuales de los jugadores
            puntuacionJugador1 = ranke.extraePuntuacion(nombre);
            puntuacionJugador2 = ranke.extraePuntuacion(nombre_);

            // Calcular nuevas puntuaciones ELO
            if (gana == 1) {
                nueva_puntuacion = calcularNuevaPuntuacionElo(puntuacionJugador1, puntuacionJugador2, 1);
                antigua_puntuacion = puntuacionJugador1;
            }
            else {
                nueva_puntuacion = calcularNuevaPuntuacionElo(puntuacionJugador1, puntuacionJugador2, 0);
                antigua_puntuacion = puntuacionJugador1;
            }

            // Aquí se cambia la del jugador 1
            if (1)
            {
                ranke.borrarJugador(nombre);
                nombre1 = nombre;
                Jugador nuevoJugador;
                nuevoJugador.nombre = nombre1;
                nuevoJugador.puntuacion = nueva_puntuacion;
                ranke.creaJugador(nuevoJugador);
                cout << nombre1 << endl;
                cout << "Pulsa cualquier tecla para volver al menu\n";
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Pulsa cualquier tecla para volver al menu\n";
                cin.ignore();
                cin.get();
            }

            if (gana == 2) {
                nueva_puntuacion = calcularNuevaPuntuacionElo(puntuacionJugador2, puntuacionJugador1, 1);
                antigua_puntuacion = puntuacionJugador2;
            }
            else {
                cout << "a";
                nueva_puntuacion = calcularNuevaPuntuacionElo(puntuacionJugador2, puntuacionJugador1, 0);
                antigua_puntuacion = puntuacionJugador2;
            }

            // Aquí se cambia la del jugador 2
            if (1)
            {
                ranke.borrarJugador(nombre_);
                nombre1 = nombre_;
                Jugador nuevoJugador;
                nuevoJugador.nombre = nombre1;
                nuevoJugador.puntuacion = nueva_puntuacion;
                ranke.creaJugador(nuevoJugador);
                cout << nombre1 << endl;
                cout << "Pulsa cualquier tecla para volver al menu\n";
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Pulsa cualquier tecla para volver al menu\n";
                cin.ignore();
                cin.get();
            }

            cout << "Pulsa cualquier tecla para volver al menu\n";
            cin.ignore();
            cin.get();
            break;
        case 2:
            system("cls");
            ranke.muestraPuntuacion();
            cout << "Pulsa cualquier tecla para volver al menu\n";
            cin.ignore();
            cin.get();
            break;
        case 3: 
            exit(0);
            break;
        default:
            if (op != 3)
            {
                cout << "Opcion incorrecta\n";
                cout << "Pulsa cualquier tecla para volver al menu\n";
                cin.ignore();
            }
            break;
        }
    } while (op != 3);
}
